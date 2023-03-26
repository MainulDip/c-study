#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");


    // variables
    char someCharacters[] = "NameCharacters";
    printf("Printing Variable someCharacters as %%s %s ", someCharacters);

    // placeholders with printf
    int characterAge = 37;
    printf("\nNow printing digit by %%d and the characterAge = %d\n", characterAge);


    return 0;
}
