1. 根据proto文件生成对应的cpp文件

>protoc.exe --cpp_out=./ test.proto

2. protobuf.rar的使用
由于该文件接占了40多M，所以进行了压缩；
解压当当前文件夹，就可正常编译啦；

3. 无法解析的外部符号 "class google::protobuf::internal::ExplicitlyConstructed
在生成的.pb.h头文件中添加，如下代码
#define PROTOBUF_USE_DLLS

4.ph.h上面添加一下宏
#define PROTOBUF_USE_DLLS