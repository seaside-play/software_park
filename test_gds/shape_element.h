#pragma once
#include <string>
#include <memory>


struct ShapeElement
{
	int age{ 18 };
	std::string net_name_{ "default" };
	int number{19};

};

struct PolygonElement
	: ShapeElement
{};

struct BoxElement
	: ShapeElement
{};

struct GdsShape
{
	void set_net(const std::string& net_name);
};

struct GdsPolygon
	: GdsShape,
	  PolygonElement
{};

struct GdsBox
	: GdsShape,
	  BoxElement
{};

class TestShapeElement
{
public:
	void Test();
};