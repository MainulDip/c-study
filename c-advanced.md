### Overview:
Some little more after the basic.

### Header File :
A header file is a file with extension .h which contains C function declarations and macro definitions to be shared between several source files. Including a header file is equal to copying the content of the header file. But it's a good practice (avoid errors/bugs) to keep all the constants, macros, system wide global variables, and function prototypes in the header files and include that header file wherever it is required.

There are 2 types of header
 - compiler/library header : #include <package.h>
 - custom/user defined header: #include "customheader.h"

 ### Once-Only Headers :
 If a header file include twice, compiler will throw error. to avoid  wrapper #ifndef can be used
 ```c
#ifndef HEADER_FILE
#define HEADER_FILE

the entire header file file

#endif
 ```
 ### Computed Includes :
 To include header based on os, this can be used.
 ```c
 // header file
 #if SYSTEM_1
   # include "system_1.h"
#elif SYSTEM_2
   # include "system_2.h"
#elif SYSTEM_3
   ...
#endif

 // c file
 #define SYSTEM_H "system_1.h" // define a macro
...
#include SYSTEM_H
 ```