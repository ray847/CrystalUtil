#include <iostream>

#include "CrystalUtil/util.h" // crystal::util::Logger

int main() {
  std::cout << "Hello from " << crystal::util::kNAME << std::endl;
  using crystal::util::Logger;
  constexpr std::string_view format = "{}. This is a {} log.";
  {
    Logger logger{};
    Logger copy{logger};
    Logger assign{nullptr};
    assign = logger;
    logger.Trace(format, 0, "trace");
    logger.Debug(format, 1, "debugging");
    logger.Info(format, 2, "information");
    logger.Warn(format, 3, "warning");
    copy.Error(format, 4, "error");
    assign.Critical(format, 5, "critical");
  }
  {
    Logger logger{nullptr};
    Logger copy{logger};
    Logger assign{nullptr};
    assign = logger;
    logger.Trace(format, 0, "trace");
    logger.Debug(format, 1, "debugging");
    logger.Info(format, 2, "information");
    logger.Warn(format, 3, "warning");
    copy.Error(format, 4, "error");
    assign.Critical(format, 5, "critical");
  }
  return 0;
}
