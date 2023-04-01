#include <stdio.h>
#include <stdlib.h>

int main()
{
    double num1, num2;
    printf("Enter first Number: ");
    scanf("%lf", &num1);

    printf("Enter second Number: ");
    scanf("%lf", &num2);

    printf("Answer: %f", num1 + num2);

    return 0;
}
