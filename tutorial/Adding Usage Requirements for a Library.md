# Step 3: Adding Usage Requirements for a Library

## 练习 1 - Adding Usage Requirements for a Library

[Usage requirements](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#target-usage-requirements) of a target parameters allow for far better control over a
library or executable\'s link and include line while also giving more
control over the transitive property of targets inside CMake. The
primary commands that leverage usage requirements are:

-   [target_compile_definitions](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html#command:target_compile_definitions)
-   [target_compile_options](https://cmake.org/cmake/help/latest/command/target_compile_options.html#command:target_compile_options)
-   [target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories)
-   [target_link_directories](https://cmake.org/cmake/help/latest/command/target_link_directories.html#command:target_link_directories)
-   [target_link_options](https://cmake.org/cmake/help/latest/command/target_link_options.html#command:target_link_options)
-   [target_precompile_headers](https://cmake.org/cmake/help/latest/command/target_precompile_headers.html#command:target_precompile_headers)
-   [target_sources](https://cmake.org/cmake/help/latest/command/target_sources.html#command:target_sources)

### 目标

Add usage requirements for a library.

### Helpful Materials

-   [CMAKE_CURRENT_SOURCE_DIR](https://cmake.org/cmake/help/latest/variable/CMAKE_CURRENT_SOURCE_DIR.html#variable:CMAKE_CURRENT_SOURCE_DIR)

### 需要编辑的文件

-   `MathFunctions/CMakeLists.txt`
-   `CMakeLists.txt`

### 入门

In this exercise, we will refactor our code from
[Adding a Library](./Adding%20a%20Library.md) to use the
modern CMake approach. We will let our library define its own usage
requirements so they are passed transitively to other targets as
necessary. In this case, `MathFunctions` will specify any needed include
directories itself. Then, the consuming target `Tutorial` simply needs
to link to `MathFunctions` and not worry about any additional include
directories.

The starting source code is provided in the `Step3` directory. In this
exercise, complete `TODO 1` through `TODO 3`.

First, add a call to [target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories) in `MathFunctions/CMakeLists`. Remember that
[CMAKE_CURRENT_SOURCE_DIR](https://cmake.org/cmake/help/latest/variable/CMAKE_CURRENT_SOURCE_DIR.html#variable:CMAKE_CURRENT_SOURCE_DIR) is the
path to the source directory currently being processed.

Then, update (and simplify!) the call to
[target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories) in the
top-level `CMakeLists.txt`.

### 构建与运行

Make a new directory called [Step3_build`, run the `cmake <Step3_build`, run the `cmake(1)>](https://cmake.org/cmake/help/latest/manual/Step3_build`, run the `cmake.1.html#manual:Step3_build`, run the `cmake(1)) executable or the
[cmake-gui <cmake-gui(1)>](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) to configure
the project and then build it with your chosen build tool or by using
[cmake --build](https://cmake.org/cmake/help/latest/manual/cmake.1.html#cmdoption-cmake-build) from
the build directory. Here\'s a refresher of what that looks like from
the command line:

```bash
mkdir Step3_build
cd Step3_build
cmake ../Step3
cmake --build .
```

Next, use the newly built `Tutorial` and verify that it is working as
expected.

### 解决方案

Let\'s update the code from the previous step to use the modern CMake
approach of usage requirements.

We want to state that anybody linking to `MathFunctions` needs to
include the current source directory, while `MathFunctions` itself
doesn\'t. This can be expressed with an `INTERFACE` usage requirement.
Remember `INTERFACE` means things that consumers require but the
producer doesn\'t.

At the end of `MathFunctions/CMakeLists.txt`, use
[target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories) with the
`INTERFACE` keyword, as follows:

```html
<details><summary>TODO 1: 点击显示/隐藏答案</summary>
```
::: {#MathFunctions/CMakeLists.txt-target_include_directories-INTERFACE .literalinclude caption="TODO 1: MathFunctions/CMakeLists.txt" language="cmake" start-after="# to find MathFunctions.h" end-before="# should we use our own"}
Step4/MathFunctions/CMakeLists.txt
:::

```html
</details>
```
Now that we\'ve specified usage requirements for `MathFunctions` we can
safely remove our uses of the `EXTRA_INCLUDES` variable from the
top-level `CMakeLists.txt`.

Remove this line:

```html
<details><summary>TODO 2: 点击显示/隐藏答案</summary>
```
::: {#CMakeLists.txt-remove-EXTRA_INCLUDES .literalinclude caption="TODO 2: CMakeLists.txt" language="cmake" start-after="add_subdirectory(MathFunctions)" end-before="# add the executable"}
Step3/CMakeLists.txt
:::

```html
</details>
```
And remove `EXTRA_INCLUDES` from `target_include_directories`:

```html
<details><summary>TODO 3: 点击显示/隐藏答案</summary>
```
::: {#CMakeLists.txt-target_include_directories-remove-EXTRA_INCLUDES .literalinclude caption="TODO 3: CMakeLists.txt" language="cmake" start-after="# so that we will find TutorialConfig.h"}
Step4/CMakeLists.txt
:::

```html
</details>
```
Notice that with this technique, the only thing our executable target
does to use our library is call
[target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries) with the name
of the library target. In larger projects, the classic method of
specifying library dependencies manually becomes very complicated very
quickly.

## 练习 2 - Setting the C++ Standard with Interface Libraries

Now that we have switched our code to a more modern approach, let\'s
demonstrate a modern technique to set properties to multiple targets.

Let\'s refactor our existing code to use an `INTERFACE` library. We will
use that library in the next step to demonstrate a common use for
[generator expressions <generator expressions(7)>](https://cmake.org/cmake/help/latest/manual/generator expressions.7.html#manual:generator expressions(7)).

### 目标

Add an `INTERFACE` library target to specify the required C++ standard.

### 资源

-   [add_library](https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library)
-   [target_compile_features](https://cmake.org/cmake/help/latest/command/target_compile_features.html#command:target_compile_features)
-   [target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries)

### 需要编辑的文件

-   `CMakeLists.txt`
-   `MathFunctions/CMakeLists.txt`

### 入门

In this exercise, we will refactor our code to use an `INTERFACE`
library to specify the C++ standard.

Start this exercise from what we left at the end of Step3 exercise 1.
You will have to complete `TODO 4` through `TODO 7`.

Start by editing the top level `CMakeLists.txt` file. Construct an
`INTERFACE` library target called `tutorial_compiler_flags` and specify
`cxx_std_11` as a target compiler feature.

Modify `CMakeLists.txt` and `MathFunctions/CMakeLists.txt` so that all
targets have a [target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries)
call to `tutorial_compiler_flags`.

### 构建与运行

Since we have our build directory already configured from Exercise 1,
simply rebuild our code by calling the following:

```bash
cd Step3_build
cmake --build .
```

Next, use the newly built `Tutorial` and verify that it is working as
expected.

### 解决方案

Let\'s update our code from the previous step to use interface libraries
to set our C++ requirements.

To start, we need to remove the two [set](https://cmake.org/cmake/help/latest/command/set.html#command:set) calls on the variables
[CMAKE_CXX_STANDARD](https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD.html#variable:CMAKE_CXX_STANDARD) and
[CMAKE_CXX_STANDARD_REQUIRED](https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD_REQUIRED.html#variable:CMAKE_CXX_STANDARD_REQUIRED). The
specific lines to remove are as follows:

::: {#CMakeLists.txt-CXX_STANDARD-variable-remove .literalinclude caption="CMakeLists.txt" language="cmake" start-after="# specify the C++ standard" end-before="# configure a header file"}
Step3/CMakeLists.txt
:::

Next, we need to create an interface library, `tutorial_compiler_flags`.
And then use [target_compile_features](https://cmake.org/cmake/help/latest/command/target_compile_features.html#command:target_compile_features)
to add the compiler feature `cxx_std_11`.

```html
<details><summary>TODO 4: 点击显示/隐藏答案</summary>
```
::: {#CMakeLists.txt-cxx_std-feature .literalinclude caption="TODO 4: CMakeLists.txt" language="cmake" start-after="# specify the C++ standard" end-before="# TODO 2: Create helper"}
Step4/CMakeLists.txt
:::

```html
</details>
```
Finally, with our interface library set up, we need to link our
executable `Tutorial`, our `SqrtLibrary` library and our `MathFunctions`
library to our new `tutorial_compiler_flags` library. Respectively, the
code will look like this:

```html
<details><summary>TODO 5: 点击显示/隐藏答案</summary>
```
::: {#CMakeLists.txt-target_link_libraries-step4 .literalinclude caption="TODO 5: CMakeLists.txt" language="cmake" start-after="add_executable(Tutorial tutorial.cxx)" end-before="# add the binary tree to the search path for include file"}
Step4/CMakeLists.txt
:::

```html
</details>
```
this:

```html
<details><summary>TODO 6: 点击显示/隐藏答案</summary>
```
::: {#MathFunctions-CMakeLists.txt-target_link_libraries-step4 .literalinclude caption="TODO 6: MathFunctions/CMakeLists.txt" language="cmake" start-after="# link SqrtLibrary to tutorial_compiler_flags" end-before="target_link_libraries(MathFunctions"}
Step4/MathFunctions/CMakeLists.txt
:::

```html
</details>
```
and this:

```html
<details><summary>TODO 7: 点击显示/隐藏答案</summary>
```
::: {#MathFunctions-SqrtLibrary-target_link_libraries-step4 .literalinclude caption="TODO 7: MathFunctions/CMakeLists.txt" language="cmake" start-after="# link MathFunctions to tutorial_compiler_flags"}
Step4/MathFunctions/CMakeLists.txt
:::

```html
</details>
```
With this, all of our code still requires C++ 11 to build. Notice though
that with this method, it gives us the ability to be specific about
which targets get specific requirements. In addition, we create a single
source of truth in our interface library.
