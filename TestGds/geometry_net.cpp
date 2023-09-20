#include "geometry_net.h"
#include <cmath>
#include <unordered_map>
#include <map>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>


void GeometryNet::test()
{
	std::unordered_map<int, int> um;

	
	int32_t a = 8926760;
	int32_t b = 485725;

	std::int64_t hash_id = (int64_t)a << 32 | b;

	UnifyNet();
	TestMap();

}

void GeometryNet::TestMap()
{
	using Names = std::set<std::string>;
	Names names;

	names.insert("Lucy");

	std::unordered_map<int, Names> room_id_names;

	room_id_names[1].insert("Chris");
	room_id_names[2].insert("John");
	room_id_names[3].insert("Peter");
	room_id_names[4].insert("Andrew");
	room_id_names[1].insert("Lily");
	room_id_names[1].insert("Frank");

	using Si = std::set<int>;
	std::set<Si> si_set;
	Si si1 = { 1,2 };
	Si si2 = { 3, 4 };
	Si si3 = { 1, 2 };
	Si si4 = { 2, 1 };

	si_set.insert(si1);
	si_set.insert(si2);
	si_set.insert(si3);
	si_set.insert(si4);
	si_set.insert(si4);

	auto mix_max = std::minmax(7, 5);

	double d1 = 5.43562343634523;
	auto d1_integer = std::round(d1);
	double d2 = 5.53562343634523;
	auto d2_integer = std::round(d2);

}


long long GeometryNet::HashId(int a, int b)
{
	return (long long)a << 32 | b;
}

void GeometryNet::UnifyNet()
{
	std::unordered_multimap<long long, std::string> one_layer_shapes_;
	one_layer_shapes_.insert({HashId(1,2), "chris"});
	one_layer_shapes_.insert({HashId(1,2), "chaojiang"});
	one_layer_shapes_.insert({HashId(3,4), "peter"});

	for (const auto& item : one_layer_shapes_)
	{
		if (1 == one_layer_shapes_.count(item.first))
			continue;

		std::cout << item.first << " " << item.second << std::endl;
	}

}
