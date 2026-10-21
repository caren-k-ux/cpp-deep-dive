#include <iostream>


// x and y created and initialized
int add(int x, int y)   //function parameters x and y are local variablesz
{
    int z{x + y}; //z is a local variable
    // z is created and initialzed here

    return z;
}

int main() 
{
    std::cout << "Enter an Integer: ";
    int x{0};
    std::cin >> x;

    std::cout << "Enter another Integer: ";
    int y{0};
    std::cin >> y;

    int sum{ add(x, y)};

    std::cout << "The sum is: " << sum << '\n';
    return 0;
 
}


// What is a Temporary object?
// It is an unnamed, disposable bariable that the compiler secretely creates in memory to temporarily hold a value fr a split secnd

//Local variables 
//variables defined inside the body of a functin are called local variabldes
//Function parameters are also generally considered to be local variable
//local variable lifetime 
//function parameteers are created and intialized when the function is entered,
//and variables within the function body are created and initialized at the point of definition