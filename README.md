# CrystalUtil

Utility module for the crystal project.

## QuickStart

```c++
#include <iostream>

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
  return 0;
}
```

## Functionality

* Logging