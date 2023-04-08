#include <stdio.h>
#include <stdlib.h>

// if the function's return type is anything other than void, put signature (prototyping) before the main function
double cube(double num);

int main()
{
    sayHi("World");

    printf("cube(7) = %f\n", cube(7.0));
    return 0;
}

// for void return type, header is not required
void sayHi (char name[]) {
    printf("Hello %s!\n", name);
}

double cube(double num) {
    double result = num * num * num;
    return result;
}
