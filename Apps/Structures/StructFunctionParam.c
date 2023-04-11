#include <stdlib.h>
#include <stdio.h>

struct gym
{
    int ids[10];
    char name[20];
};

typedef struct gym Gym;

// prototype, which will change the original variable's value through pointer reference
void passByRef(Gym *g);

// prototype, which will only change the value inside of the function
void passByVal(Gym g);

int main(int argc, char const *argv[])
{
    Gym someGym;
    strcpy(someGym.name, "ElegantGym");
    someGym.ids[0] = 1;

    Gym *someGymPtr = &someGym;
    printf("Gym Name = %s\n", someGym.name);
    printf("Gym Name's pointer = %d\n", someGymPtr->name);

    // call the function to change the original name by reference
    passByRef(someGymPtr);
    printf("Gym Name = %s\n", someGym.name);
    printf("Gym Name's pointer = %d\n\n", someGymPtr->name);

    // call the function to change only function's inner value without affecting the original value
    passByVal(someGym);
    printf("But the Original Gym Name = %s\n", someGym.name);
    printf("And the Original Gym Name's pointer = %d\n", someGymPtr->name);


    // access single character and traverse character's array 
    printf("\n\nGym Name = %c\n\n", (someGym.name)[0]);
    printf("\n\nGym Name = %c\n\n", *(someGym.name));
    printf("\n\nGym Name = %d\n\n", &(someGym.name));

    // printing array length from function without passing the array length as param.
    getArrayLen(someGym);
}


/**
 * which will change the original variable's value through pointer reference
*/
void passByRef(Gym *g) {
    strcpy(g->name, "Changing Name");
    printf("Length of the name = %d\n", sizeof(g->name));
}

/**
 * which will only change the value inside of the function
 * but the actual/out-of-scope value will not change
*/

void passByVal(Gym g) {
    strcpy(g.name, "LocalName");
    printf("Gym name = %s has been changed locally\n", g.name);
}


/**
 * Getting array's length is easily possible using struct
 * No need to pass the array length.
*/
void getArrayLen(Gym g) {
    printf("total count of ids = %d\n", sizeof(g.ids) / sizeof(*(g.ids)));
    // can be written without pointer also
    printf("total count of ids = %d\n", sizeof(g.ids) / sizeof((g.ids)[0]));
}

