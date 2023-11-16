#pragma once

#include <iostream>

namespace test {

// class mars::Tool;
struct Base {};

struct Derived1 : Base {};
struct Derived2 : Base {};

class TestObject {
  friend class Tool;

 public:
  TestObject();
  void Test();
  
 private:
  void TestStaticFuncInPrivate();

 private:
  int tools_count_{10};

 private:
  Base* base_;
};

namespace wisechip {
namespace gds {
  class Special;
}  // namespace gds
}  // namespace wisechip

class Project {
 private:
  static void Test() { std::cout << "I am from Project, it's privilege is private\n"; }
  
  friend class wisechip::gds::Special;
  friend class TestObject;
  friend class TestCkt;
};

}  // namespace test
