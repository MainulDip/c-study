#include <stdio.h>
#include <stdlib.h>

int gi[4]; // global - all array elements are initialized to 0

int main()
{
    // iteration over global defined array;
    printf("Global array's initialized elements are : ");
    // global array's initial values are 0, no garbase values are there
    for (int i = 0; i < 4; i++)
    {
        printf("gi[%d] = %d | ", i, gi[i]);
    }
    printf("\nOutof Boundary, gi[-1] = %d and gi[4] = %d", gi[-1], gi[4]);
    printf("\n");

    // iteration over function's local array;
    int fi[4]; // automatic storage - contain junk
    // it can contain whatever random junk was in that chuck of memory before.
    printf("Function's local array's initialized elements are : ");
    for (int i = 0; i < 4; i++)
    {
        printf("fi[%d] = %d | ", i, fi[i]);
    }
    printf("\nOutof Boundary, fi[-1] = %d and fi[4] = %d", fi[-1], fi[4]);
    printf("\n");

    // iteration over fn's local static array;
    int static fis[4]; // static - initialized to 0
    // local static array's values are initialized with 0
    printf("Function's Static array's initialized elements are : ");
    for (int i = 0; i < 4; i++)
    {
        printf("fis[%d] = %d | ", i, fis[i]);
    }
    printf("\nOutof Boundary, fis[-1] = %d and fis[4] = %d", fis[-1], fis[4]);
    printf("\n\n\n");


    // array basics
    int someNumbers[] = {1, 2, 3, 4};
    printf("First Number is %d\n", someNumbers[0]);

    int sn[20]; // as this array is initialized locally, it can contain whatever random junk was in that chuck of memory before
    sn[1] = 12;
    printf("First Element is in sn[0] %d\n", sn[0]);
    printf("First Element is in sn[1] %d\n", sn[1]);
    sn[19] = 34;
    printf("Last Element is in sn %d\n", sn[19]); // 34

    printf("Non Existence Element in sn[20] is %d\n", sn[20]); // 1 or something else as memory junc
    printf("Non Existence Element in sn[21] is %d\n", sn[21]); // 2 or something else as memory junc
    printf("Non Existence Element in sn[-1] is %d\n", sn[-1]); // 2 or something else as memory junc

    sn[22] = 1234;
    printf("Non Existence Element in sn[22] is %d\n", sn[22]); // -2
    printf("But the array size sn[20] = sizeof(sn) / sizeof(sn[0]) = %d\n\n", sizeof(sn) / sizeof(sn[0]));


    /**
    * array length by sizeof(array) / sizeof(array[0])
    */
    int arrSize[4];
    printf("arrSize total byte size is = %d\n", sizeof(arrSize));
    printf("arrSize first/single element's byte size is sizeof(arrSize[0]) = %d and sizeof(*arrSize) = %d\n", sizeof(arrSize[0]), sizeof(*arrSize));
    printf("arrSize total length/elements count is sizeof(arrSize) / sizeof(arrSize[0]) = %d\n\n", sizeof(arrSize) / sizeof(arrSize[0]));

    printf("arraySize first element's address is &arrSize = %d and *(&arrSize) = %d)\n", &arrSize, *(&arrSize));
    printf("*arrSize = %d **arrSize = %d and &*arrSize = %d\n", *arrSize, **&arrSize, &*arrSize);
    arrSize[0] = 7;
    printf("arraySize first element's address after assaignment is &arrSize = %d and **(&arrSize) = %d)\n\n", &arrSize, **(&arrSize));
    printf("*arrSize = %d **arrSize = %d and &*arrSize = %d\n", *arrSize, **&arrSize, &*arrSize);
    printf("arrSize = %d and *arrSize = %d and arrSize[0] = %d\n\n", arrSize, *arrSize, arrSize[0]);

    return 0;
}
