### Overview:
It's a personalized repo for the C programming language, which will act like mini guide to jump start and personal references/notes.
### Get Compiler Version :
```c
#ifdef __clang_major__
    printf ("clang detected version %d.%d\n", __clang_major__, __clang_minor__);
#endif

#ifdef __GNUC__
    // note that clang 3.7 declares itself as a gcc 4.2"
    printf ("gcc detected version %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif
``

### Variables :
```c
// type variableName = variableValue
// type variableName[] = variableValue
char characterName[] = "John"; // multiple char characters by []
int characterAge = 37;

// string by %s placeholder and % for escaping %s .
char someCharacters[] = "NameCharacters";
printf("Printing Variable someCharacters as %%s %s ", someCharacters);
// Output: Printing Variable someCharacters as %s NameCharacters

// %d for digit/int
int characterAge = 37;
printf("\nNow printing digit by %%d and the characterAge = %d\n", characterAge);
// output: Now printing digit by %d and the characterAge = 37

```


### Data Types :
```c
// int for integer or full number
int age = 77;

// double and float for decimals
double cost = 77.00;
float pi = 3.1416;

// double vs float : float can hold up to 7 decimal digits accurately while double can hold up to 15

// char for single character, also with single quote
char letter = 'G';

// string
char string[] = "String Uses double quote and is immutable";
```


### Printf :
```c
// %f for float placeholder
printf("String by %s, Digit by %d and float by %.2f", "SomeString", 1234, 77.77);
// %c for single character, %s (string), %d (int), %f and %lf (float/double)

double cost = 77.77;
printf("\nPrinting double by %%f as cost = %f", cost); // 77.770000
printf("\nPrinting double by %%.2f as cost = %.2f", cost); // 77.77
printf("\nPrinting double by %%.6g as cost = %.6g", cost); // 77.77

// %g will take a number that could be represented as %f (a simple float or double) or %e (scientific notation) and return it as the shorter of the two.

// for float, we need to specify how many decimal digit we want by %.2f (%.nf), otherwise it will print 7 decimal point
```


### Working With Numbers :
```c
// if neither of the number involved in division, it will return integer with double conversion. 
double someAverage = 7 / 6;
printf("Printing division %f\n", someAverage); // 1.000000

// to get real double, at least one of the number needs to be a double or float or both. Mismatch will also do
someAverage = (double) 7 / (float) 6;
printf("Printing division %f\n", someAverage); // 1.166667

long double piValue = 22.00 / 7.00;
// MinGW uses the Microsoft runtime, and there is said to be some problem, it doesn't support long double but implements it as double, hence using __mingw_printf.
__mingw_printf("M_PI = %.47Lf \n", piValue);


// ceil() function rounds a number upwards to its nearest integer
printf("ceil %f\n", ceil(1.4)); // 2.000000
// floor() method rounds a number downwards to its nearest integer
printf("floor %f", floor(1.4)); // 1.000000
```


### Comments :
// and /* */

### Constants:
```c
// constants are immutable (variables are mutable)
const int SOME_NUM = 7;

// also there are some constant on the fly
// here the text "hello" and the placeholder value "123" are constant
printf("hello %f", 1234);
```

### Getting User Input:
For basic, scanf and fgets can be used for collecting user inputs
```c
int age;
printf("Enter your age:");
scanf("%d", &age); // storing the %d user input to the allocated memory of age
printf("You are %d years old", age);

double cgpa;
printf("Enter your cgpa: ");
scanf("%lf", &cgpa); // %lf for double
printf("\nYour cgpa is %lf\n", cgpa); // %f will also work

// while scanning character, space before the %c is important
char grade;
printf("\nand what's the grade : ");
scanf(" %c", &grade);
printf("So, your grade is : %c\n", grade);

char firstName[10];
printf("\nYour First Name : ");
scanf("%s", &firstName); // as array by default behaves like a pointer/reference, we can omit the "&"
printf("So, your first name is : %s", firstName);

char firstNameMult[30];
printf("\nYour first name that is double worlds: ");
fgets(firstNameMult, 29, stdin);
printf("\nDouble word FirstName: %s", firstNameMult);
```

### Arrays :
```c
int someNumbers[] = {1, 2, 3, 4};
printf("First Number is %d\n", someNumbers[0]);

int sN[20];
sn[0] = 12;
printf("First Element is %d\n", sn[0]);
sn[19] = 34;
printf("Last Element is %d\n", sn[19]); // 34

printf("Non Existence Element is %d\n", sn[20]); // -2

sn[21] = 1234;
printf("Non Existence Element is %d\n", sn[21]); // -2
```

### Functions :
```c
// if the function's return type is anything other than void, put signature (prototyping) before the main function
double cube(double num);

int main()
{
    sayHi("World");

    printf("cube(7) = %f\n", cube(7.0));
    return 0;
}

// for void return type, header is not required
void sayHi (char name[]) {
    printf("Hello %s!\n", name);
}

