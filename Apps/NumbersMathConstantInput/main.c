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
    // printf("M_PI = %Lf \n", piValue);

    double a = M_PI;
    printf("%.20Lf\n", a);

    long long int x=25,y=40000;       //int was overflowing and causing you error
   long double dist;
   dist=sqrt((47-x)*(47-x)+(132000-y)*(132000-y));   //this will safely compute within range and return the desired result
   printf("After distance\n");
   printf(" x= %lld y=%lld dist=%Lf\n",x,y,dist);

    return 0;
}
