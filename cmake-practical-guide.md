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

### Optional Library Call:
Custom Library can be made optional using CMakes option() call. This gives users a variable which they can change when configuring/running their cmake build. This setting will be stored in the cache so that the user does not need to set the value each time they run CMake on a build directory.

   - This option will be displayed in the cmake-gui and ccmake with a default value and that can be changed by the user while running the build

* Main.cxx source header.h.in (CMake will process it and make it header.h inside build directory) :
   #cmakedefine USE_MYMATH
   // this will be replaced by preprocessor with either "#define VAR" or "#undef VAR" based on Cmake configuration, https://cmake.org/cmake/help/latest/command/configure_file.html#command:configure_file
* Top Level Src (Main.cxx) :
```cxx
// optional includes, check if USE_MYMATH is defined (CMake build argument)
#ifdef USE_MYMATH
#  include "MathFunctions.h"
#endif

// and use inside main func
// optional library function call
#ifdef USE_MYMATH
   const double outputValue = mysqrt(inputValue);
#else
   const double outputValue = sqrt(inputValue);
#endif
```
* Top Level CMakeLists.txt :
```txt
# option(<variable> "<help_text>" [value]) Provide a boolean option that the user can optionally select/send as build argument
# value can be "ON" or "OFF", If no initial <value> is provided, boolean OFF is the default value.

option(USE_MYMATH "Use tutorial provided math implementation" ON)


# Only call add_subdirectory and only add MathFunctions specific values
# to EXTRA_LIBS and EXTRA_INCLUDES if USE_MYMATH is ON.

if(USE_MYMATH)
  add_subdirectory(MathFunctions) # this will build the library based on directory
  list(APPEND EXTRA_LIBS MathFunctions) # just storing the value as "MathFunctions"
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions") # just storing value like above
endif()

# like set() command, the list() command creates new variable values in the current scope
# list( subcommand variable_name variable_value )
# A list in cmake is a ; separated group of strings.
# subcommands can be APPEND, INSERT, FILTER, PREPEND, POP_BACK, POP_FRONT, REMOVE_AT, REMOVE_ITEM, REMOVE_DUPLICATES, REVERSE and SOR
# https://cmake.org/cmake/help/latest/command/list.html#command:list


# if EXTRA_LIBS are set in list, it will return value, otherwise empty
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files, so header files are available to include inside src's Main.cxx
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )
```

### Usages Requirements () :
By Using INTERFACE Usages Requirement inside Library's CMakeLists.txt, the main Source's CMake file does not require to include it again. Linking the Library will aromatically do the job by target_link_libraries.

### Generator expressions :
These are evaluated during build system generation to produce information specific to each build configuration.

Generator expressions may be used to enable conditional linking, conditional definitions used when compiling, conditional include directories and more. The conditions may be based on the build configuration, target properties, platform information or any other queryable information.

* Setting C++ Standard By Using Interface Library.
```txt
# adding interface library called tutorial_compiler_flags to set C++ standard
# use add_library() with the INTERFACE signature
# Add compiler feature cxx_std_11 to tutorial_compiler_flags using target_compile_features()
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# Link to tutorial_compiler_flags with both src and library
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags)
target_link_libraries(MathFunctions tutorial_compiler_flags)
```
### Compiler Warning Flag With Generator Expression:
