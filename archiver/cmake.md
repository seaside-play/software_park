- cmake_minimum_reuqired(VERSION 3.10 FATAL_ERROR)：表示版本低于3.10时， CMake会立即退出并显示错误消息。

- cmake_policy(SET CMP0116 OLD): SET CMP0116 OLD 表示将CMP0116策略设置为旧的行为（OLD）。
  - cmake_policy作用: 
  
    CMake的策略功能主要是用来保证多个版本之间的后向兼容性。当新版本的CMake在某些特性上有变更时，这些策略确保了已有构建工程能够保持兼容。策略的定义形式是通过CMP<NNNN>形式来唯一定义一个策略，例如CMake的3.23版本定义了从CMP0000到CMP0129等130个策略。  
      
    这意味着CMake将不会采用与该策略相关的新行为，而是会继续使用旧的行为。CMake策略是CMake团队为改进CMake的行为而引入的一种机制。当CMake检测到可能产生混淆或错误的代码模式时，它会发出警告或错误。CMake策略允许用户控制这些警告或错误的行为。

  - 介绍CMP0116

    例如，如果CMake 3.10引入了一个新的策略CMP0116，该策略改变了某个指令或函数的默认行为，并且这种改变可能会影响到现有的CMakeLists.txt文件，那么开发者可以通过在CMakeLists.txt中添加cmake_policy(SET CMP0116 OLD)来显式地指示CMake继续使用旧的行为，从而避免潜在的兼容性问题。

    `CMake策略CMP0116涉及的是对目标属性的处理方式的改变。在CMake的早期版本中，设置目标属性（如链接器选项、编译器选项等）通常没有固定的顺序要求。但是，随着CMake的发展和用户需求的增加，CMake团队决定对目标属性的处理方式进行改进，以确保更一致和可预测的行为。`

    CMP0116策略的具体内容如下：

    在CMake 3.12及更早的版本中，**目标属性（如LINK_FLAGS、COMPILE_FLAGS等）**的添加顺序没有固定的规则。这可能导致一些不易察觉的问题，**特别是当多个地方对同一属性进行设置时。**

    从CMake 3.13开始，CMake引入了一个新的策略来处理目标属性：属性是按照它们被设置的顺序来应用的。这意味着，**如果你在CMakeLists.txt文件中的不同位置设置了同一个属性，那么最后设置的属性将覆盖之前设置的属性。**

    为了保持向后兼容性，CMake引入了CMP0116策略。当该策略设置为OLD时，CMake将使用旧的行为，即不保证目标属性的应用顺序。当该策略设置为NEW时，CMake将使用新的行为，即按照属性设置的顺序来应用它们。

    需要注意的是，策略机制并不是一个可靠的功能开关，也不建议将其设置为OLD以规避新版本中的变更。在将来的版本中，CMake可能会使用错误来替代当前的警告提示，因此最好尽量适应新版本的行为，并对CMakeLists.txt文件进行必要的更新。

  - 介绍CMP0113

    `CMake策略CMP0113涉及的是对find_package命令的改进。在CMake的早期版本中，find_package命令用于查找和加载外部库或工具链。然而，随着CMake的发展，对于find_package的使用和处理方式进行了改进和标准化。`

    CMP0113策略引入了一些变化，旨在改进find_package命令的行为和一致性。具体的改进内容可能包括如何处理找不到的包、如何处理包的版本号、以及如何与其他CMake命令和特性进行交互。

    通过设置CMP0113策略，开发者可以选择使用新的或旧的行为。这有助于在升级CMake版本时保持项目的稳定性和兼容性。**如果项目依赖于旧版本的CMake行为，可以将CMP0113策略设置为OLD，以保留旧的行为。如果项目希望采用新的改进和特性，可以将CMP0113策略设置为NEW。**

    请注意，具体的策略内容和行为可能随着CMake版本的更新而有所变化。因此，建议查阅相关版本的CMake文档以获取关于CMP0113策略的详细信息和最新变化。这将有助于开发者了解该策略的具体内容，并做出适当的设置和决策。

