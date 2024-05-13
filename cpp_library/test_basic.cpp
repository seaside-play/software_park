#include "test_basic.h"

#include <cassert>
#include <cmath>
#include <cstdint>

#include <functional>
#include <iostream>
#include <string>

namespace test {

void TestBasic::Test() {
  TestBoolean();
  TestPow();
  TestSin();
  TestRegister();
  TestBit();
  TestStruct();
  TestString();
  TestClone();
  TestRGB();
  TestSharedPtr();
  TestEnum();
  TestTemplate();
  TestDerivedClass();
  TestVerify();
  TestSmartSubclass();
  TestDefineMacro();
  TestTypeid();
  TestRedefineMacro();
  TestMoveStruct();
}

void TestBasic::TestBoolean() {
  int a = 10;
  bool flag = !!a;

  int b = 0;
  bool flag2 = !!b;
}

void TestBasic::TestPow() {
  auto num = 25;
  auto square_root = std::pow(num, 0.5);
}

void TestBasic::TestSin() {
  double pi = std::acos(-1);

  auto degree_30 = pi / 6;
  auto sin_value = std::sin(degree_30);
  auto arc_sin_value = std::asin(sin_value);
}

void TestBasic::TestRegister() {
  auto BoolRetureValue = []() {
    static bool flag = true;
    flag = !flag;
    return flag;
  };

  auto ret = BoolRetureValue();
  ret = BoolRetureValue();

  auto StrReturn = []() { return "HelloWorld!"; };

  auto str = StrReturn();

  auto curline = 1;
  curline = std::sin(1);
}

void TestBasic::TestBit() {
  auto nIncrement = 2048;
  auto nAvailableSize = 5000;
  auto nCurSize = 4996;
  auto nCurNewSize = nCurSize + 10;
  if (nCurNewSize >= nAvailableSize) {
    nAvailableSize = (nCurNewSize & ~(nIncrement - 1)) + nIncrement;
  }

  bool flag = true;
  bool even = !((33 - 1) & 0x01);
}

void TestBasic::TestStruct() {
  struct stu1 {
    int i;
    char c;
    int j;
  };

  struct stu2 {
    char c;
    int i;
    short d;
  };

  struct stu3 {
    bool c;
    int i;
    short d;
  };

  auto size = sizeof(stu1);
  auto size2 = sizeof(stu2);
  auto size3 = sizeof(stu3);

  struct st1 {
    bool flag;
    char c;
    int i;
  };

  struct Base {
    virtual void f() {}
  };
  struct Deriver : Base {
    int i;
    bool flag;
    int j;
    virtual void f() {}
  };

  auto len = sizeof(st1);
  auto len1 = sizeof(Deriver);
}

void TestBasic::TestString() {

 }

void TestBasic::TestClone() {
  using SpElement = std::shared_ptr<Element>;
  auto element = std::make_shared<Element>();
  auto points = std::make_shared<Points>();
  for (int i = 0; i < 5; ++i) {
    points->emplace_back(i, i+1);
  }
  element->ElementType(ElementType::PATH);
  element->Points(points);

  std::vector<SpElement> elements;
  for (int i = 0; i < points->size()-1; ++i) {
    auto element1 = std::make_shared<Element>();
    *element1.get() = *element.get();
    element1->AddPoint(*element.get(), i, 2);
    elements.emplace_back(std::move(element1));
  }
 
  //auto p = clone(*element.get());

  element->AddPoint(Point(10, 11));
}

void TestBasic::TestRGB() {
  uint8_t r = 255;
  uint8_t g = 0;
  uint8_t b = 155;

  int32_t color = 0;
  color += r;
  color = color << 8;
  color += g;
  color = color << 8;
  color += b;

  uint8_t r1 = 0;
  uint8_t g1 = 0;
  uint8_t b1 = 0;
  b1 = static_cast<uint8_t>(color & 0xFF);
  g1 = static_cast<uint8_t>(color >> 8 & 0xFF);
  r1 = static_cast<uint8_t>(color >> 16 & 0xFF);
}

class A {
  public:
};

class B : public A{
  public:
};

class BaseA {  
public:  
    int a;  
    BaseA(int val) : a(val) { }  
};  
  
class Derived : public BaseA {  
public:  
    int b;  
    using BaseA::BaseA;  // 导出基类构造函数  
    Derived(int val1, int val2) : BaseA(val1), b(val2) {}  // 初始化派生类成员变量  
};  


void TestBasic::TestSharedPtr() {
  std::shared_ptr<A> spa;
  spa = std::make_shared<B>();
}

void TestBasic::TestEnum() {
  enum class E {E1 = 0, E2 = 10};
  auto pos = E::E1;
  uint32_t a = static_cast<uint32_t>(pos);
  uint16_t a1 = 1;
  int b = a1;
}

enum NotifyType {LOG, OUTPUT, PROGRESS, OTHER};

template <typename Func, NotifyType nt>
class XCallback {
 private:
  XCallback() = default;
  XCallback(const XCallback&) = delete;
  XCallback& operator=(const XCallback&) = delete;

 public:
  static XCallback& Instance() {
    static XCallback xcallback;
    return xcallback;
  }

  template <typename Func>
  void Add(Func func) { func_ = func; }

  template <typename... T>
  void OutPut(T... args) {
    if (func_)
      func_(args...);
  }

 private:
  Func func_;
};

void TestBasic::TestTemplate() {
  std::cout << __func__ << ":\n";
  using CallbackType1 = std::function<void(uint32_t, std::string&& message)>;
  using CallbackType2 = std::function<bool()>;

  XCallback<CallbackType1, LOG>::Instance().Add([](uint32_t id, std::string&& message) {
    std::cout << id << " " << message << std::endl;
  });

  XCallback<CallbackType1, LOG>::Instance().OutPut(1, "Hello");

  XCallback<CallbackType2, OTHER>::Instance().Add([]()->bool {
    std::cout << "Success for boolean\n";
    return true;
  });

  XCallback<CallbackType2, OTHER>::Instance().OutPut();
}

class BaseLayer {};

class GdsHsMap {};

class GdsHsMapAdapter : public GdsHsMap {
 public:
  explicit GdsHsMapAdapter(BaseLayer& base_layer) : base_layer_(base_layer) {}

 BaseLayer& base_layer_;
};

void TestBasic::TestDerivedClass() {
  

}

#define verify(f) (assert(f))

void TestBasic::TestVerify() {
  auto Lam = []() { return true;};
  auto Lam2 = []() { return false;};

  //verify(Lam());
  //verify(Lam2());
}

void TestBasic::TestSmartSubclass() {
}

enum T {
  T_add_net
};

#define TOKDEF(x) { #x, T_##x }

void TestBasic::TestDefineMacro() {
 struct KeyWord {
  const char* name;
  int token;
 };

 static const KeyWord keywords[] = {
  TOKDEF(add_net)
 };

}

void TestBasic::TestTypeid() {
  std::string class_name = typeid(this).name();
}

void TestBasic::TestRedefineMacro() {
  auto pi = PI;
}

void TestBasic::TestMoveStruct() {
  struct PadAttr {
    uint16_t layer_id{0};
    size_t width{0};
    size_t heigth{0};
  };
  PadAttr pa{1, 2, 3};
  PadAttr pb;
  pb = std::move(pa);
}

}  // namespace test

