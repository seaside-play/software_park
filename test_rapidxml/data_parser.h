#pragma once

#include <memory>
#include <string>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "test.pb.h"

namespace gp = google::protobuf;

namespace test {

class DataParser {
 public:
  DataParser(std::string&& path);

  bool Parse();

  bool Parse(gp::Message& msg, const rapidxml::xml_node<>* node, const std::string& node_name);

 private:
  bool ParseValue(gp::Message& msg, const rapidxml::xml_node<>* node, const std::string& node_name);
  bool ParseAttribute(gp::Message& msg, const rapidxml::xml_node<>* node);
  bool ParseSubNode(gp::Message& msg, const rapidxml::xml_node<>* node, const std::string& node_name);

  bool handle_value(gp::Message& msg, const std::string& node_name, const std::string& node_value);

  bool MessageValue2FieldValue(gp::Message& msg,
                               const gp::FieldDescriptor* field,
                               const gp::Reflection* ref,
                               const std::string& node_value);

  bool StringValue2FieldValue(gp::Message& msg,
                               const gp::FieldDescriptor* field,
                               const gp::Reflection* ref,
                               const std::string& node_value);

 private:
  std::string path_;
  std::shared_ptr<root> root_;
  google::protobuf::Message* msg_;

  std::string node_name_ {"root"};
};

}

