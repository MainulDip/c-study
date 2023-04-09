#include <stdio.h>
#include <stdlib.h>

// define the structure
struct Car {
    int id;
    char category;
    char brand[50];
};

int main() {
    // initialize structure and assign values one by one.
    struct Car car1;
    car1.id = 1;
    car1.category = 'A';
    strcpy(car1.brand, "BMW"); // use strcpy to assign string

    // copy another structure and change values
    struct Car car2 = car1;
    car2.id = 2;
    strcpy(car2.brand, "TESLA");

    // initialize structure all at once
    struct Car car3 = {3, 'B', "FORD"};

    printf("id = %d, category = %c and brand = %s\n", car1.id, car1.category, car1.brand);
    printf("id = %d, category = %c and brand = %s\n", car2.id, car2.category, car2.brand);
    printf("id = %d, category = %c and brand = %s\n", car3.id, car3.category, car3.brand);
    return 0;
}
