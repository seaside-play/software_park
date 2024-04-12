#include "mas_component.h"
#include "test_basic.h"

namespace test {

MasComponent::MasComponent() {


}

void MasComponent::Test() {
  TestRedefinePI();
}

void MasComponent::TestRedefinePI() {
  auto pi = PI;
}

}