- generate depfiles without transforming relative paths （即CMP0116）

  在CMake中，generate depfiles without transforming relative paths 是一个特定的选项，它通常与`add_custom_command`和`add_custom_target`等命令结合使用，用于生成依赖文件（`depfiles`）。这些依赖文件记录了构建过程中源文件之间的依赖关系，以便在源文件变化时能够正确地重新构建相关的目标。

  当使用这个选项时，CMake会生成依赖文件，但不会转换其中的相对路径。这通常意味着依赖文件中的路径将保持与源文件相同的相对路径格式。这在某些情况下是有用的，比如当源文件和目标文件位于不同的目录，并且你希望保持这些路径的原始形式时。

  这个选项的具体使用方式取决于你的**构建系统和需求**。**一般来说，你可能会在add_custom_command命令中设置这个选项，以便在自定义构建规则中生成依赖文件。**
  - 例如：
  
          add_custom_command(  
              OUTPUT output_file  
              COMMAND some_command input_file  
              COMMAND_OUTPUT_VARIABLE depfiles_var  
              DEPENDS input_file  
              VERBATIM  
              COMMENT "Generating output_file"  
              GENERATE_DEPFILES ON  
              GENERATE_DEPFILES_FLAGS "relative"  
          )

    在这个例子中，GENERATE_DEPFILES ON 指示CMake生成依赖文件，而GENERATE_DEPFILES_FLAGS "relative" 可能用于指示CMake保持相对路径不变（尽管CMake的文档可能没有直接说明relative作为GENERATE_DEPFILES_FLAGS的一个选项；实际上，这个选项可能依赖于CMake的版本和具体实现）。


- add_custom_command有什么用？

  add_custom_command是CMake中的一个重要命令，用于为构建系统添加自定义的构建规则。这个命令的**主要作用是在CMake的生成过程中执行额外的命令或操作，从而扩展了CMake的基本构建功能。**

  add_custom_command命令有两种主要的使用形式：

      1. 生成输出文件：  
      你可以使用这个命令来定义生成指定的输出文件（或文件组）的生成命令。这包括指定输出文件、命令、依赖项以及其他选项。通过这种方式，你可以在CMake构建过程中添加自定义的步骤，例如**代码格式化、生成哈希文件或在修改.proto文件后更新生成的cpp或py文件等**。
      2. 为目标添加命令：  
      你也可以使用这个命令为特定的目标（如**库文件或可执行文件**）添加自定义命令。**这些命令会在构建目标之前或之后执行**。这对于需要在构建目标之前准备某些文件或在构建目标之后执行清理或测试等操作非常有用。

  add_custom_command命令具有许多选项，允许你精细地控制自定义命令的行为。

      例如，
      - APPEND选项： 可以将命令和依赖项附加到指定的输出的自定义命令，
      - BYPRODUCTS选项： 可以指定命令预期生成的文件，等等。

  **总的来说，add_custom_command是一个强大的工具，允许你在CMake构建过程中添加自定义的逻辑和操作，从而满足复杂的构建需求。**

- 在CMake中，set是一个用来显式定义变量的指令。其基本的语法结构为

      set(<variable> <value>... [PARENT_SCOPE] [CACHE <type> <docstring> [FORCE]])

    其中，<variable>是你想要设置的变量名，<value>则是变量的值。PARENT_SCOPE是一个可选参数，如果添加了它，那么变量将在上层作用域/目录被设置，但当前作用域/目录的该变量值不会改变。

    CACHE关键字及其后面的参数是另一种可选参数，它使得**CMake为变量创建一个缓存项**。缓存项旨在提供用户可设置的值，因此默认情况下不会覆盖现有缓存项。<type>指定了缓存项的类型，例如STRING表示这个变量是一个字符串类型的缓存项。<docstring>是对这个变量的描述，它将会显示在CMake的GUI工具中，以便用户了解这个变量的用途。FORCE是一个可选参数，如果设置，它会强制覆盖现有的缓存项。

    至于你提到的CACHE STRING和STRING的区别，它们实际上是set命令中不同部分的参数，它们各自有不同的作用：

    CACHE STRING：这里的CACHE是一个关键字，它告诉CMake这个变量应该被缓存。而STRING则是缓存类



- CMAKE_CXX_FLAGS_QABUILD
  
  在您提供的命令中，似乎有一个小错误：CMAKE_CXX_FALGS 应该是 CMAKE_CXX_FLAGS。CMAKE_CXX_FLAGS 是一个CMake变量，用于设置C++编译器的标志（flags）。

  set(CMAKE_CXX_FLAGS "-Os -g1 -ggdb1") 这行命令的作用是为C++编译器设置编译标志



