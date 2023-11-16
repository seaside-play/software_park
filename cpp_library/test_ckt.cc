#include "test_object.h"

#include <iostream>
#include <string>

#include "test_ckt.h"
#include "test_object.h"

namespace test {

void TestCkt::Test() {
  std::cout << __func__ << "::";
  Project::Test();
}

}  // namespace test