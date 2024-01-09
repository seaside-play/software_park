#include "data_parser.h"

#include "test.pb.h"
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"

namespace test {

DataParser::DataParser(std::string&& path) 
    : path_(std::move(path)),
      root_(std::make_shared<root>()), 
      msg_(root_.get()){}

bool DataParser::Parse() {
  return false;
}

}
