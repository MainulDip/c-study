#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr; // FILE is a special pointer data type to work with files in c
    char filename[] = "test.txt";


    /**
    * Creating and writing to the file
    */
    fptr = fopen(filename, "w"); // "w" mode indicates to create a file if does not exists

    // writing to the file
    fprintf(fptr, "First Line\n");

    // close the file to avoid memory leaks, save the file properly and let other program use the file without errors
    fclose(fptr);

    /**
    * Appending to the file
    */
    fptr = fopen(filename, "a");
    fprintf(fptr, "Second Line\n");
    fclose(fptr);

    /**
    * Reading from the file
    */
    char fileContent1[100], fileContent2[100], fileContent3[100], fileContent4[100];
    fptr = fopen(filename, "r");

    /**
    * on first call fgets return the pointer address of the first character (declared variable's address) of the first line.
    * on second call * fgets return the pointer address of the first character of the second line.
    * and so on for subsequent request and finally it return the 0 when there is no new line left.
    * this way a while loop can be used to read line one by one : while (fgets(fileline, 100, fptr)) { printf("%s\n", fileline);}
    */
    // testing the fgets return value
    printf("%p\n", fgets(fileContent1, 100, fptr)); // 000000000061FDA0
    printf("%p\n", fgets(fileContent2, 100, fptr)); // 000000000061FD30
    printf("%p\n", fgets(fileContent3, 100, fptr)); // 0000000000000000
    printf("%p\n", fgets(fileContent4, 100, fptr)); // 0000000000000000



    printf("%s", fileContent1); // First Line
    printf("%s", fileContent2); // Second Line
    fclose(fptr);

    return 0;
}
