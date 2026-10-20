//The term static is one of the most confusing in the C++ language, in large terms because it has different meaning in different contexts.
//global variables that have static duration are created when the program starts and destroeyd when the program ends
//The static keyword also gives a global idenitifier internal linkage, which means the idenitifier can only be used in the file  in which it is defined.
//Here we are going to explore the use of the static keyword when applied to local varable

//Static local variable
//remember local variables have automatic duration by default, which means they are created at the point of definition, and destroyed  when the block is exited.
//Using the static keyword on a local variable changes its duration from automatic to static duration,
//This means the variable is now created at  the start of the program, and destroyed at the end of the program(just like a local variable). 
//As a result, the static variable will retain its value even after it goes out of scope
//Example
/*
Automatic duration default
#include <iostream>

void incrementAndPrint()
{{
    int value { 1 };
    ++value;
    std::cout << value << '\n';

}    //value destroyed here

int main()
{
    incrementAndPrint();
    incrementAndPrint();
    incrementAncPrint();
    return 0;
    //program outputs 2 2 2 
    //This is vecause each time incrementAndPring() has finished running, the variable goes out of scope and is consequently destroyed
}
//Now consider a version of this program that uses a static local variable
Static Duration (using static keyword):
#include <iostream>

void incrementAndPrint()
{
    static int s_value { 1 };   //static duration via static keyword. The initializer is only executed once.
    ++s_value;
    
    std::cout << s_value << '\n';
}
//s_value is not destroyed here, but becomes inaccessible because it goes out of scope

int main()
{
    incrementAncPrint();
    incrementAndPrint();
    incrementAndPrint();

    return 0;

    //When s_vlue goes out of scope at the end of the function, it is not destroyed. Each time the function incrementAndPrint(0 is called, the value of s_value remains whatever we left it at previously
    //consequently the program outputs: 2 3 4)

    //static local variables are used when you need a local variable to remember its value accross function calls.

}

//In this program, because s_value has been declared as static =, it is created at the program start.
//static local varibles that are zero initialized or have a constexpr initializer can be iitialized at the program start
static local variables have no initializer or a non=constexpr initializer are reinitialized the first time the variable definition is encountered. The definition is skipped on subsequenf calls, so no further reinitialization happens.
Because they have sttic duration, static local variables that are not explicitly initialized are zero-initalized  by defaulet

*/

//Notice static local variables work similarly to  non-const global variables
//The only difference is the place in which they are accessible (scope )
//static local variables have local scope which means they are only accessible and can only be modified in the function in which they are defined while non-const globals can be accessed and modified from any point
//BEst Practice: Initialize your static locla variables. Static loval variables are only initialuzed the first time the code is executed not on subsequent calls
//use "s_" to prefix static (static duration ) local variables.


//Static local constants
//static local variables can be made const or constexpr. 
//One good use for a const static local variable is when you have a functoon that needs to use a const value, but creating or intializing the object is expensive (e.g. you need to read a value from a database). 
//If you used a normal local variable, th variable would be created and initialized everytime the function is executed
//with a const/constexpr static local variable, you can create and initializ the expensive object once, and then reuse it whenever the function is called.

//..static local variables are best used to avoid expensive local object initialization each time a function is called.
//Do not use static local variables that  alter program flow

//BEST PRACTICE
//Const static local variables are generally okay to us
//Non-const static local variables should generally be avoided. if you do use them, ensure the variable never needs to be reset, and isn' used to alter program flow.