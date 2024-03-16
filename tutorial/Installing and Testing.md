# Step 5: Installing and Testing

## Exercise 1 - Install Rules

Often, it is not enough to only build an executable, it should also be
installable. With CMake, we can specify install rules using the
[install](https://cmake.org/cmake/help/latest/command/install.html#command:install) command. Supporting local
installations for your builds in CMake is often as simple as specifying
an install location and the targets and files to be installed.

### Goal

Install the `Tutorial` executable and the `MathFunctions` library.

### Helpful Materials

-   [install](https://cmake.org/cmake/help/latest/command/install.html#command:install)

### Files to Edit

-   `MathFunctions/CMakeLists.txt`
-   `CMakeLists.txt`

### Getting Started

The starting code is provided in the `Step5` directory. In this
exercise, complete `TODO 1` through `TODO 4`.

First, update `MathFunctions/CMakeLists.txt` to install the
`MathFunctions` and `tutorial_compiler_flags` libraries to the `lib`
directory. In that same file, specify the install rules needed to
install `MathFunctions.h` to the `include` directory.

Then, update the top level `CMakeLists.txt` to install the `Tutorial`
executable to the `bin` directory. Lastly, any header files should be
installed to the `include` directory. Remember that `TutorialConfig.h`
is in the [PROJECT_BINARY_DIR](https://cmake.org/cmake/help/latest/variable/PROJECT_BINARY_DIR.html#variable:PROJECT_BINARY_DIR).

### Build and Run

Make a new directory called `Step5_build`. Run the
[cmake <cmake(1)>](https://cmake.org/cmake/help/latest/manual/cmake.1.html#manual:cmake(1)) executable or the
[cmake-gui <cmake-gui(1)>](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) to configure
the project and then build it with your chosen build tool.

Then, run the install step by using the
[--install](https://cmake.org/cmake/help/latest/manual/cmake.1.html#cmdoption-cmake-install) option of
the [cmake  <cmake (1)>](https://cmake.org/cmake/help/latest/manual/cmake .1.html#manual:cmake (1)) command
(introduced in 3.15, older versions of CMake must use `make install`)
from the command line. This step will install the appropriate header
files, libraries, and executables. For example:

``` console
cmake --install .
```

For multi-configuration tools, don\'t forget to use the
[--config](https://cmake.org/cmake/help/latest/manual/cmake.1.html#cmdoption-cmake-build-config)
argument to specify the configuration.

``` console
cmake --install . --config Release
```

If using an IDE, simply build the `INSTALL` target. You can build the
same install target from the command line like the following:

``` console
cmake --build . --target install --config Debug
```

The CMake variable [CMAKE_INSTALL_PREFIX](https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_PREFIX.html#variable:CMAKE_INSTALL_PREFIX) is used to determine the root of where the files will
be installed. If using the [cmake --install](https://cmake.org/cmake/help/latest/manual/cmake.1.html#cmdoption-cmake-install) command, the installation prefix can be overridden via
the [--prefix](https://cmake.org/cmake/help/latest/manual/cmake.1.html#cmdoption-cmake--install-0) argument. For example:

``` console
cmake --install . --prefix "/home/myuser/installdir"
```

Navigate to the install directory and verify that the installed
`Tutorial` runs.

### Solution

The install rules for our project are fairly simple:

-   For `MathFunctions`, we want to install the libraries and header
    file to the `lib` and `include` directories respectively.
-   For the `Tutorial` executable, we want to install the executable and
    configured header file to the `bin` and `include` directories
    respectively.

So to the end of `MathFunctions/CMakeLists.txt` we add:

```html
<details><summary>TODO 1: Click to show/hide answer</summary>
```
::: {#MathFunctions/CMakeLists.txt-install-TARGETS .literalinclude caption="TODO 1: MathFunctions/CMakeLists.txt" language="cmake" start-after="# install libs" end-before="# install include headers"}
Step6/MathFunctions/CMakeLists.txt
:::

```html
</details>
```
and

```html
<details><summary>TODO 2: Click to show/hide answer</summary>
```
::: {#MathFunctions/CMakeLists.txt-install-headers .literalinclude caption="TODO 2: MathFunctions/CMakeLists.txt" language="cmake" start-after="# install include headers"}
Step6/MathFunctions/CMakeLists.txt
:::

```html
</details>
```
The install rules for the `Tutorial` executable and configured header
file are similar. To the end of the top-level `CMakeLists.txt` we add:

```html
<details><summary>TODO 3,4: Click to show/hide answer</summary>
```
::: {#TODO 3,4: CMakeLists.txt-install-TARGETS .literalinclude caption="CMakeLists.txt" language="cmake" start-after="# add the install targets" end-before="# TODO 1: Replace enable_testing() with include(CTest)"}
Step6/CMakeLists.txt
:::

```html
</details>
```
That is all that is needed to create a basic local install of the
tutorial.

## Exercise 2 - Testing Support {#Tutorial Testing Support}

CTest offers a way to easily manage tests for your project. Tests can be
added through the [add_test](https://cmake.org/cmake/help/latest/command/add_test.html#command:add_test) command.
Although it is not explicitly covered in this tutorial, there is a lot
of compatibility between CTest and other testing frameworks such as
[GoogleTest](https://cmake.org/cmake/help/latest/module/GoogleTest.html#module:GoogleTest).

### Goal

Create unit tests for our executable using CTest.

### Helpful Materials

-   [enable_testing](https://cmake.org/cmake/help/latest/command/enable_testing.html#command:enable_testing)
-   [add_test](https://cmake.org/cmake/help/latest/command/add_test.html#command:add_test)
-   [function](https://cmake.org/cmake/help/latest/command/function.html#command:function)
-   [set_tests_properties](https://cmake.org/cmake/help/latest/command/set_tests_properties.html#command:set_tests_properties)
-   [ctest <ctest(1)>](https://cmake.org/cmake/help/latest/manual/ctest.1.html#manual:ctest(1))

### Files to Edit

-   `CMakeLists.txt`

### Getting Started

The starting source code is provided in the `Step5` directory. In this
exercise, complete `TODO 5` through `TODO 9`.

First, we need to enable testing. Next, begin adding tests to our
project using [add_test](https://cmake.org/cmake/help/latest/command/add_test.html#command:add_test). We will work
through adding 3 simple tests and then you can add additional testing as
you see fit.

### Build and Run

Navigate to the build directory and rebuild the application. Then, run
the [ctest](https://cmake.org/cmake/help/latest/manual/ctest.1.html) executable:
[ctest -N](https://cmake.org/cmake/help/latest/manual/ctest.1.html#cmdoption-ctest-N) and
[ctest -VV](https://cmake.org/cmake/help/latest/manual/ctest.1.html#cmdoption-ctest-VV). For multi-config
generators (e.g. Visual Studio), the configuration type must be
specified with the [-C <mode>](https://cmake.org/cmake/help/latest/manual/ctest.1.html#cmdoption-ctest-C) flag. For example, to run tests in Debug mode use
`ctest -C Debug -VV` from the build directory (not the Debug
subdirectory!). Release mode would be executed from the same location
but with a `-C Release`. Alternatively, build the `RUN_TESTS` target
from the IDE.

### Solution

Let\'s test our application. At the end of the top-level
`CMakeLists.txt` file we first need to enable testing with the
[enable_testing](https://cmake.org/cmake/help/latest/command/enable_testing.html#command:enable_testing) command.

```html
<details><summary>TODO 5: Click to show/hide answer</summary>
```
::: {#CMakeLists.txt-enable_testing .literalinclude caption="TODO 5: CMakeLists.txt" language="cmake" start-after="# enable testing" end-before="# does the application run"}
Step6/CMakeLists.txt
:::

```html
</details>
```
With testing enabled, we will add a number of basic tests to verify that
the application is working correctly. First, we create a test using
[add_test](https://cmake.org/cmake/help/latest/command/add_test.html#command:add_test) which runs the `Tutorial`
executable with the parameter 25 passed in. For this test, we are not
going to check the executable\'s computed answer. This test will verify
that application runs, does not segfault or otherwise crash, and has a
zero return value. This is the basic form of a CTest test.

```html
<details><summary>TODO 6: Click to show/hide answer</summary>
```
::: {#CMakeLists.txt-test-runs .literalinclude caption="TODO 6: CMakeLists.txt" language="cmake" start-after="# does the application run" end-before="# does the usage message work"}
Step6/CMakeLists.txt
:::

```html
</details>
```
Next, let\'s use the [PASS_REGULAR_EXPRESSION](https://cmake.org/cmake/help/latest/prop_test/PASS_REGULAR_EXPRESSION.html#prop_test:PASS_REGULAR_EXPRESSION) test property to verify that the output of the test
contains certain strings. In this case, verifying that the usage message
is printed when an incorrect number of arguments are provided.

```html
<details><summary>TODO 7: Click to show/hide answer</summary>
```
::: {#CMakeLists.txt-test-usage .literalinclude caption="TODO 7: CMakeLists.txt" language="cmake" start-after="# does the usage message work?" end-before="# define a function to simplify adding tests"}
Step6/CMakeLists.txt
:::

```html
</details>
```
The next test we will add verifies the computed value is truly the
square root.

```html
<details><summary>TODO 8: Click to show/hide answer</summary>
```
``` {#CMakeLists.txt-test-standard .cmake caption="TODO 8: CMakeLists.txt"}
add_test(NAME StandardUse COMMAND Tutorial 4)
set_tests_properties(StandardUse
  PROPERTIES PASS_REGULAR_EXPRESSION "4 is 2"
  )
```

```html
</details>
```
This one test is not enough to give us confidence that it will work for
all values passed in. We should add more tests to verify this. To easily
add more tests, we make a function called `do_test` that runs the
application and verifies that the computed square root is correct for
given input. For each invocation of `do_test`, another test is added to
the project with a name, input, and expected results based on the passed
arguments.

```html
<details><summary>TODO 9: Click to show/hide answer</summary>
```
::: {#CMakeLists.txt-generalized-tests .literalinclude caption="TODO 9: CMakeLists.txt" language="cmake" start-after="# define a function to simplify adding tests"}
Step6/CMakeLists.txt
:::

```html
</details>
```