- CMake module是干什么用的？

    CMake模块在CMake构建系统中具有多种用途，它们主要用于组织和管理构建过程中的代码和配置。以下是CMake模块的一些主要作用：

    - 代码复用和模块化：CMake模块允许你将代码和相关构建指令组织在一起，这样可以在多个项目或目标中重复使用这些模块。这有助于减少重复的代码和配置，提高开发效率。
    - 函数和变量作用域控制：与函数相结合，CMake模块可以帮助限制变量的作用范围，确保在特定上下文中正确地使用变量和函数。
    - 组织构建逻辑：模块可以将复杂的构建逻辑分解为更小的、更易于管理的部分。这使得构建过程更加清晰和可维护。
    - 插件和动态库支持：某些模块，如MODULE库，特别适用于需要插件系统的应用场景。这些模块可以在程序运行时动态加载，为应用程序提供扩展功能的能力。
    - 查找库和依赖项：CMake模块还可以用于查找库和其他依赖项。例如，find_package()命令会在特定的路径中查找已编译好的Find.cmake文件或库的配置文件，以便在构建过程中正确地链接和包含这些库。
    - 自定义构建规则：使用add_custom_command等命令，CMake模块可以定义自定义的构建规则。这对于需要执行特殊构建步骤或生成特定输出文件的项目非常有用。
    总之，CMake模块是CMake构建系统中的重要组成部分，它们为开发者提供了组织和管理构建过程的有效手段，有助于提高项目的可维护性和可重用性。


- cmake中CheckCXXCompilerFlag.cmake的作用是什么？

  在CMake中，CheckCXXCompilerFlag.cmake是一个模块，它提供了用于检查C++编译器是否支持特定编译标志的功能。这个模块通常用于在CMake配置阶段检测编译器的特性，以便在构建过程中根据这些特性调整编译选项。

  具体来说，CheckCXXCompilerFlag.cmake模块定义了一个函数CHECK_CXX_COMPILER_FLAG，该函数接受一个编译标志作为参数，并尝试使用该标志编译一个简单的测试源文件。如果编译成功，则表明编译器支持该标志；如果编译失败，则表明编译器不支持该标志。

  使用CheckCXXCompilerFlag.cmake模块可以帮助你编写更加健壮和可移植的CMake构建脚本。你可以利用它来检测编译器是否支持特定的优化选项、警告选项或其他特性，并据此调整你的构建配置。这有助于确保你的代码在不同编译器和平台上都能够正确地构建和运行。

  下面是一个简单的示例，展示了如何使用CheckCXXCompilerFlag.cmake模块来检查编译器是否支持-Wall标志：

      include(CheckCXXCompilerFlag)  
        
      CHECK_CXX_COMPILER_FLAG("-Wall" CXX_HAS_WALL)  
        
      if(CXX_HAS_WALL)  
          set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")  
      endif()

  在这个示例中，首先通过include命令包含了CheckCXXCompilerFlag.cmake模块。然后，使用CHECK_CXX_COMPILER_FLAG函数来检查编译器是否支持-Wall标志，并将结果存储在CXX_HAS_WALL变量中。最后，根据CXX_HAS_WALL的值来决定是否将-Wall添加到CMAKE_CXX_FLAGS变量中，以便在后续的构建过程中使用。

- cmake中CMakeDependentOption.cmake的作用是什么？

  在CMake中，CMakeDependentOption.cmake是一个模块，它提供了一种机制来创建依赖于其他选项的构建选项。这意味着你可以定义某些选项，它们的可用性或默认值取决于其他选项的状态。

  具体来说，CMakeDependentOption.cmake模块定义了一个函数cmake_dependent_option，它允许你创建一个新的构建选项，并指定它依赖于一个或多个其他选项。当依赖的选项满足特定条件时（例如，被启用或禁用），新选项才会被启用或具有特定的默认值。

  这种机制非常有用，特别是在处理复杂的构建配置时，其中某些选项可能只在其他选项启用或满足特定条件时才相关或有意义。通过使用CMakeDependentOption.cmake，你可以确保构建选项之间的依赖关系得到正确处理，并减少构建配置中的错误和混淆。

  以下是一个简单的示例，展示了如何使用CMakeDependentOption.cmake来创建一个依赖于其他选项的构建选项：

        include(CMakeDependentOption)  
        
        option(USE_FEATURE_A "Enable feature A" OFF)  
        
        cmake_dependent_option(USE_FEATURE_B "Enable feature B" OFF  
          "USE_FEATURE_A" ON)


  在这个示例中，USE_FEATURE_A是一个普通的构建选项，用户可以选择启用或禁用它。然后，使用cmake_dependent_option函数定义了USE_FEATURE_B选项，它依赖于USE_FEATURE_A选项。只有当USE_FEATURE_A被启用（即设置为ON）时，USE_FEATURE_B才会被启用或具有默认值OFF。

  通过这种方式，你可以利用CMakeDependentOption.cmake来管理复杂的构建选项依赖关系，并确保构建配置的正确性和一致性。


