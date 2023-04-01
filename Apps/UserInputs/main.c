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

    // for this, prompt can be skipped, as enter/return keyboard input behaves like another char
    char grade;
    printf("\nand what's the grade : ");
    scanf("%c", &grade);
    printf("So, your grade is : %c\n", grade);

    char firstName[10];
    printf("\nYour First Name : ");
    scanf("%s", &firstName); // as array by default behaves like a pointer/reference, we can omit the "&"
    printf("So, your first name is : %s", firstName);

    char firstNameMult[30];
    printf("\nYour first name that is double worlds: ");
    fgets(firstNameMult, 29, stdin);
    printf("\nDouble word FirstName: %s", firstNameMult);




    return 0;
}
