- Q1：编译wxPython失败
- A1：从网上下载指定的python11.5版本，没有找到就使用python11.6版本，并安装上pip，之后再打开虚拟环境；
就可以正常下载wxPython，并正常编译了

- Q2：CMake Error at C:/Program Files/CMake/share/cmake-3.28/Modules/FindPackageHandleStandardArgs.cmake:230 (message):
  Could NOT find SWIG (missing: SWIG_EXECUTABLE SWIG_DIR) (Required is at
  least version "4.0")
Call Stack (most recent call first):
  C:/Program Files/CMake/share/cmake-3.28/Modules/FindPackageHandleStandardArgs.cmake:600 (_FPHSA_FAILURE_MESSAGE)
  cmake/FindSWIG.cmake:93 (FIND_PACKAGE_HANDLE_STANDARD_ARGS)
  C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake:859 (_find_package)
  CMakeLists.txt:867 (find_package)

- A2: 下载win版本的最新SWIG，然后将SWIG_EXECUTABLE SWIG_DIR这两个宏变量对应的swig.exe 所在的目录和文件路径指定到cmake中即可


- Q3：CMake Error at cmake/CheckFindPackageResult.cmake:6 (message):
  Python Interpreter was not found - it is required to build Kicad
Call Stack (most recent call first):
  CMakeLists.txt:875 (check_find_package_result)

- A3: 设置环境变量：
PYTHONHOME C:\Users\wisechip\Desktop\kicad_8.0\build\vcpkg_installed\x64-windows\tools\python3
PYTHONPATH C:\Users\wisechip\Desktop\kicad_8.0\build\vcpkg_installed\x64-windows\tools\python3\python.exe


- Q4: 2>Creating python's pcbnew native module _pcbnew.pyd for command line use.
2>Error copying file "_pcbnew.dll" to "_pcbnew.pyd".
2>C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Microsoft\VC\v160\Microsoft.CppCommon.targets(241,5): error MSB8066: “C:\Users\wisechip\Desktop\kicad_8.0\build\CMakeFiles\f039cab5bb4438dc372fc0b7650b81da\_pcbnew.pyd.rule;C:\Users\wisechip\Desktop\kicad_8.0\build\CMakeFiles\1a95127c93f27bcdc1147a1af274282c\pcbnew_python_module.rule”的自定义生成已退出，代码为 1。
2>已完成生成项目“pcbnew_python_module.vcxproj”的操作 - 失败。
==

- A4: CMAKE_BUILD_TYPE为Release之后，generate visual studio solution之后，即便是debug模式下，
其CMAKE_BUILD_TYPE仍然为release（这个和VS的项目配置会存在不一致性）

  line：859，改成如下就可以了
  elseif( WIN32 )
      # For phase 1, copy _pcbnew.kiface to the python module.
    add_custom_command( OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/_pcbnew.${PYMOD_EXT}
        DEPENDS pcbnew_kiface
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/debug/_pcbnew${KIFACE_SUFFIX} ${CMAKE_CURRENT_BINARY_DIR}/debug/_pcbnew.${PYMOD_EXT}
        COMMENT "Creating python's pcbnew native module _pcbnew.${PYMOD_EXT} for command line use."
        )


   我注意到你在提问中有一个小错误：应该是add_custom_command，而不是add_custome_command。add_custom_command是CMake中的一个命令，用于添加自定义构建规则。这个命令允许你在构建过程中执行自定义的命令，比如生成源文件、执行前后处理步骤、自动化测试等。我注意到你在提问中有一个小错误：应该是add_custom_command，而不是add_custome_command。add_custom_command是CMake中的一个命令，用于添加自定义构建规则。这个命令允许你在构建过程中执行自定义的命令，比如生成源文件、执行前后处理步骤、自动化测试等。

- Q5：缺少rt.lib
- A5:  
      点击编译ALL_BUILD，就可以了，之后点击INSTALL，进行安装处理。


- Q6：Microsoft.CppCommon.targets(155,5): error MSB3073: 命令“setlocal
Microsoft.CppCommon.targets(155,5): error MSB3073: "C:\Program Files\CMake\bin\cmake.exe" -DBUILD_TYPE=Debug -P cmake_install.cmake
Microsoft.CppCommon.targets(155,5): error MSB3073: if %errorlevel% neq 0 goto :cmEnd
Microsoft.CppCommon.targets(155,5): error MSB3073: :cmEnd
Microsoft.CppCommon.targets(155,5): error MSB3073: endlocal & call :cmErrorLevel %errorlevel% & goto :cmDone
Microsoft.CppCommon.targets(155,5): error MSB3073: :cmErrorLevel
Microsoft.CppCommon.targets(155,5): error MSB3073: exit /b %1
Microsoft.CppCommon.targets(155,5): error MSB3073: :cmDone
Microsoft.CppCommon.targets(155,5): error MSB3073: if %errorlevel% neq 0 goto :VCEnd
Microsoft.CppCommon.targets(155,5): error MSB3073: :VCEnd”已退出，代码为 1。


- A6: 
  
      file(INSTALL DESTINATION "C:/Program Files (x86)/kicad/bin/Lib/site-packages" TYPE FILE FILES "C:/Users/wisechip/Desktop/kicad_8.0/build/pcbnew/_pcbnew.pyd")

      在CMake中，file(INSTALL ...)命令用于指定如何安装由构建过程生成的文件或目录。在你给出的例子中，这个命令的目的是安装一个文件到指定的目标位置。

      具体解释如下：

      INSTALL: 这是file命令的一个参数，表示要执行安装操作。
      DESTINATION "C:/Program Files (x86)/kicad/bin/Lib/site-packages": 指定安装的目标位置。在这个例子中，文件将被安装到C:/Program Files (x86)/kicad/bin/Lib/site-packages这个目录下。
      TYPE FILE: 指定要安装的对象类型，这里是文件（FILE）。
      FILES "C:/Users/wisechip/Desktop/kicad_8.0/build/pcbnew/_pcbnew.pyd": 指定要安装的文件路径。这里是要安装的文件的完整路径，即_pcbnew.pyd，它位于C:/Users/wisechip/Desktop/kicad_8.0/build/pcbnew/目录下。
      综上所述，这个file(INSTALL ...)命令的作用是将_pcbnew.pyd文件从C:/Users/wisechip/Desktop/kicad_8.0/build/pcbnew/目录安装到C:/Program Files (x86)/kicad/bin/Lib/site-packages目录。这通常是在构建KiCad或相关插件时的一部分，用于将生成的扩展模块安装到KiCad可以找到的位置。

将 _pcbnew.pyd copy到指定目录下，就可以啦


Q7：ALL_BUILD和INSTALL成功之后，点击“本地调试器”，出现0x00007FFFED73CF19 处(位于 kicad.exe 中)引发的异常: Microsoft C++ 异常: nlohmann::json_abi_v3_11_3::detail::parse_error，位于内存位置 0x000000DB4FD0C040 处。
Fatal Python error: failed to get the Python codec of the filesystem encoding

A7：

[https://lists.launchpad.net/kicad-developers/msg45177.html](https://lists.launchpad.net/kicad-developers/msg45177.html)
[https://dev-docs.kicad.org/en/build/windows-msvc/](https://dev-docs.kicad.org/en/build/windows-msvc/)

