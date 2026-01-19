#include <iostream>
#include <string>

#include "CrystalUtil/util.h" // crystal::util::Logger

int main() {
  std::cout << "Hello from " << crystal::util::kNAME << std::endl;
  using crystal::util::Logger;
  Logger logger{};
  constexpr std::string_view format = "{}. This is a {} log.";
  logger.Trace(format, 0, "trace");
  logger.Debug(format, 1, "debugging");
  logger.Info(format, 2, "information");
  logger.Warn(format, 3, "warning");
  logger.Error(format, 4, "error");
  logger.Critical(format, 5, "critical");

  Logger null_logger{nullptr};
  null_logger.Trace(format, 0, "trace");
  null_logger.Debug(format, 1, "debugging");
  null_logger.Info(format, 2, "information");
  null_logger.Warn(format, 3, "warning");
  null_logger.Error(format, 4, "error");
  null_logger.Critical(format, 5, "critical");
  return 0;
}
