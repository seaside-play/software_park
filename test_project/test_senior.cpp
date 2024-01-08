#include "test_senior.h"

#include <iostream>
#include <memory>
#include <type_traits>

namespace test {

struct Net {

};

using SpNet = std::shared_ptr<Net>;

//template <typename T, std::enable_if<std::is_same<T, int>::value>>
//void FillNet(T i) {
//  std::cout << "int parameter\n" ;
//}
//
//template <typename T, std::enable_if<std::is_same<T, int>::value>>
//void FillNet(double d) {
//  std::cout << "double parameter\n" ;
//}

void TestSenior::Test() {
  //TestEnableIf();
}


void TestSenior::TestEnableIf() {

}

}  // namespace test