// test_rapidxml.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

#include "data_parser.h"

int main()
{
  auto data_parser = test::DataParser("./test.xml");
  auto ret = data_parser.Parse();

  std::cout << "Hello World!\n";
}

