#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age;
    printf("Enter your age:");
    scanf("%d", &age); // storing the %d user input to the allocated memory of age
    printf("You are %d years old", age);

    double cgpa;
    printf("Enter your cgpa: ");
    scanf("%lf", &cgpa); // %lf for double
    printf("\nYour cgpa is %lf\n", cgpa); // %f will also work

    // it prompt can skipped, as enter behaves like another char, s
    char grade;
    printf("\nand what's the grade : ");
    scanf("%c", &grade);
    printf("So, your grade is : %c", grade);



    return 0;
}
