#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d", &x);

    // if, else if, else
    if(x > 7){
        printf("It's gretter than 7");
    } else if (x < 7) {
        printf("x is smaller than 7");
    } else {
        printf("if nither, x is equal to 7");
    }
    return 0;
}
