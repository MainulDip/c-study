#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Numbers and Math
    int addition = 1 + 2;
    float totalCost = 6 + 4.7;
    double totalCost2 = 7 + 12.34;

    double someAverage = 7 / 6;
    printf("Printing division %f\n", someAverage); // 1.000000
    someAverage = (double) 7 / (float) 6;
    printf("Printing division %f\n", someAverage); // 1.166667

    float multipliesNum = 7 * 7;
    printf("Printing float without defining decimal = %f \n", multipliesNum);

    double numPow = pow(3, 2);
    printf("pow(3,2) = %f \n", numPow);

    double numSqrt = sqrt(47);
    printf("sqrt(47) = %f \n", numSqrt);
    printf("sqrt(47) = %.20f \n", numSqrt);

    long double piValue = 22.00 / 7.00;
    __mingw_printf("M_PI = %.47Lf \n", piValue);

    double a = M_PI;
    printf("Printing pi Value by M_PI = %.7Lf\n", a);

    return 0;
}
