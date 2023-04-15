#include <stdio.h>

/**
 * Note: this will not work with GCC compiler because GCC does not support #pragma startup or exit.
 * Pragma directives are compiler-specific, they vary from compiler to compiler.
*/
 
void func1();
void func2();
 
#pragma startup func1
#pragma exit func2
 
void func1()
{
    printf("Inside func1()\n");
}
 
void func2()
{
    printf("Inside func2()\n");
}
 
int main()
{
    void func1();
    void func2();
    printf("Inside main()\n");
 
    return 0;
}