#include "test_esoterica.h"

#include <cassert>
#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include <boost/any.hpp>
#include <boost/variant.hpp>

void TestEsoterica::Test() {
  TestBoostAny();
  TestBoostVariant();
  TestBoostVariant2();
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
  
  // ��variable����std::string�����ܻ��׳�any_cast�쳣
  std::string s1 = boost::any_cast<std::string>(variable); 
  // ��variable����std::string��������һ��nullptrָ�룻
  std::string* s2 = boost::any_cast<std::string>(&variable);
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << "\n";
  }

  // ��ʹ��catch(const std::exception& e)���񼸺����е�Boost�쳣
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

  // Ĭ�Ϲ��캯��������һ��boost::blankʵ��
  assert(var.which() == 0); // ��״̬
  var = "Hello, dear reader";
  assert(var.which() != 0);

  // ����ʹ�����ַ�����һ������õ�һ��ֵ
  boost::variant<int, std::string> variable(0);
  int s1 = boost::get<int>(variable);
  int* s2 = boost::get<int>(&variable);

  boost::variant<int, std::string> variable2(std::string("Hello, dear lover."));
  std::string str = boost::get<std::string>(variable2);

  int cur_index = variable2.which();

  variable2 = 1;
  std::cout << "variable2: " << boost::get<int>(variable2) << "\n";
}