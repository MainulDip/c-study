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

// to get real double, at least one of the number needs to be double or float or both. Mismatch will also do
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

// for this, prompt can be skipped, as enter/return keyboard input behaves like another char
char grade;
printf("\nand what's the grade : ");
scanf("%c", &grade);
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


### Return Statement :


### If Statements :


### Building a Better Calculator :


### Switch Statements :


### Structs :


### While Loops :


### Building a Guessing Game :


### For Loops :


### 2D Arrays & Nested Loops :


### Memory Addresses :


### Pointers :


### Dereferencing Pointers :


### Writing Files :


### Reading Files :