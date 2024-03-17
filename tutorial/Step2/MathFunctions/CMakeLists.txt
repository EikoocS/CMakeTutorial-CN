# TODO 14: 从源代码列表中移除 mysqrt.cxx

# TODO 1: 添加一个名为 MathFunctions 的库，其源代码为 MathFunctions.cxx 和 mysqrt.cxx
# 提示：需要使用 add_library 命令

# TODO 7：使用选项创建变量 USE_MYMATH，并将默认值设为 ON

# TODO 8: 如果 USE_MYMATH 开启，则使用 target_compile_definitions 将 USE_MYMATH 作为预编译定义变量传递给我们的源文件

# TODO 12: 当 USE_MYMATH 开启时，为 SqrtLibrary 添加一个库，源代码为 mysqrt.cxx

# TODO 13：当 USE_MYMATH 启用时，将 SqrtLibrary 链接到 MathFunctions 库
