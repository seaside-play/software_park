// TestGds.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#include <algorithm>


#include "test_smart_ptr.h"
#include "tools.h"
#include "shape_element.h"
#include "geometry_net.h"

using namespace std;

struct Person
{
    std::string name;
    std::shared_ptr<std::string> address;
};

class Package
{
public:
    void PrintPackageAddress()
    {
        std::cout << "Package address: " << this << std::endl;
    }
};

class GdsTrace
{
public:
    GdsTrace(const std::string& name) {}

};

namespace mars
{
    namespace nep
    {
        class Container
        {
        public:
            void Initialize()
            {
                package_ = new Package();
            }

            void AddPackage(nullptr_t package)
            {
                package_ = static_cast<Package*>(package);
                package_->PrintPackageAddress();
            }

        public:
            Package* package_;
        };
    }
}

#define SET_SHAPE_ID 1

auto Add(int a, int b)
{
    return a + b;
}


int main()
{
    GeometryNet geometry_net;
    geometry_net.test();

    TestShapeElement test_shape_element;
    test_shape_element.Test();

    SmartPtr smart_ptr;
    smart_ptr.Test();

    auto add_resutl = Add(1, 2);

    std::unordered_map<int, bool> umap_layer_id_existed{ {1, true}, {2, true} };
    if (umap_layer_id_existed[3])
    {
        std::cout << "existed!" << std::endl;
    }
    else
    {
        std::cout << "not existed!" << std::endl;
    }


    std::vector<int> vi_back;
    vi_back.push_back(1);
    vi_back.push_back(3);
    vi_back.push_back(5);
    auto cur_back = vi_back.back();
    vi_back.push_back(7);
    vi_back.pop_back();
    cur_back = vi_back.back();

    for (auto it = vi_back.crbegin(); it != vi_back.crend(); ++it)
    {
        std::cout << *it << " " << std::endl;
    }


    Point start_point{ 0, 0 };
    Point end_point{ -1, -1 };

    auto raw_end_point = tools::RawEndPoint(start_point, end_point);

    double angle = tools::IntersectionRadian(start_point, end_point);
    std::cout << angle << std::endl;

    auto angle1 = std::atan2(1, 1) * 180 / kPi;
    auto hypotenuse = std::hypot(1, 1);
    auto cos_ret = 1 / hypotenuse;

    auto cos_value = std::cos(60.0 * kPi / 180.0);
    auto cos_value_h = std::cos(60.0 * kPi / 180.0);

    bool flag1 = true;
    bool flag1_rever = !flag1;
    bool flag1_rever_rever = !flag1_rever;

    std::vector<int> vi_test(5);
    vi_test.emplace_back(1);


    std::string hex_str = "10000000000000000";

    double dl = 0.000000000001;
    printf("units %le", dl);

    int bi = 0b10000000000000000;

    std::bitset<16> cur_bit_value(hex_str);
    std::bitset<16> cur_bit_value2(bi);

    std::vector<std::vector<int>> matrix { {1, 2, 2, 1, 2}, { 5,6,7,8,3 }, { 9,3,0,5,3 }, { 7,2,1,4,6 }, {3,0,8,2,4}};
    std::swap(matrix.at(0), matrix.at(4));

    int* p = nullptr;
    std::cout << "sizeof(p): " << sizeof(p) << std::endl;

    std::vector<int> vi;
    auto vi_flag = !!vi.empty();

    double d1 = 1;

    auto gds_trace = new (std::nothrow) GdsTrace("path");

    auto new_vi = new(std::nothrow)Package;

    auto define_id_len = sizeof(SET_SHAPE_ID);

    auto package = new Package();
    cout << "new Package() address: " << package << "; **address: " << &package << std::endl;
    package->PrintPackageAddress();

    std::unordered_set<int16_t> si{ -1,2,1,3,4,6 };
    si.erase(-1);
    si.erase(10);


    

    std::bitset<4> a; //申请一个名为a长度为4的bitset，默认每位为0
    std::bitset<8> b(12); //长度为8，将12二进制保存在b中，前面位补0
    string s = "00101000111101011100001010001111010111000010100011110110";
    bitset<57> c(s);  //长度为10，将s二进制保存在c中，前面位补0

    unsigned long long mantissa = c.to_ullong();
    auto mantissa_str = c.to_string();

    double ret = mantissa / pow(2, 56);
    ret = ret * pow(16, -1);

    std::cout << "二进制各个位数的布尔值:" << std::endl;
    for (int i = 0; i < c.size(); ++i)
    {
        std::cout << std::boolalpha << i << " : " << c.test(i) << "  " << std::endl;
    }
    

    cout << a << endl; //0000
    cout << b << endl; //00001100
    cout << c << endl; //0000010010


    std::bitset<16> strans_base(0x8006);

    
    std::string stras_record = strans_base.to_string();

    auto person = std::shared_ptr<Person>();
    auto order_map = std::make_shared<std::unordered_map<std::string, std::shared_ptr<Person>>>();
    order_map->emplace("Hello", person);

    std::cout << sizeof(int16_t) << std::endl;


    std::cout << "Hello World!\n";
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
