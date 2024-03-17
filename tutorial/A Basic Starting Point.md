# 第 1 步：基础的起点

怎样开始使用 CMake？这一步将介绍的一些基本语法、命令和变量。在介绍这些概念的同时，我们将通过三个练习来创建一个简单的 CMake 项目。

本步骤中的每个练习都会先介绍一些背景信息。然后是 __目标__ 和 __资源__。在这一步中要编辑的文件部分中的每个文件都位于 `Step1` 目录下，包含一个或多个 `TODO` 注释。每个 `TODO` 代表要更改或添加的一两行代码。`TODO` 应按数字顺序完成，首先完成 `TODO 1`，然后完成 `TODO 2` 等等。__入门__ 部分将提供一些有用的提示，指导你完成练习。然后，__构建与运行__ 部分将逐步介绍如何构建和测试练习。最后，在每个练习的结尾都会讨论预期的 __解决方案__ 。

还要注意的是，教程中的每一步都是在上一步的基础上进行的。例如，步骤 2 的起始代码就是步骤 1 的完整解决方案。

## 练习 1 - 构建一个基础的项目

最基本的 CMake 项目是由单个源代码文件构建的可执行文件。对于像这样的简单项目，只需一个包含三条命令的 `CMakeLists.txt` 三条命令即可。

**注意:** 虽然 CMake 支持大写、小写和混合大小写命令，但本教程都将使用小写命令。

任何项目的 CMakeLists.txt 都必须首先使用 [cmake_minimum_required](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command:cmake_minimum_required) 命令指定最低版本. 这提供了一种策略来保证 CMake 功能可以被兼容的运行。

