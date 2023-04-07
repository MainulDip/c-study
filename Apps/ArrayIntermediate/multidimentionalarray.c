#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // type name[size1][size2]...[sizeN]
    // two dimensional array

    int x[3][4] = {
        {0, 1, 2, 3},  /*  initializers for row 0 */
        {4, 5, 6, 7},  /*  initializers for row 1 */
        {8, 9, 10, 11} /*  initializers for row 2 */
    };

    // The nested braces, which indicate the intended row, are optional. The following initialization is equivalent to the x array
    int y[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};


    printf("x[0] = %d and y[1] = %d\n", x[0], y[0]); // 6422000 and 6421952 | addresses
    printf("x[0][0] = %d and y[1][0] = %d\n", x[1][2], y[1][3]); // 6 and 7

    return 0;
}
