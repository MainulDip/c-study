// A simple program that computes the square root of a number
#include <cmath>
// #include <cstdlib> // TODO 5: Remove this line
#include <iostream>
#include <string>

using namespace std;

// TODO 11: Include TutorialConfig.h

int main(int argc, char* argv[])
{
  if (argc < 2) {
    // TODO 12: Create a print statement using Tutorial_VERSION_MAJOR
    //          and Tutorial_VERSION_MINOR
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  // TODO 4: Replace atof(argv[1]) with std::stod(argv[1])
  const double inputValue = std::stod(argv[1]);
  std::cout << argv[0] << "\n"; // prints the absolute path of this file
   std::cout << argv[1] << "\n"; // prints supplied runtime argument 

  // calculate square root
  const double outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;

// std::cout << "Hello World";

// this will pause the console from going away, 
cin.get();
// it is windows specific, >0 will remove the extra text
// system("pause>0"); 
  return 0;
}

