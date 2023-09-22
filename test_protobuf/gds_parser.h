#pragma once

#include <string>


class GdsParser
{
public:
	GdsParser();
	bool Parse(const std::string& path);

};

