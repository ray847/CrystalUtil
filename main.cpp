#include <iostream>
#include <string>

#include "CrystalUtil/util.h" // crystal::util::Logger

int main() {
  std::cout << "Hello from " << crystal::util::kNAME << std::endl;
  using crystal::util::Logger;
  {
    Logger logger(std::clog);
    logger.SetLevel(Logger::Level::TRACE);
    constexpr std::string_view format = "{}. This is a {} log.";
    logger.Trace(format, 0, "trace");
    logger.Debug(format, 1, "debugging");
    logger.Info(format, 2, "information");
    logger.Warn(format, 3, "warning");
    logger.Error(format, 4, "error");
    logger.Critical(format, 5, "critical");
  } {
    Logger logger("from_main.log");
    logger.SetLevel(Logger::Level::TRACE);
    constexpr std::string_view format = "{}. This is a {} log.";
    logger.Trace(format, 0, "trace");
    logger.Debug(format, 1, "debugging");
    logger.Info(format, 2, "information");
    logger.Warn(format, 3, "warning");
    logger.Error(format, 4, "error");
    logger.Critical(format, 5, "critical");
  }
  return 0;
}
