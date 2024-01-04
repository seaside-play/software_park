#include "test_geometry.h"

#include <memory>

namespace test
{

void TestGeometry::Test() {
  TestPolygonArea();
  TestPositiveTriangle();
}
 
// 多边形面积计算公式，鞋带定理 refer: https://www.zhihu.com/question/444954371
// 什么是正多边形：多边形沿着逆时针方向为正多边形，使用右手定则来判断，若点在A->B的左侧，就是正多边形；反之，为负多边形。
void TestGeometry::TestPolygonArea() {
  auto A = std::make_pair(13, 55);
  auto B = std::make_pair(-20, -10);
  auto C = std::make_pair(-35.87, -14.88);
  auto D = std::make_pair(-8, -2);

  auto Area = [](const decltype(A)& A, const decltype(B)& B,
                 const decltype(A)& C) -> bool {
        auto sum = A.first * B.second + B.first * C.second + C.first * A.second -
                   B.first * A.second - C.first * B.second - A.first * C.second;
        return sum > 0;
      };

  auto flag = Area(A, B, C);
  auto flag2 = Area(A, B, D);
}

void TestGeometry::TestPositiveTriangle() {
  using Point = std::pair<long, long>;
  Point pt1 {-120000, 41000};
  Point pt2 {-118693, 41337};
  Point pt3 {-119520, 42122};
  Point pt4 {-119137, 40114};

  auto Direction = [](const Point& pt1, const Point& pt2, const Point& pt3) {
    auto ret = pt1.first * pt2.second + pt2.first * pt3.second +
               pt3.first * pt1.second - pt2.first * pt1.second -
               pt3.first * pt2.second - pt1.first * pt3.second;

    return ret > 0;
  };

  auto flag = Direction(pt1, pt2, pt3);
  auto flag2 = Direction(pt1, pt2, pt4);
  

}


}
