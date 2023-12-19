#include "test_geometry.h"

#include <memory>

namespace test
{

void TestGeometry::Test() {
  TestPolygonArea();
}
 
// �����������㹫ʽ��Ь������ refer: https://www.zhihu.com/question/444954371
// ʲô��������Σ������������ʱ�뷽��Ϊ������Σ�ʹ�����ֶ������жϣ�������A->B����࣬����������Σ���֮��Ϊ������Ρ�
void TestGeometry::TestPolygonArea() {
  auto A = std::make_pair(-350, 350);
  auto B = std::make_pair(278, -179);
  auto C = std::make_pair(84, 211);
  auto D = std::make_pair(-254, -78);

  auto Area = [](const decltype(A)& A, const decltype(B)& B,
                 const decltype(A)& C) -> bool {
        auto sum = A.first * B.second + B.first * C.second + C.first * A.second -
                   B.first * A.second - C.first * B.second - A.first * C.second;
        return sum > 0;
      };

  auto flag = Area(A, B, C);
  auto flag2 = Area(B, A, D);
}

}
