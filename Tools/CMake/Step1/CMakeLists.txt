# Task 1 (must be first command): Set the minimum required version of CMake to be 3.10
cmake_minimum_required(VERSION 3.10)

# Task 2: Set Compiler
set( CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe" )
set( CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe" )

# Task 3: Create a project named Tutorial
project(Tutorial VERSION 1.0 LANGUAGES CXX)

# TODO 7: Set the project version number as 1.0 in the above project command

# TODO 6: Set the variable CMAKE_CXX_STANDARD to 11
#         and the variable CMAKE_CXX_STANDARD_REQUIRED to True
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TODO 8: Use configure_file to configure and 
# copy TutorialConfig.h.in to TutorialConfig.h
configure_file(TutorialConfig.h.in TutorialConfig.h)

# TODO 3: Add an executable called Tutorial to the project
# Hint: Be sure to specify the source file as tutorial.cxx
add_executable(Tutorial tutorial.cxx)

# TODO 9: Use target_include_directories to include ${PROJECT_BINARY_DIR}
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")