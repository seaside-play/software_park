#include "test_abseil.h"

#include <algorithm>
#include <cmath>
#include <string>

#include "absl/strings/str_cat.h"
#include "absl/strings/str_format.h"
#include "absl/strings/str_replace.h"

namespace test {

void TestAbseil::Test() {
  TestStrCat();
  TestStrSplit();
  TestStrFormat();
  TestStrReplace();
}

void TestAbseil::TestStrCat() {
  std::string str1{"hello world!"};
  auto str2 = absl::StrCat(str1, " I love u!");
  absl::StrAppend(&str2, " this is a new world", "xxx");
}

void TestAbseil::TestStrSplit() {}

void TestAbseil::TestStrFormat() {
  std::string new_name;
  std::string ckt_name = "ckt1";
  int i;
  int loop = 5;
  for (new_name = ckt_name + "Copy", i = 2; loop-- != 0;
       new_name = absl::StrFormat("%sCopy%d", ckt_name, i++))
    ;

  std::string msg = absl::StrFormat("\"%s\"", ckt_name.c_str());
}

void TestAbseil::TestStrReplace() {
  std::string content = ".Partion XXX extnode = A";
  std::string raw = "XXX";
  std::string new_word = "YYY";
  auto new_content = absl::StrReplaceAll(content, {{raw, new_word}});
  // std::replace(content.begin(), content.end(), raw, new_word);
}

}  // namespace test