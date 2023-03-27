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

    float cost = 77.77;
    printf("\nPrinting double value by %%f as cost = %f", cost); // 77.770000
    printf("\nPrinting double value by %%.2f as cost = %.2f", cost); // 77.77
    printf("\nPrinting double value by %%.6g as cost = %.6g", cost); // 77.77


    return 0;
}
