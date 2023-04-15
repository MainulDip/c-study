#include <stdio.h> // include directive to add Standard Fies
#include <stdlib.h>

// Macros
#define NUMBER 0 // no semicolon for directives
#define AREA(x,y) (x*y) // macro with parameters

int main()
{
    printf("NUMBER = %d\n", NUMBER);
    printf("AREA = %d\n", AREA(10, 10));


    /**
    * if the Macro name after the #ifdef is defined before, it will run the block
    * if not defined or later make #undef to undefined, the block will not run
    * even if the Macro value is 0, the block will execute
    */
    #ifdef NUMBER
    printf("Printing NUMBER = %d again using the #ifdef\n", NUMBER);
    #endif // NUMBER

    /**
    * #undef to make a existing macro undefined
    * is used the same way, now it will not ptint
    */
    #undef NUMBER // will undefine the existing macro
    #ifdef NUMBER
    printf("The NUMBER Macro is undefined, so this will not print");
    #endif // NUMBER

    return 0;
}
