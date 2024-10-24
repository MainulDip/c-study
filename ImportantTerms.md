### POSIX:
POSIX is a programming C interface for operating systems (among other things, like Shell and utilities). It stands for "Portable Operating System Interface" It's a family of standards specified by IEEE for maintaining compatibility among operating systems.

* POSIX presents the OS to a hosted program as a set of callable C functions.

Unix and later Linux implements such interfaces themselves, Windows natively - doesn't. It has its own way to manage operating system entities (Win32). Mac OS also doesn't.
> GCC is a compiler suite common on systems that offer a POSIX interfaces. MinGW or CgyWin provide the compatibility layer with the os providing/implementing/linking the POSIX interfaces. Through these GCC works together with the underlying oss.

### MinGw:
It is a tool chain, consist of GCC, linker, objects + header + library, and debugger. MinGW rewrites programs so that they include inside themselves everything related to POSIX to OS mapping

### CygWin:
It adds to windows a library (code and headers) that add the POSIX interface to windows (translating the POSIX calls into Windows calls) and port all the GNU programs (Linux based) by compiling them to use that library.

### MSYS (M-Sys or Minimal System):
It's a a component of MinGW. MSYS is an application that gives the user a command shell based on POSIX Command Shell. It allows programmers to run shell scripts that will then run the MinGW gcc compiler and other tools to build applications


### GCC & MSVC:
* GCC: GNU Compiler Collection provides open source compilers and runtime for C, C++, Objective C, Fortran, Go, Java, and Ada.
* MSVC: Microsoft Visual C++ is a compiler for the C, C++ and C++/CX programming languages by Microsoft. MSVC is proprietary software; it was originally a standalone product but later became a part of Visual Studio and made available in both trial-ware and freeware forms.

### Unix vs Linux (Unix like):
Unix is closed source (proprietary, made by AT&T, came before Linux), where Linux is open source.

### Macros:

### Headers:

### Template and template parameter:

### typedef:

### Preprocessor || Compilation || Object Code || Linker || Executable || Runtime:
* https://www.geeksforgeeks.org/cc-preprocessors/

### Generators:
A generator provides a way to create elements "on the fly" without holding them all in memory before we start going over them. Like looping/iterating over a range creates the range elements on the fly one by one on each iteration.
```py
# here range is the generator function, each value is created in range one by one, so it takes less memory

for i in range(10):
    print(i)

# Non generator iteration is done on already created values (ie: array)
# all the values of an array are stored in memory, so it takes more memory
for i in [0,1,2,3,4,5,6,7,8,9]:
    print(i)
```