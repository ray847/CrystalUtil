#ifndef CRYSTAL_UTIL_LOG_H_
#define CRYSTAL_UTIL_LOG_H_

#include <string_view> // std::string_view
#include <ostream> // std::ostream
#include <memory> // std::unique_ptr
#include <format> // std::format

namespace crystal {
namespace util {
class Logger {
public:
  /* Constructor & Destructor */
  explicit Logger(std::ostream& os);
  ~Logger();
  /* Functions */
  template<typename... Args>
  void Info(std::format_string<Args...> fmt, Args&&... args) {
    InfoImpl(fmt.get(), std::make_format_args(args...));
  }
  template<typename... Args>
  void Debug(std::format_string<Args...> fmt, Args&&... args) {
    DebugImpl(fmt.get(), std::make_format_args(args...));
  }
  template<typename... Args>
  void Warn(std::format_string<Args...> fmt, Args&&... args) {
    WarnImpl(fmt.get(), std::make_format_args(args...));
  }
  template<typename... Args>
  void Error(std::format_string<Args...> fmt, Args&&... args) {
    ErrorImpl(fmt.get(), std::make_format_args(args...));
  }
  template<typename... Args>
  void Critical(std::format_string<Args...> fmt, Args&&... args) {
    CriticalImpl(fmt.get(), std::make_format_args(args...));
  }
private:
  /* Forward Declaration */
  struct Impl;
  /* Variables */
  std::unique_ptr<Impl> pimpl_;
  /* Functions */
  void InfoImpl(std::string_view fmt, std::format_args args);
  void DebugImpl(std::string_view fmt, std::format_args args);
  void WarnImpl(std::string_view fmt, std::format_args args);
  void ErrorImpl(std::string_view fmt, std::format_args args);
  void CriticalImpl(std::string_view fmt, std::format_args args);
};
} // namespace util
} // namespace crystal

#endif
