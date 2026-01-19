#include "CrystalUtil/log/logger.h"

#include <cstddef>
#include <filesystem>
#include <format> // std:format_args, std::vformat
#include <memory> // std::shared_ptr

#include <spdlog/sinks/basic_file_sink.h> // spdlog::sinks::basic_file_sink_mt
#include <spdlog/spdlog.h>                // spdlog::logger


namespace crystal::util {
struct Logger::Impl {
  std::shared_ptr<spdlog::logger> logger = nullptr;
  std::shared_ptr<spdlog::logger> error_logger = nullptr;
};

Logger::Logger(std::filesystem::path dir) : pimpl_(std::make_unique<Impl>()) {
  /* Check dir validity. */
  if (!std::filesystem::exists(dir)) {
    std::filesystem::create_directory(dir);
  }
  if (!std::filesystem::is_directory(dir)) {
    throw std::format("{} is not a directory", dir.string());
  }
  /* Initialize the normal logger & error logger. */
  pimpl_->logger = spdlog::basic_logger_mt("normal_logger",
                                           (dir / "logs.log").string(), true);
  pimpl_->logger->set_level(spdlog::level::trace);
  pimpl_->error_logger = spdlog::basic_logger_mt(
      "error_logger", (dir / "error_logs.log").string(), true);
  pimpl_->error_logger->set_level(spdlog::level::warn);
}
Logger::Logger(nullptr_t) {}
Logger::~Logger() = default;
void Logger::TraceImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  if (pimpl_) [[likely]]
    pimpl_->logger->trace(msg);
}
void Logger::DebugImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  if (pimpl_) [[likely]]
    pimpl_->logger->debug(msg);
}
void Logger::InfoImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  if (pimpl_) [[likely]]
    pimpl_->logger->info(msg);
}
void Logger::WarnImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  if (pimpl_) [[likely]] {
    pimpl_->logger->warn(msg); [[likely]]
    pimpl_->error_logger->warn(msg);
  }
}
void Logger::ErrorImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  if (pimpl_) [[likely]] {
    pimpl_->logger->error(msg);
    pimpl_->error_logger->error(msg);
  }
}
void Logger::CriticalImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  if (pimpl_) [[likely]] {
    pimpl_->logger->critical(msg);
    pimpl_->error_logger->critical(msg);
  }
}
} // namespace crystal::util