- cmake中GNUInstallDirs.cmake的作用是什么？
  
  在CMake中，GNUInstallDirs.cmake模块的作用是定义目标安装的标准位置。这个模块为不同类型的文件（如可执行文件、库文件、头文件等）提供了一组变量，这些变量表示所选安装前缀下的子目录名称。通过使用这些变量，你可以更容易地将已安装的文件放置在预期的目录中，从而提高项目的可移植性和一致性。

  具体来说，GNUInstallDirs.cmake定义了一些关键的变量，包括：

  1. CMAKE_INSTALL_BINDIR：用于定义用户可执行文件所在的子目录，即所选安装目录下的bin目录。
  2. CMAKE_INSTALL_LIBDIR：扩展到目标代码库（即静态库和动态库）所在的子目录。在64位系统上，它通常是lib64，而在32位系统上，它通常是lib。
  3. CMAKE_INSTALL_INCLUDEDIR：用于头文件获取正确的子目录，该变量通常为include。
  要在CMakeLists.txt中使用GNUInstallDirs.cmake模块，你只需添加一行include(GNUInstallDirs)即可导入它。然后，你可以使用这些定义的变量来指定目标文件的安装位置。

  总的来说，GNUInstallDirs.cmake模块通过提供标准的安装目录变量，帮助开发者在CMake项目中实现一致且可预测的文件安装布局。这有助于确保项目在不同的系统和环境中都能以预期的方式安装和运行。

- 指明操作系统
  - WIN32: Windows
  - APPLE：Macos
  - UNIX：表示类Unix

- set_property:
  
  在CMake中，set_property是一个相对较为少见的命令，它主要用于设置特定目标或源文件的属性。CMake的属性通常用于控制构建过程中的各个方面，比如编译选项、链接选项、源文件的语言标准等。


      set_property(TARGET <target> PROPERTY <name> <value>...)  
      set_property(SOURCE <source1> <source2> ... PROPERTY <name> <value>...)  
      set_property(DIRECTORY <dir> PROPERTY <name> <value>...)  
      set_property(GLOBAL PROPERTY <name> <value>...)

      其中：
      TARGET 用于设置目标的属性。
      SOURCE 用于设置源文件的属性。
      DIRECTORY 用于设置目录的属性。
      GLOBAL 用于设置全局属性。
      <target>、<source1>、<source2>、<dir> 分别是目标、源文件、目录的名称，而 <name> 和 <value> 则是属性的名称和值。


      例如，你可以使用set_property来为一个目标设置编译选项：

      set_property(TARGET mytarget PROPERTY COMPILE_OPTIONS "-Wall -Wextra")
      这将为mytarget目标设置编译选项-Wall和-Wextra。

      或者，你可以为源文件设置语言标准：  

      set_property(SOURCE myfile.cpp PROPERTY CXX_STANDARD 14)
      这将设置myfile.cpp的C++语言标准为C++14。

      需要注意的是，不是所有的属性都可以使用set_property来设置。CMake的文档通常会列出哪些属性可以通过set_property来设置，以及它们的具体用法和效果。

      此外，很多常见的设置（如编译选项、链接库等）通常使用更直接的命令（如`target_compile_options`、`target_link_libraries`等）来完成，而不是使用`set_property`。因此，在使用set_property之前，最好先检查CMake的文档，确保你了解该属性的用途和正确用法。


- include(PerformFeatureChecks)干什么用的？

  在CMake中，include(PerformFeatureChecks) 通常用于包含并执行一个名为 PerformFeatureChecks 的CMake模块或脚本。这个模块通常用于**执行一系列的特性检查，以确定当前的系统或编译器是否支持某些特定的功能或特性。**

  特性检查是CMake中非常重要的一个环节，它允许CMake在配置项目时根据系统的实际能力来启用或禁用某些功能。这**对于跨平台开发尤其重要**，因为不同的**操作系统、编译器或硬件架构**可能具有不同的功能集和限制。

  PerformFeatureChecks 模块通常会 *定义一系列的CMake函数或宏，用于执行这些特性检查。* 这些函数或宏可能会使用CMake的各种内置命令和变量来查询系统的信息，比如**编译器版本、库版本、可用的编译器标志等。**然后，根据这些信息，它们会**设置一些CMake变量或缓存条目，以便在后续的构建过程中使用**。

  例如，PerformFeatureChecks 模块可能会检查编译器是否支持C++11标准，并据此设置一个变量，以便在后续的构建过程中决定是否启用C++11特性。

  总的来说，include(PerformFeatureChecks) 的作用就是引入并执行一系列的特性检查，以确保项目能够在当前的系统和编译器配置下正确地构建和运行。这有助于提高项目的可移植性和健壮性。


