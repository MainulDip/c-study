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
    float multipliesNum = 7 * 7;
    double numSqrt = sqrt(46);
    double numPow = pow(3, 2);
    long double piValue = 22.00 / 7.00;

    printf("pow(3,2) = %f \n", numPow);
    printf("sqrt(47) = %f \n", numSqrt);
    printf("sqrt(47) = %.20f \n", numSqrt);
    __mingw_printf("M_PI = %.47Lf \n", piValue);

    double a = M_PI;
    printf("%.7Lf\n", a);

    return 0;
}
