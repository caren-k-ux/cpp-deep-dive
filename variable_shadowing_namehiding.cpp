//when we have variable inside a nested block that has the same name as a variable in the outer block
//The nested variable "hides" the outher variable in areas where they are both in scope 
//This is called name hiding or shadowing
#include <iostream>

int value { 5 };  //global variable 

void name()
{
    std::cout << "global variable value: " << value << '\n'; //value is not shadowed here , so this refers to the global value
}

int main()
{
    //outer block
    int apples { 5 };

    {  //nested block
        //apples refers to outeer block apples here
        std::cout << apples << '\n';    //prints value of outer block apples

        int apples { 0 };   //nested block apples come into scope here
        //define apples in the scope of nested block

        // apples now refer to the nested block apples
        //the outer block apples is temporarily hidden

        apples = 10;  //this assigns  value 10 to the nested block apples not oute block apples
        std::cout << apples << '\n';
        //prints the  value of nested block apples

    } //nested block apples go out of scope and are destroyed here

    std::cout << apples << '\n';   //prints the value of the outer block apples


    //shadowing global variables

    int value { 7 };  //hides the global variable variable as it is in scope here

    ++value;  //increments local value, not global variable

    std::cout << "local variable value: " << value << '\n';
    name();

    //because global variables are part of the global namespace we can use the scope resolution operator with no prefix to tell the compiler we mean the global variable instead of local variable

    --(::value);    //decrements global value, not local value (parenthesis addes for readability)

    std::cout << "global variable value after decrement: " << ::value << '\n';

    return 0;
}  //outer block apples go out of scope here

//Note that if the nested block apples had not been defined, the name apples in the nested block would still refer to the outer block apples, so the assignment value of 10 would  have been applied to the outer block apples
//Shadowing global variables:
//similar to how variables in a nested block can shadow variables in an outer block, 
//local variable  with the same name as a global variable will shadow the gloabal variable wherever the local variable is in scope

//Avoid variable shadowing

//some compilers would issue a warning when a variable is shadowed
//you can avoid shadowing of global variables by using the "g" or "g_" priefix.
//Shadowing can cause silent runtime bugs because the compiler will not emit an error by default 
//you can instruct your compiler (like GCC or Clang ) to warn you when shadowing occurs by 
// g++ -Wshadow main.cpp   *bash

