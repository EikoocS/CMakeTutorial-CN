# Step 10: Selecting Static or Shared Libraries

In this section we will show how the
[BUILD_SHARED_LIBS](https://cmake.org/cmake/help/latest/variable/BUILD_SHARED_LIBS.html#variable:BUILD_SHARED_LIBS) variable can be
used to control the default behavior of [add_library](https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library), and allow control over how libraries without an
explicit type (`STATIC`, `SHARED`, `MODULE` or `OBJECT`) are built.

To accomplish this we need to add [BUILD_SHARED_LIBS](https://cmake.org/cmake/help/latest/variable/BUILD_SHARED_LIBS.html#variable:BUILD_SHARED_LIBS) to the top-level `CMakeLists.txt`. We use the
[option](https://cmake.org/cmake/help/latest/command/option.html#command:option) command as it allows users to
optionally select if the value should be `ON` or `OFF`.

::: {#CMakeLists.txt-option-BUILD_SHARED_LIBS .literalinclude caption="CMakeLists.txt" language="cmake" start-after="set(CMAKE_RUNTIME_OUTPUT_DIRECTORY" end-before="# configure a header file to pass the version number only"}
Step11/CMakeLists.txt
:::

Next, we need to specify output directories for our static and shared
libraries.

::: {#CMakeLists.txt-cmake-output-directories .literalinclude caption="CMakeLists.txt" language="cmake" start-after="# we don't need to tinker with the path to run the executable" end-before="# configure a header file to pass the version number only"}
Step11/CMakeLists.txt
:::

Finally, update `MathFunctions/MathFunctions.h` to use dll export
defines:

::: {#MathFunctions/MathFunctions.h .literalinclude caption="MathFunctions/MathFunctions.h" language="c++"}
Step11/MathFunctions/MathFunctions.h
:::

At this point, if you build everything, you may notice that linking
fails as we are combining a static library without position independent
code with a library that has position independent code. The solution to
this is to explicitly set the
[POSITION_INDEPENDENT_CODE](https://cmake.org/cmake/help/latest/prop_tgt/POSITION_INDEPENDENT_CODE.html#prop_tgt:POSITION_INDEPENDENT_CODE) target
property of SqrtLibrary to be `True` when building shared libraries.

::: {#MathFunctions/CMakeLists.txt-POSITION_INDEPENDENT_CODE .literalinclude caption="MathFunctions/CMakeLists.txt" language="cmake" start-at="# state that SqrtLibrary need PIC when the default is shared libraries" end-at=")"}
Step11/MathFunctions/CMakeLists.txt
:::

Define `EXPORTING_MYMATH` stating we are using `declspec(dllexport)`
when building on Windows.

::: {#MathFunctions/CMakeLists.txt-dll-export .literalinclude caption="MathFunctions/CMakeLists.txt" language="cmake" start-at="# define the symbol stating we are using the declspec(dllexport) when" end-at="target_compile_definitions(MathFunctions PRIVATE \"EXPORTING_MYMATH\")"}
Step11/MathFunctions/CMakeLists.txt
:::

**Exercise**: We modified `MathFunctions.h` to use dll export defines.
Using CMake documentation can you find a helper module to simplify this?