要开始一个项目，我们使用 [project](https://cmake.org/cmake/help/latest/command/project.html#command:project) 命令来设置项目名称。每个项目都需要调用，并且应在 [cmake_minimum_required](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command:cmake_minimum_required) 之后调用。稍后我们将看到，该命令还可用于指定其他项目级信息，如语言和版本号。

最后，使用 [add_executable](https://cmake.org/cmake/help/latest/command/add_executable.html#command:add_executable) 命令告诉 CMake 使用指定的源文件创建一个可执行文件。

### 目标

理解如何创建一个简单的 CMake 项目。

### 用到的资源

-   [add_executable](https://cmake.org/cmake/help/latest/command/add_executable.html#command:add_executable)
-   [cmake_minimum_required](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command:cmake_minimum_required)
-   [project](https://cmake.org/cmake/help/latest/command/project.html#command:project)

### 需要编辑的文件

-   `CMakeLists.txt`

### 提示

tutorial.cxx "的源代码位于 `tutorial/Step1` 目录下，可用于计算一个数字的平方根。本步骤无需编辑该文件。

在 `TODO 1` 到 `TODO 3` 中我们需要完善在该目录下的 `CMakeLists.txt` 文件。

### 构建与运行

完成 `TODO 1` 到 `TODO 3` 我们就可以构建运行我们的项目了! 首先, 执行 [cmake <cmake(1)>](https://cmake.org/cmake/help/latest/manual/cmake.1.html#manual:cmake(1)) 或 [cmake-gui <cmake-gui(1)>](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) 来配置项目，然后用你选择的工具构建它。

例如，我们可以从命令行导航到 CMake 源代码树的 "Help/guide/tutorial "目录，并创建一个构建目录：

```bash
mkdir Step1_build
```

接下来，导航至该构建目录并运行 [cmake <cmake(1)>](https://cmake.org/cmake/help/latest/manual/cmake.1.html#manual:cmake(1)) 来配置该项目并生成本地编译系统：

```bash
cd Step1_build
cmake ../Step1
```

然后调用构建系统来实际编译/链接项目：


```bash
cmake --build .
```

对于多配置生成器（如 Visual Studio），首先导航到
适当的子目录，例如

```bash
cd Debug
```

最后，尝试使用新创建的 `Tutorial`：

```bash
Tutorial 4294967296
Tutorial 10
Tutorial
```

**注意：** 根据 shell 的不同，正确的语法可能是 `Tutorial`（例如 Windows CMD）、`./Tutorial` （例如 Bash）或 `.\Tutorial`（例如 Windows PowerShell）。为简单起见，本练习将始终使用 `Tutorial`。

### 答案

如上所述，我们只需要三行 `CMakeLists.txt
即可运行。第一行是使用 [cmake_minimum_required](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command:cmake_minimum_required) 来设置 CMake 版本:

<details><summary>TODO 1: 点击显示/隐藏答案</summary>

```cmake
cmake_minimum_required(VERSION 3.10)
```
</details></br>

制作基本项目的下一步是使用 [project](https://cmake.org/cmake/help/latest/command/project.html#command:project) 命令来设置项目名称：

<details><summary>TODO 2: 点击显示/隐藏答案</summary>

```cmake
project(Tutorial)
```

</details></br>

对于完成这个项目我们需要调用的最后一条命令是 [add_executable](https://cmake.org/cmake/help/latest/command/add_executable.html#command:add_executable)：

<details><summary>TODO 3: 点击显示/隐藏答案</summary>

```cmake
add_executable(Tutorial tutorial.cxx)
```
</details>

## 练习 2 - 指定 C++ 标准

CMake 有一些特殊的变量，要么是在幕后创建的，要么在被项目代码设置时对 CMake 有特殊意义。其中许多变量以 CMAKE_ 开头。在创建项目变量时要避免与这种命名冲突。其中两个特殊的可设置用户变量是 [CMAKE_CXX_STANDARD](https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD.html#variable:CMAKE_CXX_STANDARD) 和 [CMAKE_CXX_STANDARD_REQUIRED](https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD_REQUIRED.html#variable:CMAKE_CXX_STANDARD_REQUIRED) 。这两个变量可以一起使用来指定构建项目所需的 C++ 标准。

### 目标

添加一项需要 C++11 的功能。

### 用到的资源

-   [CMAKE_CXX_STANDARD](https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD.html#variable:CMAKE_CXX_STANDARD)
-   [CMAKE_CXX_STANDARD_REQUIRED](https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD_REQUIRED.html#variable:CMAKE_CXX_STANDARD_REQUIRED)
-   [set](https://cmake.org/cmake/help/latest/command/set.html#command:set)

### 需要编辑的文件

-   `CMakeLists.txt`
-   `tutorial.cxx`

__译注__ 这里的 .cxx 即 C++ 的源代码文件格式，也就是常见的 .cpp 。在 [StackOverflow](https://stackoverflow.com/questions/17986118/what-is-xx-in-cxx-in-a-cmake-cmakelists-txt-file) 的一个回答里有一种对为什么使用 “cxx” 而不是 “cpp” 的解释：</br>
 - xx 的意思是 “++” ，每个 x 就像是旋转了 45° 的 “+”，CXX 的意思就是 “C++”
 - 为什么不使用 “c++” ： 因为宏里面不能包含 "+"
 - 为什么不使用 “cpp” ： 因为已经被用来表示 “**C** **P**re**P**rocessor” （ C 预处理器）

### 提示

从 `TODO 4` 到 `TODO 6` ，我们需要继续编辑 `Step1` 目录中的文件。

首先，编辑 `tutorial.cxx` 添加需要 C++11 的功能，然后更新 `CMakeLists.txt` 来指定 C++11。

### 构建与运行

让我们再次构建我们的项目。由于我们已经在练习 1 中创建了目录并运行了 CMake，所以我们可以跳过构建步骤：

```bash
cd Step1_build
cmake --build .
```

现在，我们可以尝试使用新构建的 `Tutorial` 并执行与之前相同的命令：

```bash
Tutorial 4294967296
Tutorial 10
Tutorial
```

### 答案

我们首先在项目中添加一些 C++11 功能，在 `tutorial.cxx` 中用 `std::stod` 替换`atof`：


<details><summary>TODO 4: 点击显示/隐藏答案</summary>

```cpp
const double inputValue = std::stod(argv[1]);
```

</details></br>

要完成 `TODO 5` 只需删除 `#include <cstdlib>`。

我们需要在 CMake 代码中明确说明它应该使用正确的标标记。在 CMake 中启用对特定 C++ 标准的支持的一种方法是使用 [CMAKE_CXX_STANDARD](https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD.html#variable:CMAKE_CXX_STANDARD) 变量。对于这个指南，将 `CMakeLists.txt` 文件中的 [CMAKE_CXX_STANDARD](https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD.html#variable:CMAKE_CXX_STANDARD) 变量设置为 11，将
[CMAKE_CXX_STANDARD_REQUIRED](https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD_REQUIRED.html#variable:CMAKE_CXX_STANDARD_REQUIRED) 变量设置为 True。 确保 [CMAKE_CXX_STANDARD](https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD.html#variable:CMAKE_CXX_STANDARD) 在调用
[add_executable](https://cmake.org/cmake/help/latest/command/add_executable.html#command:add_executable) 之前声明。

<details><summary>TODO 6: 点击显示/隐藏答案</summary>

```cmake
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```
</details>

## 练习 3 - 添加版本号和配置头文件

有时，在源代码中也可以使用在 `CMakelists.txt` 文件中定义的变量。在这种情况下，例如我们希望输出项目的版本。

其中一种方法是使用配置头文件。我们创建一个输入文件，其中包含一个或多个要替换的变量。这些变量有特殊的语法，看起来像 `@VAR@`。然后，我们使用 [configure_file](https://cmake.org/cmake/help/latest/command/configure_file.html#command:configure_file) 命令将输入文件复制到给定的输出文件，并用 `CMakelists.txt` 文件中 `VAR` 的当前值替换这些变量。

虽然我们可以直接在源代码中编辑版本，但我们更倾向于使用这一功能，因为它可以创建一个单一数据源，而无需重复定义。

### 目标

定义并报告项目的版本号。

### 用到的资源

-   [\<PROJECT-NAME\>_VERSION_MAJOR](https://cmake.org/cmake/help/latest/variable/PROJECT-NAME_VERSION_MAJOR.html#variable:<PROJECT-NAME>_VERSION_MAJOR)
-   [\<PROJECT-NAME\>_VERSION_MINOR](https://cmake.org/cmake/help/latest/variable/PROJECT-NAME_VERSION_MINOR.html#variable:<PROJECT-NAME>_VERSION_MINOR)
-   [configure_file](https://cmake.org/cmake/help/latest/command/configure_file.html#command:configure_file)
-   [target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories)

### 需要编辑的文件

-   `CMakeLists.txt`
-   `tutorial.cxx`

### 提示

从 `TODO 7` 到 `TODO 12`，我们将继续编辑 `Step1` 中的文件。在本练习中，我们首先在 `CMakeLists.txt` 中添加项目版本号。在同一文件中，使用 [configure_file](https://cmake.org/cmake/help/latest/command/configure_file.html#command:configure_file) 将给定的输入文件复制到输出文件，并在输入文件内容中指定的一些变量值。

接下来，创建一个输入头文件 `TutorialConfig.h.in` ，定义版本号，接受 [configure_file](https://cmake.org/cmake/help/latest/command/configure_file.html#command:configure_file) 传递的变量。

最后，修改 `tutorial.cxx` 来打印出版本号。

### 构建与运行

让我们再次构建我们的项目。和之前一样，我们已经创建了一个构建目录并运行了 CMake，因此可以跳过构建步骤：

```bash
cd Step1_build
cmake --build .
```

首先验证一下在不带任何参数的情况下运行可执行文件时，是否会报告版本号。

### 答案

在本练习中，我们将通过打印版本号来改进我们的可执行文件。虽然我们可以只在源代码中这样做，但使用 `CMakeLists.txt` 可以让我们保持版本号来自单一数据源。

首先，我们修改 `CMakeLists.txt` 文件，使用 [project](https://cmake.org/cmake/help/latest/command/project.html#command:project) 命令来设置项目名称和版本号。调用 [project](https://cmake.org/cmake/help/latest/command/project.html#command:project) 命令时，CMake 会在幕后定义 `Tutorial_VERSION_MAJOR` 和 `Tutorial_VERSION_MINOR`。

<details><summary>TODO 7: 点击显示/隐藏答案</summary>

```cmake
project(Tutorial VERSION 1.0)
```

</details></br>

然后，我们使用 [configure_file](https://cmake.org/cmake/help/latest/command/configure_file.html#command:configure_file) 复制输入文件，并替换指定的 CMake 变量：

<details><summary>TODO 8: 点击显示/隐藏答案</summary>

```cmake
configure_file(TutorialConfig.h.in TutorialConfig.h)
```

</details></br>

由于配置文件将写入项目二进制目录，我们必须将该目录添加到搜索包含文件的路径列表中。

**注意：** 在本教程中，我们将交替使用项目构建目录和项目二进制目录。这两个目录是相同的，并不是指 `bin/` 目录。

我们使用 [target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories) 来指定目标可执行文件应在何处查找 include 文件。

<details><summary>TODO 9: 点击显示/隐藏答案</summary>

```cmake
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
```
</details></br>

`TutorialConfig.h.in` 是要配置的输入头文件。当从我们的 `CMakeLists.txt` 调用 [configure_file](https://cmake.org/cmake/help/latest/command/configure_file.html#command:configure_file) 时，`@Tutorial_VERSION_MAJOR@` 和`@Tutorial_VERSION_MINOR@` 的值将被替换为 `TutorialConfig.h` 中项目的相应版本号。

<details><summary>TODO 10: 点击显示/隐藏答案</summary>

```h
// Tutorial 的配置选项和设置
#define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@
```
</details></br>

接下来，我们需要修改 `tutorial.cxx` 以包含已配置的头文件 `TutorialConfig.h`。

<details><summary>TODO 11: 点击显示/隐藏答案</summary>

```cxx
#include "TutorialConfig.h"
```

</details></br>

最后，我们通过更新 `tutorial.cxx` 来打印出可执行文件的名称和版本号，如下所示：

<details><summary>TODO 12: 点击显示/隐藏答案</summary>

```cxx
  if (argc < 2) {
    // 报告版本
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }
```
</details></br>
