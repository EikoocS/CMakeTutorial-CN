# Step 4: Adding Generator Expressions

[Generator expressions <Generator expressions(7)>](https://cmake.org/cmake/help/latest/manual/Generator expressions.7.html#manual:Generator expressions(7)) are evaluated during build system generation to produce
information specific to each build configuration.

[Generator expressions <Generator expressions(7)>](https://cmake.org/cmake/help/latest/manual/Generator expressions.7.html#manual:Generator expressions(7)) are allowed in the context of many target properties,
such as [LINK_LIBRARIES](https://cmake.org/cmake/help/latest/prop_tgt/LINK_LIBRARIES.html#prop_tgt:LINK_LIBRARIES),
[INCLUDE_DIRECTORIES](https://cmake.org/cmake/help/latest/prop_tgt/INCLUDE_DIRECTORIES.html#prop_tgt:INCLUDE_DIRECTORIES),
[COMPILE_DEFINITIONS](https://cmake.org/cmake/help/latest/prop_tgt/COMPILE_DEFINITIONS.html#prop_tgt:COMPILE_DEFINITIONS) and others.
They may also be used when using commands to populate those properties,
such as [target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries),
[target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories),
[target_compile_definitions](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html#command:target_compile_definitions) and
others.

[Generator expressions <Generator expressions(7)>](https://cmake.org/cmake/help/latest/manual/Generator expressions.7.html#manual:Generator expressions(7)) may be used to enable conditional linking, conditional
definitions used when compiling, conditional include directories and
more. The conditions may be based on the build configuration, target
properties, platform information or any other queryable information.

There are different types of
[generator expressions <generator expressions(7)>](https://cmake.org/cmake/help/latest/manual/generator expressions.7.html#manual:generator expressions(7)) including Logical, Informational, and Output expressions.

Logical expressions are used to create conditional output. The basic
expressions are the `0` and `1` expressions. A `$<0:...>` results in the
empty string, and `$<1:...>` results in the content of `...`. They can
also be nested.

## 练习 1 - Adding Compiler Warning Flags with Generator Expressions

A common usage of
[generator expressions <generator expressions(7)>](https://cmake.org/cmake/help/latest/manual/generator expressions.7.html#manual:generator expressions(7)) is to conditionally add compiler flags, such as those for
language levels or warnings. A nice pattern is to associate this
information to an `INTERFACE` target allowing this information to
propagate.

### 目标

Add compiler warning flags when building but not for installed versions.

### 用到的资源

-   [cmake-generator-expressions(7)](https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html#manual:cmake-generator-expressions(7))
-   [cmake_minimum_required](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command:cmake_minimum_required)
-   [set](https://cmake.org/cmake/help/latest/command/set.html#command:set)
-   [target_compile_options](https://cmake.org/cmake/help/latest/command/target_compile_options.html#command:target_compile_options)

### 需要编辑的文件

-   `CMakeLists.txt`

### 提示

Open the file `Step4/CMakeLists.txt` and complete `TODO 1` through
`TODO 4`.

First, in the top level `CMakeLists.txt` file, we need to set the
[cmake_minimum_required](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command:cmake_minimum_required) to `3.15`. In
this exercise we are going to use a generator expression which was
introduced in CMake 3.15.

Next we add the desired compiler warning flags that we want for our
project. As warning flags vary based on the compiler, we use the
`COMPILE_LANG_AND_ID` generator expression to control which flags to
apply given a language and a set of compiler ids.

### 构建与运行

Make a new directory called `Step4_build`, run the
[cmake <cmake(1)>](https://cmake.org/cmake/help/latest/manual/cmake.1.html#manual:cmake(1)) executable or the
[cmake-gui <cmake-gui(1)>](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) to configure
the project and then build it with your chosen build tool or by using
`cmake --build .` from the build directory.

```bash
mkdir Step4_build
cd Step4_build
cmake ../Step4
cmake --build .
```

### 答案

Update the [cmake_minimum_required](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command:cmake_minimum_required) to
require at least CMake version `3.15`:

<details><summary>TODO 1: 点击显示/隐藏答案</summary>
::: {#MathFunctions-CMakeLists.txt-minimum-required-step4 .literalinclude caption="TODO 1: CMakeLists.txt" language="cmake" end-before="# set the project name and version"}
Step5/CMakeLists.txt
:::

</details>
Next we determine which compiler our system is currently using to build
since warning flags vary based on the compiler we use. This is done with
the `COMPILE_LANG_AND_ID` generator expression. We set the result in the
variables `gcc_like_cxx` and `msvc_cxx` as follows:

<details><summary>TODO 2: 点击显示/隐藏答案</summary>
::: {#CMakeLists.txt-compile_lang_and_id .literalinclude caption="TODO 2: CMakeLists.txt" language="cmake" start-after="# the BUILD_INTERFACE genex" end-before="target_compile_options(tutorial_compiler_flags INTERFACE"}
Step5/CMakeLists.txt
:::

</details>
Next we add the desired compiler warning flags that we want for our
project. Using our variables `gcc_like_cxx` and `msvc_cxx`, we can use
another generator expression to apply the respective flags only when the
variables are true. We use  to apply these flags to our interface library.

<details><summary>TODO 3: 点击显示/隐藏答案</summary>
```cmake
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
  "$<${msvc_cxx}:-W3>"
)
```

</details>
Lastly, we only want these warning flags to be used during builds.
Consumers of our installed project should not inherit our warning flags.
To specify this, we wrap our flags from TODO 3 in a generator expression
using the `BUILD_INTERFACE` condition. The resulting full code looks
like the following:

<details><summary>TODO 4: 点击显示/隐藏答案</summary>
::: {#CMakeLists.txt-target_compile_options-genex .literalinclude caption="TODO 4: CMakeLists.txt" language="cmake" start-after="set(msvc_cxx \"$<COMPILE_LANG_AND_ID:CXX,MSVC>\")" end-before="# configure a header file to pass some of the CMake settings"}
Step5/CMakeLists.txt
:::

</details>
