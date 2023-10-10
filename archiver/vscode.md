# 环境搭建

- 配置MinGW-64 [standalone build](https://winlibs.com/)  
下载相应系统的版本之后，将`mingw64\bin`目录添加到系统环境中，打开cmd 运行 `gcc -v`，若看到有效结果，说明`MinGW-64`生效

- 搜索插件
  - chinese(simplified)
  - C/C++
  - Code Runner 
    - 解决输出可执行的问题：在Code Runner中`Extension Settings\Code-runner: Executor Map\Edit in settings.json`下，添加.\\build\\
 
            "c": "cd $dir && gcc $fileName -o .\\build\\$fileNameWithoutExt && .\\build\\$fileNameWithoutExt",
            "cpp": "cd $dir && g++ $fileName -o .\\build\\$fileNameWithoutExt && .\\build\\$fileNameWithoutExt",

    取保对源文件编译后，在build中产生可执行文件

- 小记
  - Architecture： 电脑是64位，选x86_64, 电脑是32位，选i686
  - Threads：posix兼容性更好（推荐），win32更快速
  - Exception：32位选sjlj，64位选seh性能更好

