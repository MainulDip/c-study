## Overview:
CMake is not a package manager, it's a cross platform build generator, closest we can get like a package manager. It is used to 
 - structure and build c/c++ projects (cross platform, win, linux)
 - integrate third party dependencies
 - orchestrate tests
 - package projects
 - cmake generates platform specific makefile, 


NB: Conan is a package manager for C/C++ and utilize CMake under the hood.

### CMakeLists.txt :
Is the entry point for CMake. The name should be a exact match.
### Building Project:
* create a build directory, cd into it then run ( as if CMakeLists.txt is on parent directory )
 - cmake .. -G "MinGW Makefiles"
 - cmake --build . || or cmake -B [build directory] -S [source directory]
* For Project in Visual Studio, this will generate a .sln file (visual studio project file)
 - cmake .. -G 'Visual Studio 17 2022'