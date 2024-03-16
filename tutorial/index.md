# CMake Tutorial

## Introduction

CMake 指南提供一个逐步指南，涵盖了 CMake 可以协助解决的常见构建系统问题。以及提供了示例项目来展示了各个主题间的协同工作。

## Steps

教程文档和源代码示例可以在 CMake 仓库的 Help/guide/tutorial 目录（译注：[<源仓库>](https://gitlab.kitware.com/cmake/cmake/-/tree/master/Help/guide/tutorial) [<Github 镜像>](https://github.com/Kitware/CMake/tree/master/Help/guide/tutorial) [<中文仓库>](#)）中找到。每个步骤都有作为起点的源码，你可以将其拷贝下来，然后跟随教程来一步步将其完善。教程是循序渐进的，因此每一步的源码包含上一步的结果。同样，当实现遇到困难时可以浏览下一步源码来获得参考。

<!-- 这个设计其实挺好的，但原版的描述好奇怪，所以改写比较多-->

 - [第 1 步：基础的起点](./A%20Basic%20Starting%20Point.md)</br>
    学习 CMake 的一些基本语法、命令和变量
 - [第 2 步：添加库](./Adding%20a%20Library.md)</br>
    学习如何在项目中创建和使用库以及如何将库设为可选。
 - [第 3 步：为库添加使用要求](./Adding%20Usage%20Requirements%20for%20a%20Library.md)</br>
    学习如何为库添加使用要求以及用接口库设定 C++ 标准
 - [第 4 步：添加生成器表达式](./Adding%20Generator%20Expressions.md)</br>
    学习生成器表达式，用于在构建系统生成过程中进行评估，以生成每个构建配置的特定信息
 - [第 5 步：安装与测试](./Installing%20and%20Testing.md)</br>
    学习使用 install() 命令指定安装规则
 - [第 6 步：添加测试面板支持](./Adding%20Support%20for%20a%20Testing%20Dashboard.md)</br>
    学习如何将测试测试提交到 [CDash](https://www.cdash.org/)（一款基于网络的开源软件测试服务器）
 - [第 7 步：添加系统检查](./Adding%20System%20Introspection.md)</br>
    学习根据环境的系统依赖关系改变实现方法
 - [第 8 步：添加自定义命令和生成文件](./Adding%20a%20Custom%20Command%20and%20Generated%20File.md)</br>
    学习在构建过程中生成文件并编译入程序
 - [第 9 步：打包一个安装包](./Packaging%20an%20Installer.md)</br>
    学习构建一个安装包（此处的安装包所指包括 .zip 、win下的安装包、NuGet包、RPM包等）
 - [第 10 步：选择静态或动态库](./Selecting%20Static%20or%20Shared%20Libraries.md)</br>
    学习如何使用 BUILD_SHARED_LIBS 变量来控制 add_library() 的默认行为，以及如何控制没有明确类型（STATIC、SHARED、MODULE 或 OBJECT）的库的编译
 - [第 11 步：添加导出配置](./Adding%20Export%20Configuration.md)</br>
    学习如何添加必要的信息，以便其他 CMake 项目可以使用我们的项目，无论是从构建目录、本地安装还是打包后使用
 - [第 12 步：打包为调试和发布模式](./Packaging%20Debug%20and%20Release.md)</br>
    _注意：此示例适用于单配置生成器，不适用于多配置生成器（如 Visual Studio）_</br>
    学习如何设置 CPack 以捆绑多个编译目录，并构建一个包含同一项目多个配置的软件包
