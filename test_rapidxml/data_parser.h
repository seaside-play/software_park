#pragma once

#include <memory>
#include <string>

#include "rapidxml/rapidxml_print.hpp"
#include "test.pb.h"

namespace test {

class DataParser {
 public:
  DataParser(std::string&& path);

  bool Parse();

 private:
  std::string path_;
  std::shared_ptr<root> root_;
  google::protobuf::Message* msg_;
  //rapidxml::xml_document<> xml_doc_;
};

}

