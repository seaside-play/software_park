#include "gds_parser.h"

#include <fstream>

GdsParser::GdsParser() 
{}

bool GdsParser::Parse(const std::string& path)
{
	std::fstream tech_file;
	tech_file.open(path, std::ios::in);
	if (!tech_file.is_open())
		return false;



	return false;
}