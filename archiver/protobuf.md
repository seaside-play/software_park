# 1下载protoc编译器

源代码和可执行文件下载：[下载地址](https://github.com/protocolbuffers/ProtoBuf/releases)

可根据不同的系统，下载对应的可执行文件，用于编译`.proto`文件

示例C++的命令方式为： `protoc.exe --cpp_out=./ demo.proto`，就可以生成对应的demo.pb.h和demo.ph.cc源代码


## 安装vcpkg


[下载地址](https://github.com/Microsoft/vcpkg#getting-started)

for windows:

	> git clone https://github.com/microsoft/vcpkg
	> .\vcpkg\bootstrap-vcpkg.bat

通过vcpkg对protobuf源代码进行编译，参数对应的库文件

使用方法：

`vcpkg search protobuf` // 搜索需要的包   
`vcpkg install protobuf：x64-windows` // 表示下载protobuf，用于x64-windows  
`vcpkg install protobuf：x64-windows-static` // 表示下载protobuf，用于x64-windows下的静态库    
`vcpkg install protobuf：x64-windows-static-md` // 表示下载protobuf，用于x64-windows下的静态库并且为md编译方式        

vcpkg是一个特别棒的工具，针对vc开发者而言，只要通过它，就可以获得任何需要的库文件。

## 使用cmake编译protobuf源代码

[详见地址](https://github.com/protocolbuffers/protobuf/blob/main/src/README.md)

就是用git下载ProtoBuf源码，再用cmake进行生成工程项目文件，用vs2019运行工程项目文件，产生protobuf相关的debug或release库文件。

Google C++ 标准库的扩充库 Abseil：Abseil 由 Google 的基础 C ++ 和 Python 代码库组成，包括一些正支撑着如 gRPC、Protobuf 和 TensorFlow 等开源项目并一起 “成长” 的库。目前已开源 C++ 部分，Python 部分将在后续开放。

#2proto2和proto3的区别

- 更简洁
- 更强调约定而弱化语法
- 移除required，把optional改名为singular
- 增加语言支持，如Go、Ruby、JavaNano
- 移除default选项，在proto3中，默认值有系统决定，全部都是约定好的，不再提供默认值，因为本身提供了默认值，还有就是有时软件也会赋值默认值，这个时候就区分不了了；
- 枚举类型第一个字段必须是0，是一个约定
- 移除了对分组的支持
- 旧代码在解析新增字段时，会把不认识的字段丢弃，再序列化后新增字段没了；
- 移除对扩展的支持，新增Any类型，有点想C++中的void*，好理解，使用起来逻辑清晰
- 增加了JSON映射特征
- <specifying Field Labels> 
	- `optional`:
	- `repeated`:
	- `map`:
- `reserved fields`:
	- reserved 2,3,9 to 11
	- reserved "foo", "bar"
- 

## proto3新特征
- Oneof枚举字段
- Oneof嵌入Message字段
- Map字段
- Any
- Oneof
- 枚举
- 服务
- 接口
- Stub
- 

# 3 ProtoBuf反射原理和使用

## 3.1 概念
所谓反射机制就是能够在运行时知道任意类的所有属性和方法，能够调用任意对象的任意方法和属性。这种动态获取的信息以及动态调用对象方向的功能称为反射机制。

如果用一句话来总结反射实现的关键，可概括为获取系统元信息。

元信息：即系统自描述信息，用于描述系统本身。举例来讲，即系统有哪些类？类中有哪些字段、哪些方法？字段属于什么类型、方法又有怎样的参数和返回值。 

## 3.2 应用场景

Protobuf是一种常见的数据序列化方式，常常用于后台微服务之间传递数据。

- 在处理ProtoBuf Message数据时，经常需要根据一个输入的字符串，读取Message中对应属性的取值，并修改取值；
- 或者给定一个ProtoBuf对象，如何自动遍历该对象的所有字段，将其转换为json格式；
- 或者在Bigtable中根据pb对象的字段自动写填写列名和对应的value。


在写代码时，经常会遇到一些丑陋的、圈复杂度较高、较难维护的关于 PB 的使用代码：

- 对字段的必填校验硬编码在代码中：如果需要变更校验规则，则需要修改代码
- 一个字段一个 if 校验，复杂度较高：对传进来的字段每个字段都进行多种规则校验，例如长度，XSS，正则校验等。
- 想要获取 PB 中所有的非空字段，形成一个 map<string,string>，需要大量的 if 判断和重复代码；
- 在后台服务间传递数据，由于模块由不同的人开发，导致相同字段的命名不一样，从一个 PB 中挑选一部分内容到另外一个 PB 中，需要大量的 GET 和 SET 代码。

## 3.3 调用message的属性和方法

1. 通过 DescriptorPool 的 FindMessageTypeByName 获得了元信息 Descriptor。
2. 根据 MessageFactory 实例工厂和Descriptor获得了Message的默认实例Message*指针 default instance
3. 通过new()构造一个可用的消息对象

### 3.3.1 根据type name反射自动创建实例

通过字符串"person" 创建新的 person message对象。线程安全
	
	 // 先获得类型的Descriptor .
	auto descriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName("Person");
	//利用Descriptor拿到类型注册的instance. 这个是不可修改的.
	auto prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
	 // 构造一个可用的消息.
	auto instance = prototype->New(); //创建新的 person message对象。

## 3.4 通过实例instance 的反射接口reflection对其pb字段读写

Reflection主要提供了动态读写 message对象字段的接口，对message对象的自动读写主要通过该类完成。

对每种数据类型，Reflection都提供了一个单独的接口（Get、Set）用于读写字段对应的值
例如对 int32、int64的读操作：输入参数为Message和FieldDescriptor*
	
	  virtual int32  GetInt32 (const Message& message,const FieldDescriptor* field) const = 0;
	  virtual int64  GetInt64 (const Message& message, const FieldDescriptor* field) const = 0;

特殊的，对于枚举和嵌套的message：

	virtual const EnumValueDescriptor* GetEnum( const Message& message, const FieldDescriptor* field) const = 0;
	virtual const Message& GetMessage(const Message& message,
	                                    const FieldDescriptor* field,
	                                    MessageFactory* factory = NULL) const = 0;

	.proto
	enum PackType {
		SCHOOL = 0;
		HOME = 1;
	}

	message PackSection {
		PackType type = 1;
	}

	Message* message = cur_message; 此时，cur_message就是指PackageSection这个message
	std::string key = "type";
	std::string value = "HOME"
	auto field_descriptor = message->GetDescriptor()->FindFieldByLowercaseName(key); // 这个时候，就获得了有关type的域描述信息
	auto enum_descriptor = field_descriptor->enum_type(); // 获得EnumDescriptor描述信息
	auto value_descriptor = enum_descriptor->FindValueByName(value); // 根据这个枚举的字符串，转化为枚举值的描述信息
	message->GetReflection()->SetEnum(message, field_descriptor, value_descriptor); // 最终通过反射机制的SetEnum将字符串的描述信息转化为枚举值，实现枚举值的回填

	【备注】
	若枚举值中有非标准的连接符号，如+，*等，可以在定义proto时，统一改为_,而在使用反射机制时，先将+或*的特殊符号转化为_，
    而后再通过GetDescriptor()->FindFieldByLowerName(字符串名字)获得对应的描述对象，从而获得反射对象的FieldDescriptor，
	在有该对象的CPP_TYPE，找到对应的Add*，或Set*函数，并添加对应的value值。如下所示：
		message->GetReflection()->SetString(message, field_descriptor, value); // 最终通过反射机制的SetEnum将字符串的描述信息转化为枚举值，实现枚举值的回填
	主要注意区分：repeated属性，如下
		if (field->is_repeated())
			message->GetReflection()->AddString(message, field_descriptor, value);
		else
			message->GetReflection()->SetString(message, field_descriptor, value);
	具有repeated属性的字段，需要使用Add函数系列，而只有一个的就用Set函数系列。


对于写操作也是类似的接口，例如SetInt32/SetInt64/SetEnum等


	void SetInt32(Message * message, const FieldDescriptor * field, int32 value) const
	void SetString(Message * message, const FieldDescriptor * field, std::string value) const


获取重复字段的函数如下：
	
	int32 GetRepeatedInt32(const Message & message, const FieldDescriptor * field, int index) const
	std::string GetRepeatedString(const Message & message, const FieldDescriptor * field, int index) const
	const Message & GetRepeatedMessage(const Message & message, const FieldDescriptor * field, int index) const

获取反射Reflection接口，并且值写入的代码如下：线程安全

	auto reflecter = instance.GetReflection();//2.1通过字符串"Person"取得的实例instance
	auto field = descriptor->FindFieldByName("name"); // Person这个Message 中有name字段
	reflecter->SetString(&instance, field, "小明") ; //反射来设置name字段


通过instance可以获得该实例的反射，该反射可以通过SetString来设置，指定实例，指定field的字段内容。而该field由descriptor通过FindFieldByName获得，第三个参数就是字段需要更新的value值。

## 3.5反射的例子

serialize_message函数遍历提取message中所有字段以及对应的值，序列化到string中。主要思路就是：

Descriptor得到每个字段的描述符FieldDescriptor：字段名、字段的cpp类型。
通过Reflection的GetXXX接口获取对应的value。



- 类 FieldDescriptor 介绍

类 FieldDescriptor 的作用主要是对 Message 中单个字段进行描述，包括字段名、字段属性、原始的 field 字段等。

其获取自身信息的函数：

	const std::string & name() const; // Name of this field within the message.
	const std::string & lowercase_name() const; // Same as name() except converted to lower-case.
	const std::string & camelcase_name() const; // Same as name() except converted to camel-case.
	CppType cpp_type() const; //C++ type of this field.


其中cpp_type()函数是来获取该字段是什么类型的，在 protobuf 中，类型的类目如下：
	
	enum FieldDescriptor::Type {
	  TYPE_DOUBLE = = 1,
	  TYPE_FLOAT = = 2,
	  TYPE_INT64 = = 3,
	  TYPE_UINT64 = = 4,
	  TYPE_INT32 = = 5,
	  TYPE_FIXED64 = = 6,
	  TYPE_FIXED32 = = 7,
	  TYPE_BOOL = = 8,
	  TYPE_STRING = = 9,
	  TYPE_GROUP = = 10,
	  TYPE_MESSAGE = = 11,
	  TYPE_BYTES = = 12,
	  TYPE_UINT32 = = 13,
	  TYPE_ENUM = = 14,
	  TYPE_SFIXED32 = = 15,
	  TYPE_SFIXED64 = = 16,
	  TYPE_SINT32 = = 17,
	  TYPE_SINT64 = = 18,
	  MAX_TYPE = = 18
	}


serialize_message遍历提取message中****所有字段以及对应的值代码如下：



	void serialize_message(const google::protobuf::Message& message, std::string* serialized_string) {
	    //获取描述Descriptor*和反射Reflection*
	    const google::protobuf::Descriptor* descriptor = message.GetDescriptor();
	    const google::protobuf::Reflection* reflection = message.GetReflection();
	     
	    //遍历消息的所有字段  
	    for (int i = 0; i < descriptor->field_count(); ++i) {
	        // 获得单个字段的描述FieldDescriptor*
	        const google::protobuf::FieldDescriptor* field = descriptor->field(i);
	        bool has_field = reflection->HasField(message, field);
	        
	        if (has_field) {
	            //arrays not supported
	            assert(!field->is_repeated());
	            switch (field->cpp_type()) {
	            //宏定义 CASE_FIELD_TYPE(cpptype, method, valuetype) 写case
	#define CASE_FIELD_TYPE(cpptype, method, valuetype)\
	                case google::protobuf::FieldDescriptor::CPPTYPE_##cpptype:{\
	                    valuetype value = reflection->Get##method(message, field);\
	                    int wsize = field->name().size();\
	                    serialized_string->append(reinterpret_cast<char*>(&wsize), sizeof(wsize));\
	                    serialized_string->append(field->name().c_str(), field->name().size());\
	                    wsize = sizeof(value);\
	                    serialized_string->append(reinterpret_cast<char*>(&wsize), sizeof(wsize));\
	                    serialized_string->append(reinterpret_cast<char*>(&value), sizeof(value));\
	                    break;\
	                }
	
	                // 利用宏定义 CASE_FIELD_TYPE 写所有简单数据类型的case
	                CASE_FIELD_TYPE(INT32, Int32, int);
	                CASE_FIELD_TYPE(UINT32, UInt32, uint32_t);
	                CASE_FIELD_TYPE(FLOAT, Float, float);
	                CASE_FIELD_TYPE(DOUBLE, Double, double);
	                CASE_FIELD_TYPE(BOOL, Bool, bool);
	                CASE_FIELD_TYPE(INT64, Int64, int64_t);
	                CASE_FIELD_TYPE(UINT64, UInt64, uint64_t);
	#undef CASE_FIELD_TYPE
	                case google::protobuf::FieldDescriptor::CPPTYPE_ENUM: {
	                    int value = reflection->GetEnum(message, field)->number();
	                    int wsize = field->name().size();
	                    //写入name占用字节数
	                    serialized_string->append(reinterpret_cast<char*>(&wsize), sizeof(wsize));
	                    //写入name
	                    serialized_string->append(field->name().c_str(), field->name().size());
	                    wsize = sizeof(value);
	                    //写入value占用字节数
	                    serialized_string->append(reinterpret_cast<char*>(&wsize), sizeof(wsize));
	                    //写入value
	                    serialized_string->append(reinterpret_cast<char*>(&value), sizeof(value));
	                    break;
	                }
	                case google::protobuf::FieldDescriptor::CPPTYPE_STRING: {
	                    std::string value = reflection->GetString(message, field);
	                    int wsize = field->name().size();
	                    serialized_string->append(reinterpret_cast<char*>(&wsize), sizeof(wsize));
	                    serialized_string->append(field->name().c_str(), field->name().size());
	                    wsize = value.size();
	                    serialized_string->append(reinterpret_cast<char*>(&wsize), sizeof(wsize));
	                    serialized_string->append(value.c_str(), value.size());
	                    break;
	                }
	                //递归 序列化 嵌套Message
	                case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE: {
	                    std::string value;
	                    int wsize = field->name().size();
	                    serialized_string->append(reinterpret_cast<char*>(&wsize), sizeof(wsize));
	                    serialized_string->append(field->name().c_str(), field->name().size());
	                    const google::protobuf::Message& submessage = reflection->GetMessage(message, field);
	                    serialize_message(submessage, &value);
	                    wsize = value.size();
	                    serialized_string->append(reinterpret_cast<char*>(&wsize), sizeof(wsize));
	                    serialized_string->append(value.c_str(), value.size());
	                    break;
	                }
	            }
	        }
	    }
	}


# 4反射机制

# 4.1 Message

一般使用通过Message的两个接口GetDescriptor/GetReflection，可以获取该类型对应的Descriptor/Reflection。

	const google::protobuf::Reflection* pReflection = pMessage->GetReflection();
	const google::protobuf::Descriptor* pDescriptor = pMessage->GetDescriptor();
	const ::google::protobuf::Descriptor* pDescriptor =
	      google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(msg_name);

# 4.2 Descriptor

Descriptor是对message类型定义的描述，包括message的名字、所有字段的描述、原始的proto文件内容等。  
在类 Descriptor 中，可以通过如下方法获取类 FieldDescriptor：


	const FieldDescriptor* field(int index) const; // 根据定义顺序索引获取，即从0开始到最大定义的条目
	const FieldDescriptor* FindFieldByNumber(int number) const; // 根据定义的message里面的顺序值获取（option string name=3，3即为number）
	const FieldDescriptor* FindFieldByName(const string& name) const; // 根据field name获取
	const FieldDescriptor* Descriptor::FindFieldByLowercaseName(const std::string & lowercase_name)const; // 根据小写的field name获取
	const FieldDescriptor* Descriptor::FindFieldByCamelcaseName(const std::string & camelcase_name) const; // 根据驼峰的field name获取

# 4.3 FieldDescriptor

FieldDescriptor描述message中的单个字段，例如字段名，字段属性(optional/required/repeated)等。  
对于proto定义里的每种类型，都有一种对应的C++类型
	
	const std::string & name() const; // Name of this field within the message.
	CppType cpp_type() const; //C++ type of this field.
	bool is_required() const; // 判断字段是否是必填
	bool is_optional() const; // 判断字段是否是选填
	bool is_repeated() const; // 判断字段是否是重复值
	int number() const; // Declared tag number.
	int index() const; //Index of this field within the message's field array, or the file or extension scope's extensions array.


# 4.4 Reflection
Reflection主要提供了动态读写pb字段的接口，对pb对象的自动读写主要通过该类完成

读操作和嵌套的message：

	
	virtual int32  GetInt32 (const Message& message, const FieldDescriptor* field) const = 0;
	virtual int64  GetInt64 (const Message& message, const FieldDescriptor* field) const = 0;
		  // See MutableMessage() for the meaning of the "factory" parameter.
	virtual const Message& GetMessage(const Message& message, 
									  const FieldDescriptor* field, 
									  MessageFactory* factory = NULL) const = 0;

对于写操作也是类似的接口，例如SetInt32/SetInt64/SetEnum等。

	void SetInt32(Message * message, const FieldDescriptor * field, int32 value) const


读repeated类型字段：

	int32 GetRepeatedInt32(const Message & message, const FieldDescriptor * field, int index) const
	std::string GetRepeatedString(const Message & message, const FieldDescriptor * field, int index) const
	const Message & GetRepeatedMessage(const Message & message, const FieldDescriptor * field, int index) const

写repeated类型字段：

	void SetRepeatedInt32(Message * message, const FieldDescriptor * field, int index, int32 value) const
	void SetRepeatedString(Message * message, const FieldDescriptor * field, int index, std::string value) const
	void SetRepeatedEnumValue(Message * message, const FieldDescriptor * field, int index, int value) const // Set an enum field's value with an integer rather than EnumValueDescriptor. more..


新增重复字段

	void AddInt32(Message * message, const FieldDescriptor * field, int32 value) const
	void AddString(Message * message, const FieldDescriptor * field, std::string value) const

# 5特征工程使用

 有了上面的知识，我们如何使用到自己的工程中呢。

## 5.1 定义proto文件

首先我们定义一个proto文件test_refactor.proto

	
	syntax = "proto3";
	package test.refactor;
	
	option cc_generic_services = true;
	
	message item_info {    // item 信息 
	    int32 source               = 1;
	    repeated int32 newsTypes   = 2;
	    string name = 3;
	};
	
	message user_info {    // 用户信息
	    int32 type           = 1;
	    repeated int32 sex   = 2;
	    string imei = 3;
	};
	
	message item_req {
	    item_info item = 1;
	    user_info user = 2;
	};
	
	message refactor_reqs {
	    item_req req = 1;
	}

- 业务场景是所有的特征都包括在message的refactor_reqs中，利用这个message我们可以获取到对应的Descriptor

	const ::google::protobuf::Descriptor* descriptor =
      google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName("test.refactor.refactor_reqs");


- 获取对应field，通过name获取对应需要获取的FieldDescriptor，如获取item信息的数据，写为req.item

	field_descriptor = descriptor->FindFieldByName(“item”);

- 最终每次获取的时候，我们获取的数据都是填充到test::refactor::refactor_reqs refactor_reqs中。


## 5.2 

代码（略），见工程Demo/TestProto3

# 6 反射的两种主要用途

# 6.1 通过proto对象的名字来创建一个对象(json→pb)

即通过proto对象的完整字符串路径，可以创建一个对象，并根据field的名字对数据进行读写操作，实现从json到pb的转化。


	#include <iostream>
	#include <string>
	#include "person.pb.h"
	 
	using namespace std;
	 
	/*
	    Descriptor/FieldDescriptor位于descriptor.h文件;
	    Message/Reflection 位于message.h文件
	    以上四个类都位于 namespace google::protobuf下.
	*/
	using namespace google::protobuf;
	 
	typedef tencent::Person T;
	 
	Message* createMessage(const std::string& typeName);
	 
	int main()
	{
		//通过Descriptor类的full_name函数获取相应结构的type_name
		std::string type_name = T::descriptor()->full_name();
	    cout << "type_name:" << type_name << endl;
	 
	 
	    //根据type name创建相应的message对象 new_person
	    Message* new_person = createMessage(type_name);
	    assert(new_person != NULL);//指针为null向stderr打印一条信息
	    assert(typeid(*new_person) == typeid(tencent::Person::default_instance()));
	    cout << "new_person:" << new_person->DebugString() << endl;
	 
	 
	    //接下来使用DescriptorPool类的FindMessageTypeByName方法通过type_name查到元信息Descriptor*
	    const Descriptor* descriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(type_name);
		cout << "FindMessageTypeByName() = " << descriptor << endl;
		cout << "T::descriptor()         = " << T::descriptor() << endl;
		cout << endl;
	 
		// 再用MessageFactory::generated_factory() 找到 MessageFactory 对象
		const Message* prototype = MessageFactory::generated_factory()->GetPrototype(descriptor);
		cout << "GetPrototype()        = " << prototype << endl;
	    cout << "T::default_instance() = " << &T::default_instance() << endl;
	    cout << endl;
	 
	    //再然后我们实例化出一个实例
	    //dynamic_cast:将基类的指针或引用安全第一转换成派生类的指针或引用，并用派生类的指针或引用调用非虚函数。
	    T* new_obj = dynamic_cast<T*>(prototype->New());
	    cout << "prototype->New() = " << new_obj << endl;
	    cout << endl;
	 
	    /*--------接下来看看反射接口怎么用--------*/
	    //获取这个message的反射接口指针
	    const Reflection* reflecter = new_obj->GetReflection();
	 
	    //通过name查找filed
	    const FieldDescriptor* field = descriptor->FindFieldByName("name");
	 
	    //设置这个field的字段值
	    std::string str1 = "shuozhuo";
	    reflecter->SetString(new_obj, field, str1);
	 
	    //取出这个field的值
	    std::cout << "\"name\" field is:" << reflecter->GetString(*new_obj,field)<< std::endl;
	}
	 
	 
	/*
	    本函数的作用就是根据type name 自动创建具体的protobuf message对象;
	*/
	Message* createMessage(const std::string& typeName)
	{
	  Message* message = NULL;
	  const Descriptor* descriptor = DescriptorPool::generated_pool()->FindMessageTypeByName(typeName);
	  if (descriptor)
	  {
	    const Message* prototype = MessageFactory::generated_factory()->GetPrototype(descriptor);
	    if (prototype)
	    {
	      message = prototype->New();
	    }
	  }
	  return message;
	}



# 6.2 通过Message初始化和获取成员变量的值(pb→json)

这个工作就是需要将2581C的数据转换成xml文件，此处用了到反射机制。

1、MessageLite类

所有message的接口类，从名字看就是lite的message，普通的message也是他的子类。

MessageLite是和“轻量级”的message(仅仅提供encoding+序列化,没有reflection和descriptors)。在确定可以使用“轻量级”message的场景下，可以在.proto文件中增加配置（option optimize_for = LITE_RUNTIME;），来让protocol compiler产出MessageLite类型的类，这样可以节省runtime资源。

注：lite 低热量的、淡的、轻量级的。

2、Message类

接口类，在MessageLite类的基础上增加了descriptor和reflection。

3、MessageFactory类

接口类，来找到MessageFactory对象，他能创建程序编译的时候所链接的全部protobuf Message types。其提供的GetPrototype方法可以找到具体的Message Type的default instance。  底层封装了GeneratedMessageFactory类。

4、DescriptorPool类

用 DescriptorPool::generated_pool() 找到一个 DescriptorPool 对象，它包含了程序编译的时候所链接的全部 protobuf Message types。然后通过其提供的 FindMessageTypeByName 方法即可根据type name 查找到Descriptor。

5、GeneratedMessageFactory类

继承自MessageFactory，singleton模式。

6、Descriptor类

描述一种message的meta信息(注意:不是单独的message对象)。构造函数是private类型，必须通过DescriptorPool(friend类)来构造。
 
const成员
	
	const FileDescriptor* file_： 描述message所在的.proto文件信息
	const Descriptor* containing_type_：如果在proto定义中，这个message是被其它message所包含，那么这个字段是上一级message的descriptor*；如果没有被包含，那么是NULL
	const MessageOptions* options_： 定义在descriptor.proto，从注释看是用来和老版本proto1中MessageSet做拓展，可以先不去关注涉及extension的部分。

非const成员如下：

	int field_count_：当前field包含的field的个数
	FieldDescriptor* fields_： 以连续数组方式保存的所有的fieds
	int nested_type_count_: 嵌套类型数量
	Descriptor* nested_types_: message中嵌套message
	int enum_type_count_： 内部enum的个数
	EnumDescriptor* enum_types_： enum类型的连续内存起始地址

7、FileDescriptor类

描述整个.proto文件信息，其中包含：

	1、依赖.proto文件信息：
	int dependency_count_;
	const FileDescriptor** dependencies_;
	 
	2、当前.proto文件包含的message信息：
	int message_type_count_;
	Descriptor* message_types_;
	 
	3、当前.proto文件包含的所有symbol(各种discriprot)的tables：
	const FileDescriptorTables* tables_;

8、FileDescriptor类

描述一个单独的field，构造函数为private，也必须由DescriptorPool(friend类)构造。通过包含这个field的message的descriptor的函数（Descriptor::FindFieldByName()）获得。

9、EnumDescriptor类

描述在.proto文件中定义的enum类型

# 7 额外函数

# 7.1 打印


	#include "google/protobuf/text_format.h"
	cout << "----------print------------" << endl;
	Message *test;
  	std::string new_str;
  	google::protobuf::TextFormat::PrintToString(*test, &new_str);
  	std::cout<< new_str <<std::endl;

	

# 8 生成稳定的库

## 8.1 vcpkg

- 生成x86静态md版本
`vcpkg install protobuf:x86-windows-static-md`
- 生成x86静态mt版本
`vcpkg install protobuf:x86-windows-static`
- 生成x86动态版本
`vcpkg install protobuf`

[推荐参考资料](https://blog.csdn.net/what951006/article/details/115360430)



# 9 参考
[ProtoBuf-反射原理与使用](https://blog.csdn.net/h2517956473/article/details/117387877)

[protobuf反射详解及应用(pb/json相互转换)](https://blog.csdn.net/mijichui2153/article/details/111665192)

[C++ protobuf反射特征工程正确姿势](https://blog.csdn.net/qq_18447271/article/details/127844677)

[Protobuf反射详解](http://www.p-chao.com/2017-09-04/protobuf%E5%8F%8D%E5%B0%84%E8%AF%A6%E8%A7%A3/)

[Protobuf： C++ 产生的代码简析（Proto3）](https://blog.csdn.net/baidu_32237719/article/details/100034758)

[protobuf反射详解](https://blog.csdn.net/chary8088/article/details/52876674)

[protobuf反射详解(c++)](https://www.jianshu.com/p/ec25a0a9a539)

[C++ 实用技术 - google protobuf反射技术 - 基础API](https://blog.csdn.net/yindongjie1221/article/details/90575989)

[C++ Descriptor::field方法代码示例](https://vimsky.com/examples/detail/cpp-ex---Descriptor-field-method.html)

[Language Guide (proto 3)](https://protobuf.dev/programming-guides/proto3/)

[Protocol Buffers Documentation](https://protobuf.dev/reference/cpp/api-docs/)

[protobuf c++ 使用map笔记](https://bbs.csdn.net/topics/606679437)
