#include "CrystalUtil/log.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include <format>
#include <memory>

namespace crystal::util {
struct Logger::Impl {
  std::shared_ptr<spdlog::logger> logger;
};

Logger::Logger(std::filesystem::path file):
  pimpl_(
    std::make_unique<Impl>(
      spdlog::basic_logger_mt("basic_logger", file.string())
    )
  ) {}
Logger::~Logger() = default;
void Logger::InfoImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  pimpl_->logger->info(msg);
}
void Logger::DebugImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  pimpl_->logger->debug(msg);
}
void Logger::WarnImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  pimpl_->logger->warn(msg);
}
void Logger::ErrorImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  pimpl_->logger->error(msg);
}
void Logger::CriticalImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  pimpl_->logger->critical(msg);
}
} // namespace crystal::util
