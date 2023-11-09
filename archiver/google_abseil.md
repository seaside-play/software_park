# 1 简介

以下内容来源于[Google Abseil 用 C++ 11 的代码实现了许多 C++ 14 和 C++ 17 的特性](https://zhuanlan.zhihu.com/p/29940200)

https://zhuanlan.zhihu.com/p/29940200

最近 Google 开源了其内部多年使用的 C++ 代码库 Abseil 作为 C++ 标准库的补充，并会对其进行持续更新，本文对其进行简要介绍。

一句话概括，这个库的特点是用 C++ 11 的代码实现了许多 C++ 14 和 C++ 17 的特性，所以你的编译器也要支持 C++ 11（gcc 4.8+/clang 3.3+，不同平台略有差异）。

需要注意一点的是 Google 内部代码是不支持异常（Excepton）的，C++ 异常的优劣之处有许多讨论（知乎上的讨论），不用异常可以在一定程度上利于编译器优化，这里主要可能还是历史支持原因。如果你的项目是支持异常的建议要好好测试一下，具体参考下 abseil / Abseil Fundamentals 。

Abseil 简要组成部分如下：

base Abseil Fundamentals ：包含初始化代码和其它部分依赖的代码。除了 C++ 标准库外不依赖外部代码
algorithm ：C++ 库的增强
container ：STL 风格容器
debugging ：内存泄露检查
memory ：智能指针和内存管理
meta ：用 C++11 兼容代码支持 C++14 和 C++17 版本的 <type_traits> 库
numeric ：支持 C++11 兼容的 128 位整数
strings ：string 相关函数增强
synchronization ：同步原语和抽象支持
time ：时间方面的计算
types ：非容器类型的工具类型

一些使用要点：

不要使用编译版本的库，不保证 ABI 二进制级别的兼容
不会频繁更新 API 接口，如果更新会提供工具，请使用工具或指导进行更新（毕竟谷歌内部的代码库有超过250M行，不可能全部手动更新）
共享库的 dynamic unloading 可能不被支持，同时不是所有代码都支持动态载入
尽量使用命名空间前缀 absl
支持基本的异常，但自定义的异常可能不被完整支持
至少五年的支持（哈哈，想起了 google reader)
需要使用 Bazel （类似于CMake，最早是用来支持 TensorFlow 开发的工具）进行编译，这个可能会影响现有代码的构建方式
另外 Google 还开源了一份 python 代码库 abseil-py 。

更多内容参见如下链接：

[1] 选择 abseil 的原因

[2] 兼容性指导

[3] abseil / Design Notes ：设计理念，现在还只有两篇文章，后续应该会更新

[4] https://abseil.io/tips/ : 这里会每周介绍一些谷歌内容的 C++ tips


Abseil 是 Google 开源的 C++ 库，旨在提供高质量、可靠且易于使用的基础设施组件。它由多个模块组成，涵盖了广泛的功能和领域，包括字符串处理、并发编程、日志记录、时间处理等。以下是 Abseil 的主要特点和组件：

1.字符串库：Abseil 提供了一套强大而灵活的字符串处理工具，包括字符串拼接、分割、查找、替换等常用操作，以及基于模式匹配的功能。

2.并发库：Abseil 提供了各种并发编程的工具和原语，包括互斥锁、条件变量、原子操作等，帮助开发人员编写高效且线程安全的并发代码。

3.容器库：Abseil 包含了一系列高性能的容器类型，如 flat_hash_map、flat_hash_set、InlinedVector 等，用于管理数据集合并提供高效的访问和操作。

4.日志库：Abseil 提供了灵活的日志记录功能，支持多级别的日志消息、消息格式化、日志过滤等，方便开发人员进行调试和错误追踪。

5.时间库：Abseil 提供了可靠且易于使用的时间处理工具，包括时钟类型、时间间隔计算、日期时间格式化等，满足日常的时间操作需求。

6.效用库：Abseil 包含了许多实用的小工具和功能，如命令行解析器、随机数生成器、文件操作等，简化了常见任务的编码过程。

7.测试框架：Abseil 提供了全面而强大的测试框架，包括单元测试、性能测试和基准测试等，方便开发人员进行代码测试和性能优化。

Abseil 遵循现代 C++ 的最佳实践，注重代码的易读性、可维护性和高性能，已被广泛应用于 Google 内部的项目。（很强）

😊2. 环境配置
下面进行环境配置：

    git clone https://github.com/abseil/abseil-cpp.git

    #include <iostream>
    #include <string>
    #include "absl/strings/str_cat.h"

    int main() {
      std::string str1 = "Hello";
      std::string str2 = "Abseil";
      std::string str3 = "!";
      
      // 使用 absl::StrCat 进行字符串拼接
      std::string result = absl::StrCat(str1, ", ", str2, str3);
      
      // 输出拼接结果
      std::cout << result << std::endl; 
      return 0;
    }


# 2 Windows下配置

# 3 使用

