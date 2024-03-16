# Step 2: Adding a Library

At this point, we have seen how to create a basic project using CMake.
In this step, we will learn how to create and use a library in our
project. We will also see how to make the use of our library optional.

## Exercise 1 - Creating a Library

To add a library in CMake, use the [add_library](https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library) command and specify which source files should make up
the library.

Rather than placing all of the source files in one directory, we can
organize our project with one or more subdirectories. In this case, we
will create a subdirectory specifically for our library. Here, we can
add a new `CMakeLists.txt` file and one or more source files. In the top
level `CMakeLists.txt` file, we will use the
[add_subdirectory](https://cmake.org/cmake/help/latest/command/add_subdirectory.html#command:add_subdirectory) command to add the
subdirectory to the build.

Once the library is created, it is connected to our executable target
with [target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories) and
[target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries).

### Goal

Add and use a library.

### Helpful Resources

-   [add_library](https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library)
-   [add_subdirectory](https://cmake.org/cmake/help/latest/command/add_subdirectory.html#command:add_subdirectory)
-   [target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories)
-   [target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries)
-   [PROJECT_SOURCE_DIR](https://cmake.org/cmake/help/latest/variable/PROJECT_SOURCE_DIR.html#variable:PROJECT_SOURCE_DIR)

### Files to Edit

-   `CMakeLists.txt`
-   `tutorial.cxx`
-   `MathFunctions/CMakeLists.txt`

### Getting Started

In this exercise, we will add a library to our project that contains our
own implementation for computing the square root of a number. The
executable can then use this library instead of the standard square root
function provided by the compiler.

For this tutorial we will put the library into a subdirectory called
`MathFunctions`. This directory already contains the header files
`MathFunctions.h` and `mysqrt.h`. Their respective source files
`MathFunctions.cxx` and `mysqrt.cxx` are also provided. We will not need
to modify any of these files. `mysqrt.cxx` has one function called
`mysqrt` that provides similar functionality to the compiler\'s `sqrt`
function. `MathFunctions.cxx` contains one function `sqrt` which serves
to hide the implementation details of `sqrt`.

From the `Help/guide/tutorial/Step2` directory, start with `TODO 1` and
complete through `TODO 6`.

First, fill in the one line `CMakeLists.txt` in the `MathFunctions`
subdirectory.

Next, edit the top level `CMakeLists.txt`.

Finally, use the newly created `MathFunctions` library in `tutorial.cxx`

### Build and Run

Run the [cmake  <cmake (1)>](https://cmake.org/cmake/help/latest/manual/cmake .1.html#manual:cmake (1)) executable
or the [cmake-gui <cmake-gui(1)>](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) to
configure the project and then build it with your chosen build tool.

Below is a refresher of what that looks like from the command line:

``` console
mkdir Step2_build
cd Step2_build
cmake ../Step2
cmake --build .
```

Try to use the newly built `Tutorial` and ensure that it is still
producing accurate square root values.

### Solution

In the `CMakeLists.txt` file in the `MathFunctions` directory, we create
a library target called `MathFunctions` with
[add_library](https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library). The source files for
the library are passed as an argument to [add_library](https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library). This looks like the following line:

```html
<details><summary>TODO 1: Click to show/hide answer</summary>
```
``` {#MathFunctions/CMakeLists.txt-add_library .cmake caption="TODO 1: MathFunctions/CMakeLists.txt"}
add_library(MathFunctions MathFunctions.cxx mysqrt.cxx)
```

```html
</details>
```
To make use of the new library we will add an
[add_subdirectory](https://cmake.org/cmake/help/latest/command/add_subdirectory.html#command:add_subdirectory) call in the
top-level `CMakeLists.txt` file so that the library will get built.

```html
<details><summary>TODO 2: Click to show/hide answer</summary>
```
``` {#CMakeLists.txt-add_subdirectory .cmake caption="TODO 2: CMakeLists.txt"}
add_subdirectory(MathFunctions)
```

```html
</details>
```
Next, the new library target is linked to the executable target using
[target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries).

```html
<details><summary>TODO 3: Click to show/hide answer</summary>
```
``` {#CMakeLists.txt-target_link_libraries .cmake caption="TODO 3: CMakeLists.txt"}
target_link_libraries(Tutorial PUBLIC MathFunctions)
```

```html
</details>
```
Finally we need to specify the library\'s header file location. Modify
the existing [target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories) call to add the `MathFunctions` subdirectory as an
include directory so that the `MathFunctions.h` header file can be
found.

```html
<details><summary>TODO 4: Click to show/hide answer</summary>
```
``` {#CMakeLists.txt-target_include_directories-step2 .cmake caption="TODO 4: CMakeLists.txt"}
target_include_directories(Tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctions"
                          )
```

```html
</details>
```
Now let\'s use our library. In `tutorial.cxx`, include
`MathFunctions.h`:

```html
<details><summary>TODO 5: Click to show/hide answer</summary>
```
::: {#CMakeLists.txt-include-MathFunctions.h .literalinclude caption="TODO 5: tutorial.cxx" language="cmake" start-after="#include <string>" end-before="#include \"TutorialConfig.h\""}
Step3/tutorial.cxx
:::

```html
</details>
```
Lastly, replace `sqrt` with the wrapper function `mathfunctions::sqrt`.

```html
<details><summary>TODO 6: Click to show/hide answer</summary>
```
::: {#CMakeLists.txt-option .literalinclude caption="TODO 6: tutorial.cxx" language="cmake" start-after="const double inputValue = std::stod(argv[1]);" end-before="std::cout"}
Step3/tutorial.cxx
:::

```html
</details>
```
## Exercise 2 - Adding an Option

Now let us add an option in the MathFunctions library to allow
developers to select either the custom square root implementation or the
built in standard implementation. While for the tutorial there really
isn\'t any need to do so, for larger projects this is a common
occurrence.

CMake can do this using the [option](https://cmake.org/cmake/help/latest/command/option.html#command:option)
command. This gives users a variable which they can change when
configuring their cmake build. This setting will be stored in the cache
so that the user does not need to set the value each time they run CMake
on a build directory.

### Goal

Add the option to build without `MathFunctions`.

### Helpful Resources

-   [if](https://cmake.org/cmake/help/latest/command/if.html#command:if)
-   [option](https://cmake.org/cmake/help/latest/command/option.html#command:option)
-   [target_compile_definitions](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html#command:target_compile_definitions)

### Files to Edit

-   `MathFunctions/CMakeLists.txt`
-   `MathFunctions/MathFunctions.cxx`

### Getting Started

Start with the resulting files from Exercise 1. Complete `TODO 7`
through `TODO 14`.

First create a variable `USE_MYMATH` using the
[option](https://cmake.org/cmake/help/latest/command/option.html#command:option) command in
`MathFunctions/CMakeLists.txt`. In that same file, use that option to
pass a compile definition to the `MathFunctions` library.

Then, update `MathFunctions.cxx` to redirect compilation based on
`USE_MYMATH`.

Lastly, prevent `mysqrt.cxx` from being compiled when `USE_MYMATH` is on
by making it its own library inside of the `USE_MYMATH` block of
`MathFunctions/CMakeLists.txt`.

### Build and Run

Since we have our build directory already configured from Exercise 1, we
can rebuild by simply calling the following:

``` console
cd ../Step2_build
cmake --build .
```

Next, run the `Tutorial` executable on a few numbers to verify that
it\'s still correct.

Now let\'s update the value of `USE_MYMATH` to `OFF`. The easiest way is
to use the [cmake-gui <cmake-gui(1)>](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1))
or [ccmake <ccmake(1)>](https://cmake.org/cmake/help/latest/manual/ccmake.1.html#manual:ccmake(1)) if you\'re in
the terminal. Or, alternatively, if you want to change the option from
the command-line, try:

``` console
cmake ../Step2 -DUSE_MYMATH=OFF
```

Now, rebuild the code with the following:

``` console
cmake --build .
```

Then, run the executable again to ensure that it still works with
`USE_MYMATH` set to `OFF`. Which function gives better results, `sqrt`
or `mysqrt`?

### Solution

The first step is to add an option to `MathFunctions/CMakeLists.txt`.
This option will be displayed in the
[cmake-gui <cmake-gui(1)>](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) and
[ccmake <ccmake(1)>](https://cmake.org/cmake/help/latest/manual/ccmake.1.html#manual:ccmake(1)) with a default
value of `ON` that can be changed by the user.

```html
<details><summary>TODO 7: Click to show/hide answer</summary>
```
::: {#CMakeLists.txt-option-library-level .literalinclude caption="TODO 7: MathFunctions/CMakeLists.txt" language="cmake" start-after="# should we use our own math functions" end-before="if (USE_MYMATH)"}
Step3/MathFunctions/CMakeLists.txt
:::

```html
</details>
```
Next, make building and linking our library with `mysqrt` function
conditional using this new option.

Create an [if](https://cmake.org/cmake/help/latest/command/if.html#command:if) statement which checks
the value of [USE_MYMATH`. Inside the `if](https://cmake.org/cmake/help/latest/command/USE_MYMATH`. Inside the `if.html#command:USE_MYMATH`. Inside the `if) block, put the
[target_compile_definitions](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html#command:target_compile_definitions) command
with the compile definition `USE_MYMATH`.

```html
<details><summary>TODO 8: Click to show/hide answer</summary>
```
``` {#CMakeLists.txt-USE_MYMATH .cmake caption="TODO 8: MathFunctions/CMakeLists.txt"}
if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
endif()
```

```html
</details>
```
When `USE_MYMATH` is `ON`, the compile definition `USE_MYMATH` will be
set. We can then use this compile definition to enable or disable
sections of our source code.

The corresponding changes to the source code are fairly straightforward.
In `MathFunctions.cxx`, we make `USE_MYMATH` control which square root
function is used:

```html
<details><summary>TODO 9: Click to show/hide answer</summary>
```
::: {#MathFunctions-USE_MYMATH-if .literalinclude caption="TODO 9: MathFunctions/MathFunctions.cxx" language="c++" start-after="which square root function should we use?" end-before="}"}
Step3/MathFunctions/MathFunctions.cxx
:::

```html
</details>
```
Next, we need to include `mysqrt.h` if `USE_MYMATH` is defined.

```html
<details><summary>TODO 10: Click to show/hide answer</summary>
```
::: {#MathFunctions-USE_MYMATH-if-include .literalinclude caption="TODO 10: MathFunctions/MathFunctions.cxx" language="c++" start-after="include <cmath>" end-before="namespace mathfunctions"}
Step3/MathFunctions/MathFunctions.cxx
:::

```html
</details>
```
Finally, we need to include `cmath` now that we are using `std::sqrt`.

```html
<details><summary>TODO 11: Click to show/hide answer</summary>
```
``` {#tutorial.cxx-include_cmath .c++ caption="TODO 11 : MathFunctions/MathFunctions.cxx"}
#include <cmath>
```

```html
</details>
```
At this point, if `USE_MYMATH` is `OFF`, `mysqrt.cxx` would not be used
but it will still be compiled because the `MathFunctions` target has
`mysqrt.cxx` listed under sources.

There are a few ways to fix this. The first option is to use
[target_sources](https://cmake.org/cmake/help/latest/command/target_sources.html#command:target_sources) to add `mysqrt.cxx`
from within the `USE_MYMATH` block. Another option is to create an
additional library within the `USE_MYMATH` block which is responsible
for compiling `mysqrt.cxx`. For the sake of this tutorial, we are going
to create an additional library.

First, from within `USE_MYMATH` create a library called `SqrtLibrary`
that has sources `mysqrt.cxx`.

```html
<details><summary>TODO 12: Click to show/hide answer</summary>
```
::: {#MathFunctions/CMakeLists.txt-add_library-SqrtLibrary .literalinclude caption="TODO 12 : MathFunctions/CMakeLists.txt" language="cmake" start-after="# library that just does sqrt" end-before="# TODO 7: Link"}
Step3/MathFunctions/CMakeLists.txt
:::

```html
</details>
```
Next, we link `SqrtLibrary` onto `MathFunctions` when `USE_MYMATH` is
enabled.

```html
<details><summary>TODO 13: Click to show/hide answer</summary>
```
::: {#MathFunctions/CMakeLists.txt-target_link_libraries-SqrtLibrary .literalinclude caption="TODO 13 : MathFunctions/CMakeLists.txt" language="cmake" start-after="to tutorial_compiler_flags" end-before="endif()"}
Step3/MathFunctions/CMakeLists.txt
:::

```html
</details>
```
Finally, we can remove `mysqrt.cxx` from our `MathFunctions` library
source list because it will be pulled in when `SqrtLibrary` is included.

```html
<details><summary>TODO 14: Click to show/hide answer</summary>
```
::: {#MathFunctions/CMakeLists.txt-remove-mysqrt.cxx-MathFunctions .literalinclude caption="TODO 14 : MathFunctions/CMakeLists.txt" language="cmake" end-before="# TODO 1:"}
Step3/MathFunctions/CMakeLists.txt
:::

```html
</details>
```
With these changes, the `mysqrt` function is now completely optional to
whoever is building and using the `MathFunctions` library. Users can
toggle `USE_MYMATH` to manipulate what library is used in the build.
