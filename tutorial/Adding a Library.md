# 第二步 2: 添加库

至此，我们已经了解了如何使用 CMake 创建一个基本项目。在这一步中，我们将学习如何在项目中创建和使用库以及为多种实现添加可选则的库和实现。

## 练习 1 - 创建一个库

要在 CMake 中添加一个库，请使用 [add_library](https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library) 命令，并指定组成该库的源文件。

我们可以用一个或多个子目录来组织项目，而不是将所有源文件放在一个目录中。在本例中，我们将专门为库创建一个子目录。在这里，我们可以添加一个新的 `CMakeLists.txt` 文件和一个或多个源文件。在顶层的 `CMakeLists.txt` 文件中，我们将使用 [add_subdirectory](https://cmake.org/cmake/help/latest/command/add_subdirectory.html#command:add_subdirectory) 命令将子目录添加到构建中。

一旦创建了库，它就会通过 [target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories) 和 [target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries) 连接到我们的可执行目标。

### 目标

添加并使用一个库。

### 用到的资源

-   [add_library](https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library)
-   [add_subdirectory](https://cmake.org/cmake/help/latest/command/add_subdirectory.html#command:add_subdirectory)
-   [target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories)
-   [target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries)
-   [PROJECT_SOURCE_DIR](https://cmake.org/cmake/help/latest/variable/PROJECT_SOURCE_DIR.html#variable:PROJECT_SOURCE_DIR)

### 需要编辑的文件

-   `CMakeLists.txt`
-   `tutorial.cxx`
-   `MathFunctions/CMakeLists.txt`

### 提示

在本练习中，我们将在项目中添加一个库，其中包含我们自己实现的数字平方根计算方法。然后，可执行文件就可以使用这个库代替编译器提供的标准平方根函数。
 
在本教程中，我们将把函数库放到名为 `MathFunctions` 的子目录中。该目录已包含头文件 `MathFunctions.h` 和 `mysqrt.h`。我们还提供了它们各自的源文件 `MathFunctions.cxx` 和 `mysqrt.cxx`。我们不需要修改这些文件。`mysqrt.cxx` 有一个名为 `mysqrt` 的函数，它提供了与编译器的 `sqrt` 函数类似的功能。`MathFunctions.cxx` 包含一个函数 `sqrt`，用于隐藏 `sqrt` 的实现细节。

在 `tutorial/Step2` 目录中，完成 `TODO 1` 到 `TODO 6`。

首先，完善 `MathFunctions` 目录下的 `CMakeLists.txt`。

接着，编辑主目录下的 `CMakeLists.txt`。

最后, 在 `tutorial.cxx` 中使用新创建的 `MathFunctions` 库。

### 构建与运行

运行 [cmake <cmake (1)>](https://cmake.org/cmake/help/latest/manual/cmake.1.html#manual:cmake(1)) 可执行文件或 [cmake-gui <cmake-gui(1)>](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) 配置项目，然后使用所选的构建工具构建项目。

命令的提示：

```bash
mkdir Step2_build
cd Step2_build
cmake ../Step2
cmake --build .
```

尝试使用新建的 `Tutorial` 并确保它仍能生成准确的平方根值。

### 答案

在 `MathFunctions` 目录下的 `CMakeLists.txt` 文件中，我们用 [add_library](https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library) 创建了一个名为 `MathFunctions` 的目标库。库的源文件作为参数传递给 [add_library](https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library)：

<details><summary>TODO 1: 点击显示/隐藏答案</summary>

```cmake
add_library(MathFunctions MathFunctions.cxx mysqrt.cxx)
```

</details></br>
为了使用新定义的库，我们将在顶层的 `CMakeLists.txt` 文件中添加一个 [add_subdirectory](https://cmake.org/cmake/help/latest/command/add_subdirectory.html#command:add_subdirectory) 调用来编译该库。

<details><summary>TODO 2: 点击显示/隐藏答案</summary>

```cmake
target_link_libraries(Tutorial PUBLIC MathFunctions)
```

</details></br>

然后，使用 [target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries) 将新目标库链接到可执行目标。

<details><summary>TODO 3: 点击显示/隐藏答案</summary>

```cmake
target_link_libraries(Tutorial PUBLIC MathFunctions)
```

</details></br>

最后，我们需要指定库的头文件位置。修改现有的 [target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories) 调用，添加 `MathFunctions` 子目录作为 include 目录，以便找到 `MathFunctions.h` 头文件。

<details><summary>TODO 4: 点击显示/隐藏答案</summary>
```cmake
target_include_directories(Tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctions"
                          )
```

</details></br>

现在让我们使用我们的函数库。在 `tutorial.cxx` 中 include `MathFunctions.h`：

<details><summary>TODO 5: 点击显示/隐藏答案</summary>

```cxx
#include "MathFunctions.h"
```

</details></br>

最后，将 `sqrt` 替换为封装函数 `mathfunctions::sqrt`。

<details><summary>TODO 6: 点击显示/隐藏答案</summary>

```cxx
const double outputValue = mathfunctions::sqrt(inputValue);
```

</details>
## 练习 2 - 添加一个选项

现在，让我们在 MathFunctions 库中添加一个选项，允许开发人员选择使用自定义平方根实现或内置的标准实现。虽然对于本教程中的平方根函数来说没有必要，但对于大型项目来说，这是经常发生的事情。

CMake 可以使用 [option](https://cmake.org/cmake/help/latest/command/option.html#command:option) 命令实现这一功能。这样，用户就可以在配置 cmake 编译时更改一个变量。该设置将保存在缓存中，因此用户无需每次在构建目录上运行 CMake 时都设置该值。

### 目标

添加不使用 `MathFunctions` 的构建选项。

### 用到的资源

-   [if](https://cmake.org/cmake/help/latest/command/if.html#command:if)
-   [option](https://cmake.org/cmake/help/latest/command/option.html#command:option)
-   [target_compile_definitions](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html#command:target_compile_definitions)

### 需要编辑的文件

-   `MathFunctions/CMakeLists.txt`
-   `MathFunctions/MathFunctions.cxx`

### 提示

用练习 1 的结果来完成 `TODO 7` 到 `TODO 14`。

首先在 `MathFunctions/CMakeLists.txt` 中使用 [option](https://cmake.org/cmake/help/latest/command/option.html#command:option) 命令创建一个变量 `USE_MYMATH`。在同一文件中，使用该选项将编译定义传递给 `MathFunctions` 库。

然后，更新 `MathFunctions.cxx` 来实现根据 `USE_MYMATH` 变量选择性编译。

最后，在 MathFunctions/CMakeLists.txt 的 `USE_MYMATH` 块内，通过将 mysqrt.cxx 创建为独立的库，来避免在不需要时依旧编译它。****

### 构建与运行

由于我们已经在练习 1 中配置好了构建目录，因此只需调用以下命令即可重建：

```bash
cd ../Step2_build
cmake --build .
```

接下来，给 `Tutorial` 程序输入几个数据来验证它是否正常工作。

现在让我们把 `USE_MYMATH` 的值更新为 `OFF`。最简单的方法是在终端使用 [cmake-gui <cmake-gui(1)>](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) 或 [ccmake <ccmake(1)>](https://cmake.org/cmake/help/latest/manual/ccmake.1.html#manual:ccmake(1)) 。也可以用命令行更改选项：

```bash
cmake ../Step2 -DUSE_MYMATH=OFF
```

现在，重新构建代码：

```bash
cmake --build .
```

然后，再次运行可执行文件，以确保在将 `USE_MYMATH` 设置为 `OFF` 时仍能运行。对比一下 `sqrt` 和 `mysqrt` 哪个函数的实现结果更好？

### 答案

第一步是在 `MathFunctions/CMakeLists.txt` 中添加一个选项。该选项将显示在 [cmake-gui <cmake-gui(1)>](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) 和 [ccmake <ccmake(1)>](https://cmake.org/cmake/help/latest/manual/ccmake.1.html#manual:ccmake(1)) 中，默认值为 `ON` 。

<details><summary>TODO 7: 点击显示/隐藏答案</summary>

```cmake
option(USE_MYMATH "Use tutorial provided math implementation" ON)
```

</details></br>

接下来，使用新选项为用 `mysqrt` 函数来构建和链接我们的库添加条件。

创建一条 [if](https://cmake.org/cmake/help/latest/command/if.html#command:if) 语句，检查 `USE_MYMATH` 的值。在 [if](https://cmake.org/cmake/help/latest/command/if.html#command:if) 块中，将 [target_compile_definitions()](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html#command:target_compile_definitions) 命令与编译定义 USE_MYMATH 放在一起。

<details><summary>TODO 8: 点击显示/隐藏答案</summary>

```cmake
if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
endif()
```

</details></br>

当 `USE_MYMATH` 为 `ON` 时，就设置编译定义变量 `USE_MYMATH` ，然后我们就可以使用该编译定义来启用或禁用源代码的各个部分。

对源代码的相应修改相当简单。在 `MathFunctions.cxx` 中，我们根据 `USE_MYMATH` 控制使用哪个平方根函数：

<details><summary>TODO 9: 点击显示/隐藏答案</summary>

```cxx
#ifdef USE_MYMATH
  return detail::mysqrt(x);
#else
  return std::sqrt(x);
#endif
```

</details></br>

接下来，如果定义了 `USE_MYMATH` ，我们需要 include `mysqrt.h`。

<details><summary>TODO 10: 点击显示/隐藏答案</summary>

```cxx
#ifdef USE_MYMATH
#  include "mysqrt.h"
#endif
```

</details></br>

最后，如果我们使用了 `std::sqrt`，就需要包含 `cmath`。

<details><summary>TODO 11: 点击显示/隐藏答案</summary>

```cpp
#include <cmath>
```

</details></br>

此时，如果 `USE_MYMATH` 为 `OFF`，则不会使用 `mysqrt.cxx`，但它仍会被编译，因为 `MathFunctions` 目标在源代码下列出了 `mysqrt.cxx`。

有几种方法可以解决这个问题。第一种方法是使用 [target_sources](https://cmake.org/cmake/help/latest/command/target_sources.html#command:target_sources) 从 `USE_MYMATH` 代码块中添加 `mysqrt.cxx`。另一种方法是在 `USE_MYMATH` 代码块中创建一个额外的库，负责编译 `mysqrt.cxx`。在本教程中，我们将创建一个附加库。

首先，在 `USE_MYMATH` 中创建一个名为 `SqrtLibrary` 的库，其源代码为 `mysqrt.cxx`。

<details><summary>TODO 12: 点击显示/隐藏答案</summary>

```cmake
add_library(SqrtLibrary STATIC
            mysqrt.cxx
            )
target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
```

</details></br>

接下来，当启用 `USE_MYMATH` 时，我们将 `SqrtLibrary` 链接到 `MathFunctions` 上。

<details><summary>TODO 13: 点击显示/隐藏答案</summary>

```cmake
target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
```

</details></br>

最后，我们可以将 `mysqrt.cxx` 从我们的 `MathFunctions` 库源代码列表中移除，因为当 `SqrtLibrary` 被包含时它就会被引入。

<details><summary>TODO 14: 点击显示/隐藏答案</summary>

```cmake
add_library(MathFunctions MathFunctions.cxx)
```

</details></br>

有了这些更改，"mysqrt "函数现在对于构建和使用 "MathFunctions "库的用户来说完全是可选的了。用户可以切换 `USE_MYMATH` 来控制在构建过程中使用哪个库。
