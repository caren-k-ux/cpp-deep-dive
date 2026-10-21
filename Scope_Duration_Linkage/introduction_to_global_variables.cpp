//n the local varables file we covered that local variables are varables defined inside a function body
//local variables have block scope(are only visible within the block they are declared in), and have automatic duration ( they are automatically created at the point of definition and destroyed when the  block is exited) and have no linkaage.

//In C++, variables  can also be declared outside a function.Such variables are called global variables.

//Declaring global variables

#include <iostream>

//Variables declared outsde of a function are called gloabla varables
//By conventon globla variables are declared at the top of the file, below the includes nt the global namespace
int g_x {};    //global   variable g_x

//global variable can be defined inside a user-defined namespace. 
namespace Foo
{
    int g_y{}; //g_y is now inside the foo namespace, but is now a global variable
}

void doSomething()
{
    //global variables can be seen and used everywhere in the file: take note of that

    g_x = 3;
    std::cout << g_x << '\n';
}


int main()
{
    doSomething();
    std::cout << g_x << '\n';

    //global variables can be seen used anywhere in the file
    g_x = 5;
    std::cout << g_x << '\n';

    Foo::g_y = 4;
    std::cout << Foo::g_y << '\n';
    //Although g_y is limited to the scope of the namespace Foo, that name is still globally accessed viaFoo::g_y, and g_y is still a global variable

    return 0;

}
//g_x goes out of scope here

//The scope of  global variables
//Identifiers declared  in the global namespace have global namespace scope (commonly called global scope, and sometimes informally called file scope), which means they are  visble from their point of declaration until the end of  the  file in which they are declared
//Variable declared inside a namespace are also global variables
//Prefer defining global variables inside a namespace rather than in the global namespace.

//Global variables have static duration
//An identifiers duration are the rules that determine the exact time taken from when it instatieted to the point of its destructioon
//Global variables are created when the program starts (before main begins execution) and destroyed when it ends. 
//This is called static duration .
//Variables with static duration are sometimes called static variables
//By conventon developers prefix global variable identifiers with "g" or "g_" to indicate that they are global
/*
    -helps avoid naming collisions with other identifiers in the global namespace obviously
    -helps prevent name/variable shadowing
    -helps indicate that the prefixed variables persist beyond the scope othht he function and thus any changes made on them will also persist

consider using a "g" or "g_" prefix when nameing global variables (especially those defined in the global namespace), to help differenciate them from local variables and function parameters
*/

//Unlike local variables, which ar uninitialied by default, variables with static duration are zero initialized by default

//Non-const global variables can be optionally initialized:
//int g_x;     //no explicit initalizer (zero-initialized by default)
//int g_y {};  //value initialized (resulting in xero initialization)
//int g_z      //list initialized with specifiec value

//As with all constants, constant global variable must be initialized
//const g_x;  //error ; must be initialized
//constexpr int g_w;  //error; must be initialized
//const int g_y { 1 };
// constexpr int g_z { 2 };


//non-constant global variables should generally be avoided altogether
