#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Enter a number : ");
    scanf("%d", &x);

    // if, else if, else
    if(x > 7){
        printf("It's gretter than 7");
    } else if (x < 7) {
        printf("x is smaller than 7");
    } else {
        printf("if nither, x is equal to 7");
    }
    printf("\n\n");

    // switch
    char grade;
    printf("Enter your grade : ");
    scanf(" %c", &grade); // space before the %c is important for scanning

    switch(grade) {
    case 'A':
        printf("A Grade");
        break;
    case 'B':
        printf("B Grade");
        break;
    default :
        printf("Something Else Grade");
        break;
    }
    printf("\n\n");


    return 0;
}
