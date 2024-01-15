// test_abseil.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <fstream>
#include <iostream>
#include "absl/log/log.h"

#include <absl/base/log_severity.h>
#include <cstdio>
#include "absl/base/attributes.h"
#include "absl/base/log_severity.h"
#include "absl/flags/declare.h"
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/flags/usage.h"
#include "absl/log/absl_check.h"
#include "absl/log/absl_log.h"
#include "absl/log/check.h"
#include "absl/log/internal/log_message.h"
#include "absl/log/log_sink.h"
#include "absl/strings/str_format.h"
#include "absl/strings/str_split.h"

#include "absl/flags/declare.h"
#include "absl/log/internal/log_message.h"
#include "absl/log/internal/log_sink_set.h"
#include "absl/strings/str_cat.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"

#include "absl/base/log_severity.h"
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/flags/usage.h"
#include "absl/strings/str_cat.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"

#include "absl/algorithm/algorithm.h"
#include "absl/algorithm/container.h"
#include "absl/base/log_severity.h"
#include "absl/debugging/internal/stack_consumption.h"
#include "absl/debugging/leak_check.h"
#include "absl/debugging/stacktrace.h"
#include "absl/debugging/symbolize.h"
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/flags/usage.h"
#include "absl/log/log_sink_registry.h"
#include "absl/strings/str_cat.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"

#include "absl/hash/hash.h"
#include "absl/log/initialize.h"
#include "absl/strings/string_view.h"
#include "absl/strings/str_split.h"

#include <tuple>
#include <string>
#include <vector>

bool TestCheck()
{
    return false;
}
ABSL_FLAG(std::string,
          log_dir,
          "C:\\Users\\wisechip\\Desktop\\temp",
          "directory to write log files");
ABSL_FLAG(std::string,
          program_name,
          "test_abseil",
          "program name to use in log files");

void InitializeLogging() {
  std::string log_filename = absl::StrCat(
      absl::GetFlag(FLAGS_program_name), ".",
      absl::FormatTime("%Y%m%d", absl::Now(), absl::LocalTimeZone()), ".log");
  std::string log_filepath =
      absl::StrCat(absl::GetFlag(FLAGS_log_dir), "\\", log_filename);

  // absl::InitializeLogSink(log_filepath.c_str(), absl::LogSink::kLogrotate);
}

namespace wisechip {
namespace base {
class LinePrinterLogSink : public absl::LogSink {
 public:
  LinePrinterLogSink(const std::string& log_file_path)
      : log_file_path_(log_file_path) {
    fopen_s(&fp_, log_file_path.c_str(), "a");
  }

  ~LinePrinterLogSink() {
    fputc('\f', fp_);
    PCHECK(fclose(fp_) == 0) << "Failed to close " << log_file_path_.c_str();

  }

  void Send(const absl::LogEntry& entry) override {
    for (absl::string_view line :
         absl::StrSplit(entry.text_message_with_prefix(), absl::ByChar('\n'))) {
      // Overprint severe entries for emphasis:
      for (int i = static_cast<int>(absl::LogSeverity::kInfo);
           i <= static_cast<int>(entry.log_severity()); i++) {
        absl::FPrintF(fp_, "%s\r", line);
      }
      fputc('\n', fp_);
    }
  }

 private:
  FILE* fp_;
  std::string log_file_path_;
};

class LogInitializer {
 public:
  LogInitializer(const std::string& log_file_path)
      : line_printer_log_sink_(log_file_path) {
    absl::AddLogSink(&line_printer_log_sink_);
  }

  ~LogInitializer() { absl::RemoveLogSink(&line_printer_log_sink_); }

 private:
  LinePrinterLogSink line_printer_log_sink_;
};
}  // namespace base
}  // namespace wisechip

#include <vector>

int main() {
  absl::InitializeLog();
  // wisechip::base::LogInitializer
  // log("C:\\Users\\wisechip\\Desktop\\temp\\1.txt");
  wisechip::base::LogInitializer log("test_abseil_log.txt");

  // std::vector<int> vi{ 1,2,3,4,5,6 };
  // auto iter = absl::linear_search(vi.cbegin(), vi.cend(), 5);
  LOG(INFO) << "Log message.";
  LOG(ERROR) << "error1";
  LOG(WARNING) << "It's warning 1";
  LOG(ERROR) << "error2";
  LOG(WARNING) << "It's warning 2";
  LOG(INFO) << "Log message2.";

  absl::string_view str("hello world");

  std::string str_hello = "hello_world";

  // test hash
  auto hash_id = (absl::Hash<std::tuple<int, int>>{}(std::make_tuple(1, 2)));
}