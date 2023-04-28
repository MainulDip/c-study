## Overview:
CMake is not a package manager, it's a cross platform build generator, closest we can get like a package manager. It is used to 
 - structure and build c/c++ projects (cross platform, win, linux)
 - integrate third party dependencies
 - orchestrate tests
 - package projects
 - cmake generates platform specific makefile, 


NB: Conan is a package manager for C/C++ and utilize CMake under the hood.

### CMakeLists.txt and Basic Config:
Is the entry point for CMake. The name should be a exact match.

 * start with cmake_minimum_required(version)
 * Define the Compiler:
    - for c++ : set( CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe" )
    - for c : set( CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe" )
 * then define the project and type : project(ProjectName C/CXX)
 * then : add_executable(ProjectName EntryPoint.cxx)
### Building Project:
* create a build directory, cd into it then run ( as if CMakeLists.txt is on parent directory )
 - cmake .. -G "MinGW Makefiles"
 - cmake --build . || or cmake -B [build directory] -S [source directory]
* For Project in Visual Studio, this will generate a .sln file (visual studio project file)
 - cmake .. -G 'Visual Studio 17 2022'
### Specifying C/C++ Standard:
CMake's special variables start with "CMAKE_", this should be reserved naming convention that should not be used for custom naming.
```txt
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

### Data passing (Version Number):

