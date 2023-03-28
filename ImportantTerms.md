### MinGw:
It is a tool chain, consist of GCC, linker, objects + header + library, and debugger. MinGW rewrites programs so that they include inside themselves everything related to POSIX to OS mapping.

### CgyWin:
It adds to windows a library (code and headers) that add the POSIX interface to windows (translating the POSIX calls into Windows calls) and port all the GNU programs (Linux based) by compiling them to use that library.

### MSYS:
MSYS is an application that gives the user a Bourne shell that can run configure scripts and Makefiles. No compilers come with MSYS. In the Cygwin, MinGW, and MSYS hierarchy, it is at the bottom the food chain in terms of tools provided.

### POSIX:
POSIX is a programming C interface for operating systems (among other things, like Shell and utilities). It stands for "Portable Operating System Interface" It's a family of standards specified by IEEE for maintaining compatibility among operating systems.

* POSIX presents the OS to a hosted program as a set of callable C functions.

* GCC is a compiler suite common on systems that offer a POSIX interface.

Unix and later Linux implements such interfaces in themselves, Windows natively - doesn't. It has its own way to manage operating system entities (Win32). Mac OS also doesn't.


### MSVC:
Microsoft Visual C++ is a compiler for the C, C++ and C++/CX programming languages by Microsoft. MSVC is proprietary software; it was originally a standalone product but later became a part of Visual Studio and made available in both trialware and freeware forms.

### Unix vs Linux (Unix like):
Unix is closed source (made by AT&T, came before Linux), where Linux is open source.