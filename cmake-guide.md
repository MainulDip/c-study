## Overview:
This is a high level overview of CMake Build System.
Docs: https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#target-usage-requirements
### Binary Targets:
Executables and libraries are defined using the add_executable() and add_library() commands. The resulting binary files have appropriate PREFIX, SUFFIX and extensions for the platform targeted. Dependencies between binary targets are expressed using the target_link_libraries() command:
```txt
add_library(archive archive.cpp zip.cpp lzma.cpp)
add_executable(zipapp zipapp.cpp)
target_link_libraries(zipapp archive)
```
archive is defined as a STATIC library -- an archive containing objects compiled from archive.cpp, zip.cpp, and lzma.cpp. zipapp is defined as an executable formed by compiling and linking zipapp.cpp. When linking the zipapp executable, the archive static library is linked in.
### Library Types:
* Static : 
   By default, the add_library() command defines a STATIC library, unless a type is specified. It is linkable and extendable with other libraries and doesn't require export of any symbol (like shared).
```txt
add_library(archive archive.cpp zip.cpp lzma.cpp)
add_executable(zipapp zipapp.cpp)
target_link_libraries(zipapp archive)
```

* Shared :
   Similar to Static Library, but CMake expects SHARED libraries to export at least one symbol (e.g. Windows resource DLL, C++/CLI DLL).
```txt
add_library(MyFramework SHARED MyFramework.cpp)
set_target_properties(MyFramework PROPERTIES
  FRAMEWORK TRUE
  FRAMEWORK_VERSION A # Version "A" is macOS convention
  MACOSX_FRAMEWORK_IDENTIFIER org.cmake.MyFramework
)
```
* Module : 
   A module library, i.e. plugin, adds additional support at runtime but isn't required compile time. But shared libraries are specified by the developer at compile-time and must be present for the application to run, even though their methods are loaded at runtime. So Module Libraries are not linkable by linkers. Shared library can be linked.

* Object :
   An object library compiles source files but does not archive or link their object files into a library. Instead other targets created by add_library or add_executable() may reference the objects using an expression of the form $<TARGET_OBJECTS:objlib> as a source, where objlib is the object library name.

   ```txt
   add_library(archive OBJECT archive.cpp zip.cpp lzma.cpp)

   add_library(archiveExtras STATIC $<TARGET_OBJECTS:archive> extras.cpp)

   add_executable(test_exe $<TARGET_OBJECTS:archive> test.cpp)
   ```

   Alternatively, object libraries may be linked into other targets:
   ```txt
   add_library(archive OBJECT archive.cpp zip.cpp lzma.cpp)

   add_library(archiveExtras STATIC extras.cpp)
   target_link_libraries(archiveExtras PUBLIC archive)

   add_executable(test_exe test.cpp)
   target_link_libraries(test_exe archive)
   ```


