#pragma once

#include <algorithm>
#include <memory>
#include <vector>

#include "mas_component.h"

namespace test {
  
template <typename T>
T* clone(const T& obj) {
    T* newObj = new T();  // 创建一个新的对象  
    std::copy(obj.begin(), obj.end(), newObj->begin());  // 深拷贝成员变量  
    return newObj;  
}

struct Point {
  Point(int x0, int x1) : x(x0), y(x1) {}
 int x; int y;
};
using Points = std::vector<Point>;
using SpPoints = std::shared_ptr<Points>;

enum class ElementType {PATH, POLYGON, BOX};

class Element {
 public:
  Element& operator=(const Element& element) {
    if (&element == this) return *this;

    element_type_ = element.element_type_;
    points_ = std::make_shared<std::vector<Point>>();
    
    return *this;
  }

  void AddPoint(Element& element, int start, int count) { 
    for (int i = start; i < start + count; ++i) {
      auto item = element.points_->at(i);
      points_->push_back(item);
    }
  }
  void ElementType(ElementType element_type) { element_type_ = element_type; }
  void Points(SpPoints points) { points_ = points; }

  void AddPoint(Point point) { points_->push_back(std::move(point)); };

 protected:
  SpPoints points_;

 private:
  enum ElementType element_type_;
};

class MasComponent;
class TestBasic {
 public:
  void Test();

 private:
  void TestBoolean();
  void TestPow();
  void TestSin();
  void TestRegister();
  void TestBit();
  void TestStruct();
  void TestString();
  void TestClone();
  void TestRGB();
  void TestSharedPtr();
  void TestEnum();
  void TestTemplate();
  void TestDerivedClass();
  void TestVerify();
  void TestSmartSubclass();

private:
  std::unique_ptr<MasComponent> mas_component_;
};

}  // namespace test
