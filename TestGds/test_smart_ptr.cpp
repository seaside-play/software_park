#include "test_smart_ptr.h"

#include <cmath>
#include <chrono>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>


using Id = int;
using Name = std::string;
using IdNames = std::unordered_map<Id, Name>;

class A
{
public:
	IdNames GetIdNames()
	{
		return id_names_;
		/*IdNames id_names;
		id_names.emplace(1, "chris");
		return id_names;*/
	}

private:
	IdNames id_names_;
};

struct CoordinatePoint
{
	int x, y;
};

void set_smart_ptr(std::shared_ptr<SmartPtr> smart_ptr)
{
	std::shared_ptr<SmartPtr> temp;
	temp = std::move(smart_ptr);
	//temp = smart_ptr;
}


void SmartPtr::Test()
{
	std::shared_ptr<SmartPtr> cur_smart_ptr;
	auto sptr = std::make_shared<SmartPtr>();
	cur_smart_ptr = std::move(sptr);
	set_smart_ptr(cur_smart_ptr);

	auto now = std::chrono::system_clock::now();
	// 必须考虑多线程来处理计算
	for (int i = 0; i < 1000000; ++i)
	{
		for (int j = 0; j < 1000000; ++j)
		{
			int n;
			n = 1;
		}
	}
	auto current = std::chrono::system_clock::now();
	auto dif = current - now;
	auto micro_seconds = dif.count();

	std::chrono::duration<double> diff = current - now;

	CoordinatePoint pt;
	pt.x = 1; pt.y = 2;
	std::unordered_multimap<std::string, CoordinatePoint> points;
	points.emplace("chris", pt);


	A test_a;
	auto id_names = test_a.GetIdNames();
	for (auto id_name : id_names)
	{

	}

	std::string class_name = typeid(this).name();

	auto line_no = __LINE__;
	auto func_name = __func__;

	std::ostringstream oss;
	oss << class_name << "::" << __func__ << "::" << __LINE__ << std::endl;
	std::string location = oss.str();

	int a = 9054010;

	int b = 815000;
	int c = (long long)a << 32 + (long long)b;
	long long d = 7;
	
	auto binary_len = sizeof(long long) * 8;
	auto cur_len = std::ceil(log(100) / log(2));
	long long need_move_binary_count = (binary_len - cur_len);

	d = (long long)d << need_move_binary_count;
	d = (long long)d << 63;

	auto long_size = sizeof(long);
	auto longlong_size = sizeof(long long);
	long f = d | c;


	int n1 = 19;
	int n2 = 9;


	int n3 = (n1 - n2 >> 1) + n2;

	if (14 == n3)
		std::cout << "right" << std::endl;
	else 
		std::cout << "wrong" << std::endl;
}
