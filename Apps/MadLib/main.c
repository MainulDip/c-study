#include <stdio.h>
#include <stdlib.h>

int main()
{
    char color[20], pluralNoun[20], celebrityF[20], celebrityL[20];

    printf("Enter a color: ");
    scanf("%s", color);

    printf("Enter a plural Noun: ");
    scanf("%s", pluralNoun);

    printf("Enter a Celebrity name with two words: ");
    scanf("%s", celebrityF);
    scanf("%s", celebrityL);

    printf("Roses are %s\n", color);
    printf("%s are blue\n", pluralNoun);
    printf("I love you %s %s\n", celebrityF, celebrityL);
    return 0;
}
