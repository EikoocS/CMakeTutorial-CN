# Step 7: Adding System Introspection

Let us consider adding some code to our project that depends on features
the target platform may not have. For this example, we will add some
code that depends on whether or not the target platform has the `log`
and `exp` functions. Of course almost every platform has these functions
but for this tutorial assume that they are not common.

## Exercise 1 - Assessing Dependency Availability

### Goal

Change implementation based on available system dependencies.

### Helpful Resources

-   [CheckCXXSourceCompiles](https://cmake.org/cmake/help/latest/module/CheckCXXSourceCompiles.html#module:CheckCXXSourceCompiles)
-   [target_compile_definitions](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html#command:target_compile_definitions)

### Files to Edit

-   `MathFunctions/CMakeLists.txt`
-   `MathFunctions/mysqrt.cxx`

### Getting Started

The starting source code is provided in the `Step7` directory. In this
exercise, complete `TODO 1` through `TODO 5`.

Start by editing `MathFunctions/CMakeLists.txt`. Include the
[CheckCXXSourceCompiles](https://cmake.org/cmake/help/latest/module/CheckCXXSourceCompiles.html#module:CheckCXXSourceCompiles) module. Then,
use `check_cxx_source_compiles` to determine whether `log` and `exp` are
available from `cmath`. If they are available, use
[target_compile_definitions](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html#command:target_compile_definitions) to
specify `HAVE_LOG` and `HAVE_EXP` as compile definitions.

In the `MathFunctions/mysqrt.cxx`, include `cmath`. Then, if the system
has `log` and `exp`, use them to compute the square root.

### Build and Run

Make a new directory called `Step7_build`. Run the
[cmake  <cmake (1)>](https://cmake.org/cmake/help/latest/manual/cmake .1.html#manual:cmake (1)) executable or the
[cmake-gui <cmake-gui(1)>](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) to configure
the project and then build it with your chosen build tool and run the
`Tutorial` executable.

This can look like the following:

``` console
mkdir Step7_build
cd Step7_build
cmake ../Step7
cmake --build .
```

Which function gives better results now, `sqrt` or `mysqrt`?

### Solution

In this exercise we will use functions from the
[CheckCXXSourceCompiles](https://cmake.org/cmake/help/latest/module/CheckCXXSourceCompiles.html#module:CheckCXXSourceCompiles) module so
first we must include it in `MathFunctions/CMakeLists.txt`.

```html
<details><summary>TODO 1: Click to show/hide answer</summary>
```
::: {#MathFunctions/CMakeLists.txt-include-check_cxx_source_compiles .literalinclude caption="TODO 1: MathFunctions/CMakeLists.txt" language="cmake" start-after="# does this system provide the log and exp functions?" end-before="check_cxx_source_compiles"}
Step8/MathFunctions/CMakeLists.txt
:::

```html
</details>
```
Then test for the availability of `log` and `exp` using
`check_cxx_compiles_source`. This function lets us try compiling simple
code with the required dependency prior to the true source code
compilation. The resulting variables `HAVE_LOG` and `HAVE_EXP` represent
whether those dependencies are available.

```html
<details><summary>TODO 2: Click to show/hide answer</summary>
```
::: {#MathFunctions/CMakeLists.txt-check_cxx_source_compiles .literalinclude caption="TODO 2: MathFunctions/CMakeLists.txt" language="cmake" start-after="include(CheckCXXSourceCompiles)" end-before="# add compile definitions"}
Step8/MathFunctions/CMakeLists.txt
:::

```html
</details>
```
Next, we need to pass these CMake variables to our source code. This
way, our source code can tell what resources are available. If both
`log` and `exp` are available, use
[target_compile_definitions](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html#command:target_compile_definitions) to
specify `HAVE_LOG` and `HAVE_EXP` as `PRIVATE` compile definitions.

```html
<details><summary>TODO 3: Click to show/hide answer</summary>
```
::: {#MathFunctions/CMakeLists.txt-target_compile_definitions .literalinclude caption="TODO 3: MathFunctions/CMakeLists.txt" language="cmake" start-after="# add compile definitions" end-before="# state"}
Step8/MathFunctions/CMakeLists.txt
:::

```html
</details>
```
Since we may be using `log` and `exp`, we need to modify `mysqrt.cxx` to
include `cmath`.

```html
<details><summary>TODO 4: Click to show/hide answer</summary>
```
::: {#MathFunctions/mysqrt.cxx-include-cmath .literalinclude caption="TODO 4: MathFunctions/mysqrt.cxx" language="c++" start-after="#include \"mysqrt.h\"" end-before="include <iostream>"}
Step8/MathFunctions/mysqrt.cxx
:::

```html
</details>
```
If `log` and `exp` are available on the system, then use them to compute
the square root in the `mysqrt` function. The `mysqrt` function in
`MathFunctions/mysqrt.cxx` will look as follows:

```html
<details><summary>TODO 5: Click to show/hide answer</summary>
```
::: {#MathFunctions/mysqrt.cxx-ifdef .literalinclude caption="TODO 5: MathFunctions/mysqrt.cxx" language="c++" start-after="// if we have both log and exp then use them" end-before="return result;"}
Step8/MathFunctions/mysqrt.cxx
:::

```html
</details>
```