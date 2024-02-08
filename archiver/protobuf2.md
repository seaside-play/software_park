 
# proto

将IPC-2581C的简单类型中的枚举值用proto中的enum值来映射

在xsd中的属性，可以对应类的成员变量，就是message中的一项

IPC-2581C中先定义了simpleType和complexType


# protobuf的使用

通过GetDescriptor获得描述符，在通过描述符查找名字对应的类描述，通过反射，构成该类的创建；

创建类之后，就可以往里面填写内容啦；

message的所获得反射，就像类对象，可以