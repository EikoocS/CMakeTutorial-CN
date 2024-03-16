# Step 12: Packaging Debug and Release

**Note:** This example is valid for single-configuration generators and
will not work for multi-configuration generators (e.g. Visual Studio).

By default, CMake\'s model is that a build directory only contains a
single configuration, be it Debug, Release, MinSizeRel, or
RelWithDebInfo. It is possible, however, to setup CPack to bundle
multiple build directories and construct a package that contains
multiple configurations of the same project.

First, we want to ensure that the debug and release builds use different
names for the libraries that will be installed. Let\'s use
[d]{.title-ref} as the postfix for the debug libraries.

Set [CMAKE_DEBUG_POSTFIX](https://cmake.org/cmake/help/latest/variable/CMAKE_DEBUG_POSTFIX.html#variable:CMAKE_DEBUG_POSTFIX) near the
beginning of the top-level `CMakeLists.txt` file:

::: {#CMakeLists.txt-CMAKE_DEBUG_POSTFIX-variable .literalinclude caption="CMakeLists.txt" language="cmake" start-after="project(Tutorial VERSION 1.0)" end-before="target_compile_features(tutorial_compiler_flags"}
Complete/CMakeLists.txt
:::

And the [DEBUG_POSTFIX](https://cmake.org/cmake/help/latest/prop_tgt/DEBUG_POSTFIX.html#prop_tgt:DEBUG_POSTFIX) property on
the tutorial executable:

::: {#CMakeLists.txt-DEBUG_POSTFIX-property .literalinclude caption="CMakeLists.txt" language="cmake" start-after="# add the executable" end-before="# add the binary tree to the search path for include files"}
Complete/CMakeLists.txt
:::

Let\'s also add version numbering to the `MathFunctions` library. In
[MathFunctions/CMakeLists.txt`, set the `VERSION](https://cmake.org/cmake/help/latest/prop_tgt/MathFunctions/CMakeLists.txt`, set the `VERSION.html#prop_tgt:MathFunctions/CMakeLists.txt`, set the `VERSION) and [SOVERSION](https://cmake.org/cmake/help/latest/prop_tgt/SOVERSION.html#prop_tgt:SOVERSION)
properties:

::: {#MathFunctions/CMakeLists.txt-VERSION-properties .literalinclude caption="MathFunctions/CMakeLists.txt" language="cmake" start-after="# setup the version numbering" end-before="# install libs"}
Complete/MathFunctions/CMakeLists.txt
:::

From the `Step12` directory, create `debug` and `release`
subdirectories. The layout will look like:

``` none
- Step12
   - debug
   - release
```

Now we need to setup debug and release builds. We can use
[CMAKE_BUILD_TYPE](https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html#variable:CMAKE_BUILD_TYPE) to set the
configuration type:

```bash
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
cd ../release
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

Now that both the debug and release builds are complete, we can use a
custom configuration file to package both builds into a single release.
In the `Step12` directory, create a file called
`MultiCPackConfig.cmake`. In this file, first include the default
configuration file that was created by the
[cmake  <cmake (1)>](https://cmake.org/cmake/help/latest/manual/cmake .1.html#manual:cmake (1)) executable.

Next, use the `CPACK_INSTALL_CMAKE_PROJECTS` variable to specify which
projects to install. In this case, we want to install both debug and
release.

::: {#MultiCPackConfig.cmake .literalinclude caption="MultiCPackConfig.cmake" language="cmake"}
Complete/MultiCPackConfig.cmake
:::

From the [Step12` directory, run `cpack <Step12` directory, run `cpack(1)>](https://cmake.org/cmake/help/latest/manual/Step12` directory, run `cpack.1.html#manual:Step12` directory, run `cpack(1)) specifying our custom configuration file with the
`config` option:

```bash
cpack --config MultiCPackConfig.cmake
```
