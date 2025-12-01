#include "CrystalUtil/log.h"

#include <spdlog/spdlog.h> // spdlog::logger
#include <spdlog/sinks/ostream_sink.h> // spdlog::sinks::ostream_sink_mt
#include <spdlog/sinks/basic_file_sink.h> // spdlog::sinks::basic_file_sink_mt
#include <format> // std:format_args, std::vformat
#include <memory> // std::shared_ptr
#include <fstream> // std::ofstream

namespace crystal::util {
spdlog::level::level_enum ToSpdlogLevel(Logger::Level level) {
  switch (level) {
    case Logger::Level::TRACE:
      return spdlog::level::trace;
    case Logger::Level::DEBUG:
      return spdlog::level::debug;
    case Logger::Level::INFO:
      return spdlog::level::info;
    case Logger::Level::WARN:
      return spdlog::level::warn;
    case Logger::Level::ERROR:
      return spdlog::level::err;
    case Logger::Level::CRITICAL:
      return spdlog::level::critical;
    default:
      return spdlog::level::info;
  }
}

struct Logger::Impl {
  std::shared_ptr<spdlog::sinks::sink> sink = nullptr;
  std::shared_ptr<spdlog::logger> logger = nullptr;
};

Logger::Logger(std::ostream& os) : pimpl_(std::make_unique<Impl>()) {
  pimpl_->sink = std::make_shared<spdlog::sinks::ostream_sink_mt>(os);
  pimpl_->logger = std::make_shared<spdlog::logger>("os_mt_logger",
                                                    pimpl_->sink);
}
Logger::Logger(std::filesystem::path path) : pimpl_(std::make_unique<Impl>()) {
  pimpl_->sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
    path,
    true //< overwrite set to true
  );
  pimpl_->logger = std::make_shared<spdlog::logger>("file_mt_logger",
                                                    pimpl_->sink);
}
Logger::~Logger() = default;
void Logger::SetLevel(Level level) {
  pimpl_->logger->set_level(ToSpdlogLevel(level));
}
void Logger::TraceImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  pimpl_->logger->trace(msg);
}
void Logger::DebugImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  pimpl_->logger->debug(msg);
}
void Logger::InfoImpl(std::string_view fmt, std::format_args args) {
  std::string msg = std::vformat(fmt, args);
  pimpl_->logger->info(msg);
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
