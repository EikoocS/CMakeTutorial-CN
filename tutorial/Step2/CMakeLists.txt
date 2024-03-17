cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本号
project(Tutorial VERSION 1.0)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 检查是否使用了自定义的 MathFunctions 库
configure_file(TutorialConfig.h.in TutorialConfig.h)

# TODO 2: 使用 add_subdirectory() 添加 MathFunctions 子目录

# 添加可执行文件
add_executable(Tutorial tutorial.cxx)

# TODO 3: 使用 target_link_libraries() 添加 MathFunctions 到 Tutorial

# TODO 4: 使用 target_include_directories() 添加 MathFunctions 到 Tutorial
# 提示：使用 ${PROJECT_BINARY_DIR} 指向编译目录

# 添加二进制目录，以便我们找到 TutorialConfig.h 以及 MathFunctions.h
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
