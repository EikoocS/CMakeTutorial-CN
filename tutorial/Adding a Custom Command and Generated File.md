# Step 8: Adding a Custom Command and Generated File

Suppose, for the purpose of this tutorial, we decide that we never want
to use the platform `log` and `exp` functions and instead would like to
generate a table of precomputed values to use in the `mysqrt` function.
In this section, we will create the table as part of the build process,
and then compile that table into our application.

First, let\'s remove the check for the `log` and `exp` functions in
`MathFunctions/CMakeLists.txt`. Then remove the check for `HAVE_LOG` and
`HAVE_EXP` from `mysqrt.cxx`. At the same time, we can remove
`#include <cmath>`.

In the `MathFunctions` subdirectory, a new source file named
`MakeTable.cxx` has been provided to generate the table.

After reviewing the file, we can see that the table is produced as valid
C++ code and that the output filename is passed in as an argument.

The next step is to create `MathFunctions/MakeTable.cmake`. Then, add
the appropriate commands to the file to build the `MakeTable` executable
and then run it as part of the build process. A few commands are needed
to accomplish this.

First, we add an executable for `MakeTable`.

::: {#MathFunctions/MakeTable.cmake-add_executable-MakeTable .literalinclude caption="MathFunctions/MakeTable.cmake" language="cmake" start-after="# first we add the executable that generates the table" end-before="target_link_libraries"}
Step9/MathFunctions/MakeTable.cmake
:::

After creating the executable, we add the `tutorial_compiler_flags` to
our executable using [target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries).

::: {#MathFunctions/MakeTable.cmake-link-tutorial-compiler-flags .literalinclude caption="MathFunctions/MakeTable.cmake" language="cmake" start-after="add_executable" end-before="# add the command to generate"}
Step9/MathFunctions/MakeTable.cmake
:::

Then we add a custom command that specifies how to produce `Table.h` by
running MakeTable.

::: {#MathFunctions/MakeTable.cmake-add_custom_command-Table.h .literalinclude caption="MathFunctions/MakeTable.cmake" language="cmake" start-after="# add the command to generate the source code"}
Step9/MathFunctions/MakeTable.cmake
:::

Next we have to let CMake know that `mysqrt.cxx` depends on the
generated file `Table.h`. This is done by adding the generated `Table.h`
to the list of sources for the library `SqrtLibrary`.

::: {#MathFunctions/CMakeLists.txt-add_library-Table.h .literalinclude caption="MathFunctions/CMakeLists.txt" language="cmake" start-after="# library that just does sqrt" end-before="# state that we depend on"}
Step9/MathFunctions/CMakeLists.txt
:::

We also have to add the current binary directory to the list of include
directories so that `Table.h` can be found and included by `mysqrt.cxx`.

::: {#MathFunctions/CMakeLists.txt-target_include_directories-Table.h .literalinclude caption="MathFunctions/CMakeLists.txt" language="cmake" start-after="# state that we depend on our bin" end-before="target_link_libraries"}
Step9/MathFunctions/CMakeLists.txt
:::

As the last step, we need to include `MakeTable.cmake` at the top of the
`MathFunctions/CMakeLists.txt`.

::: {#MathFunctions/CMakeLists.txt-include-MakeTable.cmake .literalinclude caption="MathFunctions/CMakeLists.txt" language="cmake" start-after="# generate Table.h" end-before="# library that just does sqrt"}
Step9/MathFunctions/CMakeLists.txt
:::

Now let\'s use the generated table. First, modify `mysqrt.cxx` to
include `Table.h`. Next, we can rewrite the `mysqrt` function to use the
table:

::: {#MathFunctions/mysqrt.cxx .literalinclude caption="MathFunctions/mysqrt.cxx" language="c++" start-after="// a hack square root calculation using simple operations"}
Step9/MathFunctions/mysqrt.cxx
:::

Run the [cmake  <cmake (1)>](https://cmake.org/cmake/help/latest/manual/cmake .1.html#manual:cmake (1)) executable
or the [cmake-gui <cmake-gui(1)>](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) to
configure the project and then build it with your chosen build tool.

When this project is built it will first build the `MakeTable`
executable. It will then run `MakeTable` to produce `Table.h`. Finally,
it will compile `mysqrt.cxx` which includes `Table.h` to produce the
`MathFunctions` library.

Run the Tutorial executable and verify that it is using the table.