double cube(double num) {
    double result = num * num * num;
    return result;
}
```

### Array as Function Parameter:
Passing arrays in C is the same as passing by pointer/address. Where the function gets the first element's address of the array, no other information like array length is supplied.

So we have to either pass the length on the array as in another parameter, or wrap it in a struct and pass the struct as parameter.

```c
#include <stdio.h>
float calculateSum(float num[], int length);

int main() {
  float result, num[] = {23.4, 55, 22.6, 3, 40.5, 18};
  int numLength = sizeof(num) / sizeof(*num) // or sizeof(num[0])

  // num array is passed to calculateSum()
  result = calculateSum(num, numLength); 
  printf("Result = %.2f", result);
  return 0;
}

float calculateSum(float num[], int length) {
  float sum = 0.0;

  for (int i = 0; i < length; ++i) {
    sum += num[i];
  }

  return sum;
}
```

### Multidimensional array and pointer:
```c
int x[3][4] = {
    {0, 1, 2, 3},  /*  initializers for row 0 */
    {4, 5, 6, 7},  /*  initializers for row 1 */
    {8, 9, 10, 11} /*  initializers for row 2 */
};

// The nested braces, which indicate the intended row, are optional. The following initialization is equivalent to the x array
int y[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};


printf("x[0] = %d and y[1] = %d\n", x[0], y[0]); // 6422000 and 6421952 | addresses
printf("x[0][0] = %d and y[1][0] = %d\n", x[1][2], y[1][3]); // 6 and 7
```

### Multidimensional array as function parameter:
```c
#include <stdio.h>
void displayNumbers(int num[2][2]);

int main() {
  int num[2][2];
  printf("Enter 4 numbers:\n");
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%d", &num[i][j]);
    }
  }

  // pass multi-dimensional array to a function
  displayNumbers(num);

  return 0;
}

void displayNumbers(int num[2][2]) {
  printf("Displaying:\n");
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      printf("%d\n", num[i][j]);
    }
  }
}
```
### Function Parameter as Pointer and Address:
* Passing Address
```c
#include <stdio.h>
void swap(int *n1, int *n2);

int main()
{
    int num1 = 5, num2 = 10;

    // address of num1 and num2 is passed
    swap( &num1, &num2);

    printf("num1 = %d\n", num1);
    printf("num2 = %d", num2);
    return 0;
}

void swap(int* n1, int* n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
```

* Passing Pointer
```c
#include <stdio.h>

void addOne(int* ptr) {
  (*ptr)++; // adding 1 to *ptr
}

int main()
{
  int* p, i = 10;
  p = &i;
  addOne(p);

  printf("%d", *p); // 11
  return 0;
}
```
### Multidimensional array as function parameter:

https://stackoverflow.com/questions/2828648/how-to-pass-a-multidimensional-array-to-a-function-in-c-and-c

### Function's varag arguments and default parameter's values:

### Return Statement :


### If Statements :
```c
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
```
### Switch Statements :
```c
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
```


### Structs | Structures :
Structures/Structs are a way to group several related variables into one place. Each variable in the structure is known as a member of the structure. A structure can contain many different data types (int, float, char, etc.) in one place.

```c
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
```

### Structure Inheritance Hack || Structure/s in Structure:
```c
typedef struct 
{
    int id;
    char brand[30];
    char engineType[30];
} Car;

typedef struct 
{
    Car car;
    int engineWattage;
} ElectricCar;

typedef struct 
{
    Car car;
    int engineCC;
} GasolineCar;

ElectricCar electricCar  = { 1, "TESLA", "Electric", 7000};
GasolineCar gasCar = {2, "BMW", "Gas", 2000};

printf("id = %d\n", electricCar.car.id);
printf("id = %d, brand = %s, Engine Type = %s, EngineCC = %d\n", gasCar.car.id, gasCar.car.brand, gasCar.car.engineType, gasCar.engineCC);
```

### Structure Pointer:
```c
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

    printf("Batch: ptr->batch = %d\n", ptr->batch); // arrow operator
    printf("Batch: s1.batch = %d\n", s1.batch); // direct from structure

 
    return 0;
}
```

### Structure as Function Params:
```c
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
```

### Template:


### While Loops :


### Building a Guessing Game :


### For Loops :


### 2D Arrays & Nested Loops :


### Memory Addresses :


### Pointers :

### Pointer Arithmetic:

https://www.geeksforgeeks.org/multidimensional-pointer-arithmetic-in-cc/

### Pointers with array:
https://www.geeksforgeeks.org/pointer-array-array-pointer/?ref=rp

### double pointers:
https://www.geeksforgeeks.org/c-pointer-to-pointer-double-pointer/?ref=rp

### Multidimensional array to pointer:

https://stackoverflow.com/questions/1584100/converting-multidimensional-arrays-to-pointers-in-c


### Dereferencing Pointers :


### Writing Files :


### Reading Files :


### Recursion: 
Recursion is the technique of making a function call itself.
```c
#include <stdio.h>

int sum(int k);

int main() {
  int result = sum(10);
  printf("%d", result); // result, 55
  return 0;
}

int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } else {
    return 0;
  }
}
```

### Macros:
```c
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int main() {
    int a[17];
    size_t n = NELEMS(a);
    return 0;
}
```