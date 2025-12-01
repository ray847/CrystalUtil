#include <iostream>
#include <string>

#include "CrystalUtil/util.h" // crystal::util::Logger

int main() {
  std::cout << "Hello from " << crystal::util::kNAME << std::endl;
  using crystal::util::Logger;
  {
    Logger logger(std::clog);
    logger.SetLevel(Logger::Level::DEBUG);
    constexpr std::string_view format = "{}. This is a {} log.";
    logger.Info(format, 1, "information");
    logger.Debug(format, 2, "debugging");
    logger.Warn(format, 3, "warning");
    logger.Error(format, 4, "error");
    logger.Critical(format, 5, "critical");
  } {
    Logger logger("from_main.log");
    logger.SetLevel(Logger::Level::DEBUG);
    constexpr std::string_view format = "{}. This is a {} log.";
    logger.Info(format, 1, "information");
    logger.Debug(format, 2, "debugging");
    logger.Warn(format, 3, "warning");
    logger.Error(format, 4, "error");
    logger.Critical(format, 5, "critical");
  }
  return 0;
}
