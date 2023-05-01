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

### File copy/configuration and Data passing:
configure_file(<inputfile.h.in> <outputfile.h>) : Copies an <input> file to an <output> file and substitutes variable values referenced as @VAR@ or ${VAR} in the input file content. The output file will be placed in CMAKE_CURRENT_BINARY_DIR or Build directory. So we also need to add that directory to the list of paths to search for include files by target_include_directories ( ProjectName PUBLIC "${PROJECT_BINARY_DIR}" )

```txt
// inputfile.h.in
#define ProjectName_VERSION_MAJOR @ProjectName_VERSION_MAJOR@
#define ProjectName_VERSION_MINOR @ProjectName_VERSION_MINOR@
// getting from CMakeLists.txt

// CMakeLists.txt
project(ProjectName VERSION 1.0) 
// here cmake will auto Generate variables for Major and Minor Version by ProjectName_VERSION_MAJOR and ProjectName_VERSION_MINOR

// add the build directory where the pre-processor will search for copied files (header files)
target_include_directories ( ProjectName PUBLIC "${PROJECT_BINARY_DIR}" )
// see practical use inside tools/step1/CMakeLists.txt
```

### Adding Library Using CMake:
* The Library Should be on it's own directory with a CMakeLists.txt, which will be called from the top level CMakeLists.txt.

* Library Level CMakeLists.txt :
   - define the library and source file using : add_library(LibraryName sourcefile.cxx)
* Top Level CMakeLists.txt :
   - Specify Library Src File and It's CMakeLists.txt directory by : add_subdirectory(LIbraryDirectory)
   - Link the Library with the Executable by : target_link_libraries(ProjectName PUBLIC LibraryName)
   - Include the Library's Header File Into Searchable Directory by : 
      target_include_directories(ProjectName PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/LibraryDirectory"
                          )
* Main.cxx :
   - Call the library functions by including the Library Header File only as : #include "LibraryHeader.h"
   - Then call the functions (defined inside Library's Header as Signature) from top level cpp code