// TestCppRef.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main()
{
    //std::vector<int> v{ 3, 1, 4, 1, 5, 9, 2, 6 };
    //std::srand(std::time(0));
    //std::pair<int, int> bounds = std::minmax(std::rand() % v.size(),
    //    std::rand() % v.size());

    //std::cout << "v[" << bounds.first << "," << bounds.second << "]: ";
    //for (int i = bounds.first; i < bounds.second; ++i)
    //    std::cout << v[i] << ' ';
    //std::cout << '\n';


    auto v = { 3, 9, 1, 4, 2, 5, 9 };
    const auto min_max = std::minmax_element(begin(v), end(v));

    auto MinMax = [](std::vector<int>&& v) ->auto {
        return std::minmax_element(std::begin(v), std::end(v));
    };

    auto xs = MinMax(v);

    std::cout << "min = " << *min_max.first << ", max = " << *min_max.second << '\n';

}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
