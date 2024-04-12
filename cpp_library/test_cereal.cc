#include "test_cereal.h"

#include <fstream>

#include <cereal/archives/xml.hpp>

namespace test {

void TestCereal::Test() {
  Test1();
  TestUnar();
  TestXML();
}

void TestCereal::Test1() {
  std::ofstream os("out.cereal", std::ios::binary);
  cereal::BinaryOutputArchive archive(os);

  MyRecord record;
  record.x = 1;
  record.y = 2;
  record.z = 3.0;

  SomeData myData;
  myData.id = 108;

  std::unordered_map<uint32_t, MyRecord> m;
  m[0] = record;

  auto data = std::make_shared<std::unordered_map<uint32_t, MyRecord>>(m);
  myData.data = data;

  archive(myData);
}

void TestCereal::TestUnar() {
  /// <summary>
  ///
  /// </summary>
  std::ifstream ifs("out.cereal", std::ios::binary);
  cereal::BinaryInputArchive unarchive(ifs);

  SomeData my_raw_data;
  unarchive(my_raw_data);
}

void TestCereal::TestXML() {
  {
    std::ofstream os("data.xml");
    cereal::XMLOutputArchive archive(os);

    MyRecord record;
    record.x = 1;
    record.y = 2;
    record.z = 3.0;

    SomeData myData;
    myData.id = 108;

    std::unordered_map<uint32_t, MyRecord> m;
    m[0] = record;

    auto data = std::make_shared<std::unordered_map<uint32_t, MyRecord>>(m);
    myData.data = data;
    int someInt = 1;
    double d = 0.0;

    archive(
        CEREAL_NVP(myData),  // Names the output the same as the variable name
        someInt,  // No NVP - cereal will automatically generate an enumerated
                  // name
        cereal::make_nvp("this_name_is_way_better",
                         d));  // specify a name of your choosing
  }

  {
    std::ifstream is("data.xml");
    cereal::XMLInputArchive archive(is);

    SomeData m1;
    int someInt;
    double d;

    archive(m1, someInt, d);  // NVPs not strictly necessary when loading
                              // but could be used (even out of order)
  }

}  // when archive goes out of scope it is guaranteed to have flushed its
   // contents to its stream

}  // namespace test