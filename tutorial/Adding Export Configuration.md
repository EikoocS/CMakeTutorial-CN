# Step 11: Adding Export Configuration

During [Installing and Testing](./Installing%20and%20Testing.md)
of the tutorial we added the ability for CMake to install the library
and headers of the project. During
[Packaging an Installer](./Packaging%20an%20Installer.md) we
added the ability to package up this information so it could be
distributed to other people.

The next step is to add the necessary information so that other CMake
projects can use our project, be it from a build directory, a local
install or when packaged.

The first step is to update our [install(TARGETS)](https://cmake.org/cmake/help/latest/command/install(TARGETS).html#command:install(TARGETS)) commands to not only specify a `DESTINATION` but also an
`EXPORT`. The `EXPORT` keyword generates a CMake file containing code to
import all targets listed in the install command from the installation
tree. So let\'s go ahead and explicitly `EXPORT` the `MathFunctions`
library by updating the `install` command in
`MathFunctions/CMakeLists.txt` to look like:

::: {#MathFunctions/CMakeLists.txt-install-TARGETS-EXPORT .literalinclude caption="MathFunctions/CMakeLists.txt" language="cmake" start-after="# install libs"}
Complete/MathFunctions/CMakeLists.txt
:::

Now that we have `MathFunctions` being exported, we also need to
explicitly install the generated `MathFunctionsTargets.cmake` file. This
is done by adding the following to the bottom of the top-level
`CMakeLists.txt`:

::: {#CMakeLists.txt-install-EXPORT .literalinclude caption="CMakeLists.txt" language="cmake" start-after="# install the configuration targets" end-before="include(CMakePackageConfigHelpers)"}
Complete/CMakeLists.txt
:::

At this point you should try and run CMake. If everything is setup
properly you will see that CMake will generate an error that looks like:

```bash
Target "MathFunctions" INTERFACE_INCLUDE_DIRECTORIES property contains
path:

  "/Users/robert/Documents/CMakeClass/Tutorial/Step11/MathFunctions"

which is prefixed in the source directory.
```

What CMake is trying to say is that during generating the export
information it will export a path that is intrinsically tied to the
current machine and will not be valid on other machines. The solution to
this is to update the `MathFunctions`
[target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories) to
understand that it needs different `INTERFACE` locations when being used
from within the build directory and from an install / package. This
means converting the [target_include_directories](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories) call for `MathFunctions` to look like:

::: {#MathFunctions/CMakeLists.txt-target_include_directories .literalinclude caption="MathFunctions/CMakeLists.txt" language="cmake" start-after="# to find MathFunctions.h, while we don't." end-before="# should we use our own math functions"}
Step12/MathFunctions/CMakeLists.txt
:::

Once this has been updated, we can re-run CMake and verify that it
doesn\'t warn anymore.

At this point, we have CMake properly packaging the target information
that is required but we will still need to generate a
`MathFunctionsConfig.cmake` so that the CMake
[find_package](https://cmake.org/cmake/help/latest/command/find_package.html#command:find_package) command can find our
project. So let\'s go ahead and add a new file to the top-level of the
project called `Config.cmake.in` with the following contents:

::: {#Config.cmake.in .literalinclude caption="Config.cmake.in"}
Step12/Config.cmake.in
:::

Then, to properly configure and install that file, add the following to
the bottom of the top-level `CMakeLists.txt`:

::: {#CMakeLists.txt-install-Config.cmake .literalinclude caption="CMakeLists.txt" language="cmake" start-after="# install the configuration targets" end-before="# generate the config file"}
Step12/CMakeLists.txt
:::

Next, we execute the [configure_package_config_file](https://cmake.org/cmake/help/latest/command/configure_package_config_file.html#command:configure_package_config_file). This command will configure a provided file but with a
few specific differences from the standard
[configure_file](https://cmake.org/cmake/help/latest/command/configure_file.html#command:configure_file) way. To properly
utilize this function, the input file should have a single line with the
text `@PACKAGE_INIT@` in addition to the content that is desired. That
variable will be replaced with a block of code which turns set values
into relative paths. These values which are new can be referenced by the
same name but prepended with a `PACKAGE_` prefix.

::: {#CMakeLists.txt-configure-package-config.cmake .literalinclude caption="CMakeLists.txt" language="cmake" start-after="# install the configuration targets" end-before="# generate the version file"}
Step12/CMakeLists.txt
:::

The [write_basic_package_version_file](https://cmake.org/cmake/help/latest/command/write_basic_package_version_file.html#command:write_basic_package_version_file)
is next. This command writes a file which is used by
[find_package](https://cmake.org/cmake/help/latest/command/find_package.html#command:find_package), documenting the
version and compatibility of the desired package. Here, we use the
`Tutorial_VERSION_*` variables and say that it is compatible with
`AnyNewerVersion`, which denotes that this version or any higher one are
compatible with the requested version.

::: {#CMakeLists.txt-basic-version-file.cmake .literalinclude caption="CMakeLists.txt" language="cmake" start-after="# generate the version file" end-before="# install the generated configuration files"}
Step12/CMakeLists.txt
:::

Finally, set both generated files to be installed:

::: {#CMakeLists.txt-install-configured-files.cmake .literalinclude caption="CMakeLists.txt" language="cmake" start-after="# install the generated configuration files" end-before="# generate the export"}
Step12/CMakeLists.txt
:::

At this point, we have generated a relocatable CMake Configuration for
our project that can be used after the project has been installed or
packaged. If we want our project to also be used from a build directory
we only have to add the following to the bottom of the top level
`CMakeLists.txt`:

::: {#CMakeLists.txt-export .literalinclude caption="CMakeLists.txt" language="cmake" start-after="# needs to be after the install(TARGETS) command"}
Step12/CMakeLists.txt
:::

With this export call we now generate a `MathFunctionsTargets.cmake`,
allowing the configured `MathFunctionsConfig.cmake` in the build
directory to be used by other projects, without needing it to be
installed.
