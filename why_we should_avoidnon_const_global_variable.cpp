//Many developers  believe non-const global varibles should be avoided completely!
//note non-const global variables
//By far the biggest reason non-const global variables are dangerous is because
// their value can be changed by any function that is called
//consider the following program

#include <iostream>

int g_mode;                 //declare global variable(will be zero initialized by default)


void doSomething()
{
    g_mode = 2;  //set the global variable g_mode variable to 2
}

int main()
{
    g_mode = 1;      //note: this sets the globalvariable g_mode to 1. it does not delare a local g_mode variable

    doSomething();
    //Programmers still expects g_mode to be 1
    //but doSomething()  changed it to 2;

    if (g_mode == 1)
    {
        std::cout << "No threat detected.\n";
        
    }

    else
    {
        std::cout << "Launching nuclear missles...\n";
    }
    //here unless the programmer had explicit knowledge that doSomething() was  going to change the value of g_mode
    //he or she was probably not expecting doSomething to change the value!
    //consequently the rest of main() does not work like the programmer expects and the world is destroyed

    //global variable make  the program's state unpredictable. 
    //Every function call becomes potentially dangerous and the programmer has no easy way of knoweing which ones are dangerous and which aren't
    //Local variables are much safer becalues other function have no effect on them

    return 0;
}

//Global variable make your program less modular and flexible.
//In particular, avoid using global variables for important "decision point" variables(e.g variables you'd use in a conditional statement, like the g_modee example above)
//Your program is less likely o break if  a global variable holding an informatinal value chanes(e.g like the user's name)
//it is more likely to break if you change a global variable that impacts how your program actually funtions


//Best practice: Use local variable instead of global variables whenever possible
//Avoid initializing bject with static duration using other objects with static duration from a different translation unit

/*
Initialization of static variables(which includes global variables) happens as part of program startup, before execution of the main function.
//This proceeds  in two phases
 * C++ Startup Initialization Order Summary:
 * 
 * Phase 1: Static Initialization (Happened first, before runtime)
 * - Constant Initialization: 'constexpr' and literal values evaluated at compile-time.
 * - Zero-Initialization: Uninitialized globals are wiped to zero.
 *   (Ensures safe baseline memory states before any runtime logic executes).
 * 
 * Phase 2: Dynamic Initialization (Happens second, executes runtime logic)
 * - Evaluates non-constexpr expressions (e.g., function calls like init()).
 * - Within a single file: Strictly follows top-to-bottom definition order.
 * - Across multiple files (Translation Units): Order is completely undefined 
 *   (leads to the Static Initialization Order Fiasco).
 * 
 * Best Practice: Avoid initializing a global/static variable using another global/static 
 * variable from a different translation unit, and minimize dynamic global init entirely.
 */

 //Note: static initialization does not strictly follow the order of definition which states that variable are initialized in the order of which they are defined

/*
 If you do find a good use of non-const global variable, a few useful bits of advice will minimize the amount of trouble you can get into.
 This advice si not only for non-const global variables, but can help  with all global variables.
 - prefix all non-namespaced global variables with "g" or "g_" or better yet, put them in a namespace to reduce the chance of naming collisons

 For example, insteed of
#include <iostream>
constexpr double gravity { 9. 8 };  //risk of collission with some other global variable named gravity

int main()
{
    std::cout << gravity << '\n';    //unclear if this is a local or global variable from the names
    return 0;
}

Do this:

#include <iostream>

namespace constants
{
    constexpr double gravity { 9. 8 };
    //will not collide with other global variable named gravity
}

int main()
{
    std::cout << constants::gravity << '\n';
    //clear this is a global variable (since namespaces are global)

    return 0;
}


Second instead of allowing direct access to the global variable, it's better practice to "encapsulate" the variable.
Make sure the variable can only be accessed from within the file it is declared in, e.g by makeing the variables static or const
then provide external global "access functions" to work with the variable.
These functions ensure proper usage is mantained
also if you ever decide to change the underlying implementation(e.g move one database to another), you only have to update the access function instead of every piece of code that uses global variables directly
Example:
*constants.cpp
namespace constants
{
    constexpr double gravity { 9. 8 };//  has internal linkage, is accessible only within this file
}

double gravity()   //has external linkage, can be accessed by other files
{
    //We could add logic here if needed later
    //or change the implementation transparently to the callers
    return constants::gravity;
}
*Main.cpp
#include <iostream>

double getGravity();               //foward declaration

int main()
{
    std::cout << getGravity() << '\n';
    return 0;
}

Third when writing an otherwise an otherwise standalone function that uses the global bariable,
don't use the variable directly in your function body. Pass it in as an argument instead.
That way if your function eve needs to use a different value for some circumstance, you can simply vary the argument this helps mantain modularity
*Example
#include <iostream>
namespace constants
{
    constexpr double gravity { 9.8 }[]
}

//This function can calculate the instant velocity for any graviry value (more useful)
double instantVelocity()
{
    return gravity * time;

}

int main()
{
    std::cout << instantVelocity(5, constants::gravity) << '\n';
    return 0;
}
*/