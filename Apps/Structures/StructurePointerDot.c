// C Program to demonstrate Structure pointer
#include <stdio.h>
#include <string.h>
 struct Student {
    int roll_no;
    char name[30];
    char branch[40];
    int batch;
};
 
int main() { 
    struct Student s1;
    struct Student* ptr = &s1;
 
    s1.roll_no = 27;
    strcpy(s1.name, "Kamlesh Joshi");
    strcpy(s1.branch, "Computer Science And Engineering");
    s1.batch = 2019;
 
    // accessing structure pointer with dot operators
    printf("Roll Number: %d\n", (*ptr).roll_no);
    printf("Name: %s\n", (*ptr).name);
    printf("Branch: %s\n", (*ptr).branch);
    printf("Batch: %d\n", (*ptr).batch);

    printf("Batch: ptr->batch = %d\n", ptr->batch);
    printf("Batch: s1.batch = %d\n", s1.batch);

 
    return 0;
}