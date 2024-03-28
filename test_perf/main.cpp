// test_perf.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "test_overflow.h"

int main()
{
  std::cout << "Begin to test performance...\n" ;

  TestOverflow test_overflow;
  test_overflow.Test();
  
  std::cout << "End test performance...\n" ;
}