- add_dependencies仅控制构建顺序，而不影响链接依赖
  add_dependencies是CMake中用来添加构建依赖关系的命令。这个命令用于指定一个目标（target）依赖于另一个目标或一组目标。这意味着在构建过程中，CMake会确保被依赖的目标在依赖它的目标之前被构建。

      add_dependencies(target-name depend-target1 [depend-target2 ...])

  其中：

  target-name是你想要添加依赖关系的目标。  
  depend-target1、depend-target2等是你想要target-name依赖的目标。  

  例如，假设你有一个自定义命令或外部脚本，它需要在构建你的库之前运行。你可以使用add_custom_command或add_custom_target来定义这个命令或目标，然后使用add_dependencies来确保它在你的库之前构建：


      add_custom_target(my_custom_target COMMAND my_script.sh)  
      add_library(my_library my_source.cpp)  
      add_dependencies(my_library my_custom_target)

    在这个例子中，my_script.sh会在my_library之前运行，因为它是一个my_library的依赖项。

    需要注意的是，add_dependencies仅控制构建顺序，而不影响链接依赖。如果你的目标需要链接到另一个目标，你应该使用target_link_libraries命令。


- cmake中的file函数有什么用？

  在CMake中，file函数用于执行与文件相关的操作。它允许你查询文件的存在性、读取文件内容、写入文件以及执行其他与文件相关的任务。file函数在CMake脚本中非常有用，特别是在需要处理文件或目录的生成、配置和测试时。

  以下是file函数的一些常见用法和选项：

  1. 查询文件或目录是否存在：
  使用EXISTS选项可以检查文件或目录是否存在。

        file(EXISTS path/to/file_or_directory)

  2. 读取文件内容：
  使用READ选项可以将文件的内容读入一个变量中。  

        file(READ filename variable)


  3. 写入文件：
  使用WRITE选项可以将文本写入文件。

        file(WRITE filename "Some text to write")

  4. 追加内容到文件：
  使用APPEND选项可以将文本追加到文件的末尾。

        file(APPEND filename "More text to append")


- target_include_directories和include_directories有什么区别？

  target_include_directories 支持设置私有包含路径，这意味着这些头文件路径只会在当前 target 内起作用，不会影响其他 target。这在需要为特定 target 隐藏或隔离头文件时非常有用。  
  include_directories 设置的头文件路径则是共享的，即所有 target 都可以看到这些路径


- add_library OBJECT作用？

  在CMake中，add_library命令用于创建库文件，其语法允许指定库的类型，包括静态库（STATIC）、共享库（SHARED）和模块库（MODULE）。然而，add_library命令本身并不直接支持OBJECT作为库的类型。

  但CMake确实支持OBJECT库的概念，这通常与add_custom_command或add_custom_target等命令结合使用，以生成一系列对象文件（即编译后的.o或.obj文件），但并不将这些对象文件链接成一个库。这种方式通常用于生成一些中间对象文件，这些文件可以在后续步骤中被其他目标使用，而不是直接创建一个库。

  如果你想创建一组对象文件而不是一个完整的库，你可能需要这样做：

  1. 使用add_library命令创建一个OBJECT库，但这并不是标准的做法，因为CMake的add_library命令不支持直接创建OBJECT库。

  2. 替代地，你可以创建一个自定义目标，使用add_custom_command或add_custom_target来编译源文件并生成对象文件，但不将它们链接。

  3.  将生成的对象文件添加到其他目标中，使用**target_sources**或**add_dependencies**来确保正确的构建顺序和依赖关系。
  需要注意的是，直接操作对象文件通常比操作库文件更底层和复杂，因此在使用这种方法时需要谨慎，并确保你理解CMake的构建系统和依赖关系管理。

  总的来说，如果你想要生成对象文件而不是库，你应该考虑使用CMake的其他功能，而不是试图通过add_library命令的某种非标准用法来实现。如果你有更具体的需求或场景，请提供更多信息，以便我能提供更准确的帮助。
