#include "test_esoterica.h"

#include <cassert>
#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <vector>

#include <boost/any.hpp>
#include <boost/variant.hpp>
#include <boost/optional.hpp>

void TestEsoterica::Test() {
  TestBoostAny();
  TestBoostVariant();
  TestBoostVariant2();
  TestOptional();
  TestArray();
  TestTie();
}

void TestEsoterica::TestBoostAny() {
  std::vector<boost::any> some_values;
  some_values.push_back(10);
  const char* c_str = "hello world!";
  some_values.push_back(c_str);
  some_values.push_back(std::string("Wow!"));
  std::string& s = boost::any_cast<std::string&>(some_values.back());
  s += "That is greate!\n";
  auto capacity = some_values.capacity();
  auto size = some_values.size();
  std::cout << s;

  boost::any variable(std::string("Hello World!"));

  try {
  
  // 若variable不是std::string，可能会抛出any_cast异常
  std::string s1 = boost::any_cast<std::string>(variable); 
  // 若variable不是std::string，将返回一个nullptr指针；
  std::string* s2 = boost::any_cast<std::string>(&variable);
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << "\n";
  }

  // 可使用catch(const std::exception& e)捕获几乎所有的Boost异常
}

void TestEsoterica::TestBoostVariant() {
  using my_var_t = boost::variant<int, const char*, std::string>;
  std::vector<my_var_t> some_values;
  some_values.push_back(10);
  some_values.push_back("Hello there!");
  some_values.push_back(std::string("Wow!"));
  std::string& s = boost::get<std::string>(some_values.back());
  s += " That is greate!\n";
  std::cout << s;

  const char* c_str = boost::get<const char*>(some_values[1]);

  int ival = boost::get<int>(some_values.front());
}

void TestEsoterica::TestBoostVariant2() {
  std::cout << __func__ << ": ";
  using my_vat_t = boost::variant<boost::blank, int, const char*, std::string>;
  my_vat_t var;

  // 默认构造函数将创建一个boost::blank实例
  assert(var.which() == 0); // 空状态
  var = "Hello, dear reader";
  assert(var.which() != 0);

  // 可以使用两种方法从一个变体得到一个值
  boost::variant<int, std::string> variable(0);
  int s1 = boost::get<int>(variable);
  int* s2 = boost::get<int>(&variable);

  boost::variant<int, std::string> variable2(std::string("Hello, dear lover."));
  std::string str = boost::get<std::string>(variable2);

  int cur_index = variable2.which();

  variable2 = 1;
  std::cout << "variable2: " << boost::get<int>(variable2) << "\n";
}

class LockedDevice {
  explicit LockedDevice(const char* /*param*/) {
    std::cout << "Device is locked\n";
  }

 public:
  ~LockedDevice() { // release device lock 
  }

  void Use() { std::cout << "Success!\n"; }

  static boost::optional<LockedDevice> try_lock_device() {
    if (rand() % 2) {
      // 未能锁定设备
      return boost::none;
    }
    // 成功！
    return LockedDevice("device name"); // device name
  }

};

int TestEsoterica::TestOptional(){
  for (unsigned i = 0; i < 10; ++i) {
    boost::optional<LockedDevice> t = LockedDevice::try_lock_device();
    // optional 能够转为bool类型
    if (t) {
      t->Use();
      return 0;
    } else {
      std::cout << "... trying again\n";
    }
  }
  std::cout << "Failure!\n"; // 失败
  return -1;
}

void TestEsoterica::TestArray() {}

void TestEsoterica::TestTuple() {}

void TestEsoterica::TestTie() {
  auto tp = std::make_tuple<int, double, float>(1, 1.0, 3.4);
  int a;
  double c;
  float d;
  std::tie(a, c, d) = tp;

  auto tp2 = std::tie(a, d);
}
