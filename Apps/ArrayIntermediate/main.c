#include <stdio.h>
#include <stdlib.h>

void printSizeOf(int intArray[]);
void printLength(int intArray[]);

int main(int argc, char* argv[])
{
    int array[7] = { 0, 1, 2, 3, 4, 5, 6 };

    printf("sizeof of array: %d\n", (int) sizeof(array)); // 28

    printf("sizeof of array's first element: %d\n", (int) sizeof(array[0])); // 4
    printf("sizeof of array's first element address: %d\n", (int) sizeof(&array[0])); // 8
    printf("sizeof of array's first element: %d\n", (int) sizeof(&array)); // 8

    printSizeOf(array); // 8
    // An array sent as a parameter to a function is treated as a pointer address, so sizeof will return the pointer's address size, instead of the array's.

    printf("Length of array: %d\n", (int)( sizeof(array) / sizeof(array[0]) )); // 7
    printLength({ 0, 1, 2, 3, 4, 5, 6 }); // 2
}

void printSizeOf(int intArray[])
{
    printf("sizeof of parameter: %d\n", (int) sizeof(intArray)); // 8, address size
    printf("intArray = %d\n", intArray); // 6422016 (memory address)
}

void printLength(int intArray[])
{
    // here intArray is a address, so
    printf("Length of parameter: %d\n", (int)( sizeof(intArray) / sizeof(intArray[0]) ));
    printf("\n\n%d", (int) sizeof(intArray));
}
