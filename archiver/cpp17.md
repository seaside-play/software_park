# 1 主要新特性

1. 构造函数模板推导
2. 结构化绑定
3. if-switch语句初始化
4. 内联变量
5. 折叠表达式
6. constexpr lambda表达式
7. namespace嵌套
8. __has_include预处理表达式
9. 在lambda表达式用*this捕获对象副本
10. 新增Attribute
11. 字符串转换
12. std::variant
13. std::optional
14. std::any
15. std::apply
16. std::make_from_tuple
17. as_const
18. std::string_view
19. file_system
20. std::shared_mutex

# 2 详细阐述
## 2.1 构造函数模板推导

# 3 GCC 各个版本的情况

    C++版本	GCC版本支持情况	GCC版本	指定版本的命令标志
    C++98	完全支持	GCC 6.1之前版本的默认模式	
    C++11	完全支持	GCC 4.8.1开始完全支持	-std=c++11 or -std=gnu++11
    C++14	完全支持	GCC 6.1版本开始完全支持，GCC 6.1到GCC 10的默认模式	-std=c++14 or -std=gnu++14
    C++17	完全支持	GCC 5开始支持，GCC 7基本完全支持，GCC 8完全支持。GCC 11的默认模式	-std=c++17 or -std=gnu++17
    C++20	未完全支持	GCC 8开始陆续支持（因该标准较新，故GCC支持都是实验性质的）	-std=c++20 or -std=c++2ag++ or -std=gnu++20
    C++23	未完全支持（标准还在发展中）	GCC 11开始支持（因该标准仍不断发展，故GCC支持都是实验性质的）	-std=c++2bg++ or -std=gnu++2b