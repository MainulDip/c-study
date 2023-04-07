#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // type name[size1][size2]...[sizeN]
    // two dimensional array

    int x[3][4] = {
        {1, 2, 3, 4},  /*  initializers for row 0 */
        {5, 6, 7, 8},  /*  initializers for row 1 */
        {9, 10, 11, 12} /*  initializers for row 2 */
    };

    // The nested braces, which indicate the intended row, are optional. The following initialization is equivalent to the x array
    int y[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    


    printf("x[0] = %d and y[1] = %d\n", x[0], y[0]); // 6422000 and 6421952 | addresses
    printf("x[0][0] = %d and y[1][0] = %d\n\n", x[1][1], y[1][2]); // 6 and 7

    // multidimensional array pointers
    printf("y = %d, *y = %d, **y = %d, y[0] = %d, *y[0] = %d\n", y, *y, **y, y[0], *y[0]);
    printf("**y[0] = %d, *y[0][1] = %d, y[][2] = %d, *y[][2] = %d\n\n", *y[12], y[0][1], y[0][2], y[0][2]);


    // int *zx[3][4] = &x; // not work
    int (*zy)[3][4] = &y;

    return 0;
}
