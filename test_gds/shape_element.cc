#include "shape_element.h"
#include <unordered_map>
#include <sstream>

void GdsShape::set_net(const std::string& net_name)
{
	auto shape_element = reinterpret_cast<ShapeElement*>(this);
	shape_element->net_name_ = net_name;
};


void test_vector(int** p, int rows, int cols)
{

}

void TestShapeElement::Test()
{
	auto* gds_polygon = new GdsPolygon();
	gds_polygon->net_name_ = "Hello Polygon";

	GdsShape* gds_shape = gds_polygon;
	gds_shape->set_net("I am from GdsShape");

	std::unordered_map<int, std::unordered_map<int, GdsShape*>> layerid_shapes;
	layerid_shapes[1].insert({2, gds_shape });
	layerid_shapes[1].insert({ 3, gds_shape });



	std::vector<std::vector<int>> vvi;
	vvi.push_back({1,2,3,4});
	vvi.push_back({1,2,3});


	std::ostringstream oss;
	oss << "hello " << "world";
	std::string str1 = oss.str();
	std::string str2 = oss.str();
	// 二维的vector不能够转化为指针二维数值
	//test_vector((char**)vvi, vvi.size(), 4);


	auto diff = std::distance(vvi.begin(), vvi.end());
	auto diff2 = std::distance(vvi.end(), vvi.begin());
}