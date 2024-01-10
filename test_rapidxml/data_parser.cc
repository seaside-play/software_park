#include "data_parser.h"

#include <iostream>

#include "test.pb.h"

namespace test {

DataParser::DataParser(std::string&& path)
    : path_(std::move(path)),
      root_(std::make_shared<root>()),
      msg_(root_.get()) {}

bool DataParser::Parse() {
  bool ret = false;
  try {
    rapidxml::file<> fdoc(path_.c_str());
    rapidxml::xml_document<> doc;
    doc.parse<0>(fdoc.data());
    auto root = doc.first_node();
    ret = Parse(*root_.get(), root, node_name_);
  } catch (rapidxml::parse_error err) {
    std::cout << "rapidxml::parse_error: " << err.what() << "\n";
  } catch (...) {
    std::cout << "exception\n";
  }

  std::cout << "protobuf content: " << root_->DebugString() ;
  return ret;
}

bool DataParser::Parse(gp::Message& msg,
                       const rapidxml::xml_node<>* node,
                       const std::string& node_name) {
  if (node == nullptr)
    return false;

  ParseValue(msg, node, node_name);
  ParseAttribute(msg, node);
  ParseSubNode(msg, node, node_name);

  return true;
}

bool DataParser::ParseValue(gp::Message& msg,
                            const rapidxml::xml_node<>* node,
                            const std::string& node_name) {
  if (node->value_size() <= 0)
    return true;

  return handle_value(msg, node_name, node->value());
}

bool DataParser::handle_value(gp::Message& msg,
                              const std::string& node_name,
                              const std::string& node_value) {
  auto desc = msg.GetDescriptor();
  auto field = desc->FindFieldByName(node_name);
  if (field == nullptr)
    return false;

  auto ref = msg.GetReflection();
  switch (field->cpp_type()) {
    case gp::FieldDescriptor::CppType::CPPTYPE_MESSAGE:
      return MessageValue2FieldValue(msg, field, ref, node_value);
    case gp::FieldDescriptor::CppType::CPPTYPE_STRING:
      return StringValue2FieldValue(msg, field, ref, node_value);
    default:
      break;
  }

  return false;
}

bool DataParser::MessageValue2FieldValue(gp::Message& msg,
                               const gp::FieldDescriptor* field,
                               const gp::Reflection* ref,
                               const std::string& node_value) {
  return true;
}

bool DataParser::StringValue2FieldValue(gp::Message& msg,
                               const gp::FieldDescriptor* field,
                               const gp::Reflection* ref,
                               const std::string& node_value) {

  if (field->is_repeated()) 
    ref->AddString(&msg, field, node_value);
  else
    ref->SetString(&msg, field, node_value);
  return true;
}

bool DataParser::ParseAttribute(gp::Message& msg,
                                const rapidxml::xml_node<>* node) {
  for (auto attr = node->first_attribute(); attr != nullptr; attr = attr->next_attribute()) {
    if (attr->name_size() <= 0 || attr->value_size() <= 0)
      continue;
    handle_value(msg, attr->name(), attr->value());
  }

  return true;
}

bool DataParser::ParseSubNode(gp::Message& msg,
                              const rapidxml::xml_node<>* node,
                              const std::string& node_name) {
  auto desc = msg.GetDescriptor();
  auto ref = msg.GetReflection();

  for (auto child = node->first_node(); child != nullptr; child = child->next_sibling()) {
    if (child->name_size() <= 0)
      continue;
    auto field = desc->FindFieldByName(child->name());
    if (field == nullptr)
      continue;

    if (field->cpp_type() != google::protobuf::FieldDescriptor::CppType::CPPTYPE_MESSAGE)
      continue;

    auto sub_msg = field->is_repeated() ? ref->AddMessage(&msg, field) : ref->MutableMessage(&msg, field);

    Parse(*sub_msg, child, node_name);
  }

  return true;
}

}  // namespace test
