#include<stdlib.h>
#include<stdio.h>

/**
 * Passing Compilation Arguments, using shell
 * first compile this file into this directory by -> gcc CompilerArgs.c -o outputFileName -std=c99
 * then run -> outputFileName.exe Hello World
 * it will print the output of the file
 * if no output filename is supplied, a.exe (windows) will be the output file name
*/

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++) {
        printf("arg %d : %s\n", i, argv[i]);
    }
    return 0;
}

/** Output:
 * arg 0 : <filename.exe>
 * arg 1 : Hello
 * arg 2 : World
*/