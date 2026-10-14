//consider the case where you need to write some code to perform some discrete task, like reading input from the user
//while implementing this code you essentially have 2 options 
//1. write the code as part of an existing function say main (called writing code "in-place" or "inline")
//2. Create a new function (and possibly sub-funcions) to handle the task
//putting code in a new function provides many potential benefits as small functions are easer to read and understand, reuse and to update as code needs to be modified in one place
//but is also has cons, their is a certain amount of perfomance overhead that occurs everytime you use a new functon
//All the extra woork that must happen to facilitate, and/or cleanup after some task in this case making a function call) is called overhead.
//For large functions and/or perform complex tasks, the overhead of the function call is typically insignificant compared tot the time the function takes t run
//for small functions the overhead costs can be larger thant the time needed to actually excute the functions code

//Inline Expansion
// Inline expansion is a process where a function call is replaced by the actual code from the called function's definition 
//The C++ compiler uses inline exansion to avoid  the overhead cost we discussed above
#include <iostream>

int min(int x, int y)
{
    return (x < y)?x : y;
}

int main()
{
    std::cout << min(5, 6) << '\n';
    std::cout << min( 3, 2) << '\n';
    //In inline expansion the compiler expands the min() calls above and the resulting code will look like this
    std::cout << ((5 < 6)? 5 : 6) << '\n';
    std::cout << ((3 < 2)? 3 : 6) << '\n';

    //Notice min() has been replaced with the actual function code in min()
    //This allows ud to  avoid the overhead of those calls, while preserving the results of the code
    return 0;
}

//THE PERFORMANCE OF INLINE CODE
/*
-Beyond removing the cost of functioncall, inline expansion can also allow the compiler to optimize the resulting code more efficiently
for example, because the expression((5 < 6) ? 5: 6) is a constant expression the compiler can further optimize the code to std::cout << 5 << '\n'
-Inline expansions can result in performance improvements, reductions or no change to performance at all,
 depending on the relative cost of a functin call, the sie of the function, and what other optimization can be performed
-Inline expandion is best suited to simple, short functions (e.g no more than a few statements) 
*/

//Moderen optimizing compilers make the decison about when functions should be expanded inline 
//so you do not need to explicity tell the compiler to make the function inline
//The most common kind of function that can't be expanded inline is a function  whose definition is in another translation unit
//This is because the compiler is actually blind to other translation units (file) as C++ compiles .cpp files independently and does not see other files
//since the compiler cannot see the definition for such a function, it does not know what to replace the function call with
//as we will see later each inline function must be defined fully in each file to be used

//Historically compilers did not have the capability to determine wether inline expansion would be beneficial, or were not very good at it
//C++ provided the inline keyword to be used as a hint, note a "hint" to thell the compiler that a function would "probably" benefit from being expanded inline
//A function declared using the inline keyword  is called an inline function
//Example

[[maybe_unused]] inline int min(int x, int y) 
{
    return ( x < y ) ? x : y;
}

//However in modern C++ the inline keyword is no longer used to request that a function be expanded inline
//This is because
/*
- It is a form of premature optimizaton, and misuse could actually harm performance
- It is just a hint to help the compiler determine where to perform inline expansio
  The compiler is free to ignore the request, and it may very well do so and the compiler is also free to perform inline expansions for functions that do not use the inline keyword
  out of topic initially I thought the compiler like was the master of everything but as it turns out it is just as blind as the preprocessor and linker maybe less blind leaves us with the question who is the master puppetteer
- The inline keyword is defined at the wrong level of granurality; we use it on a function definition but it is actually determined per function call 
The best practice is to not used the inline keyword to request for inline expansion for your functions.
Modern compilers are good at this and will implicitly do this for us and they are definitely better than humans.
*/

//MORDERNLY, THE INLINE KEYWORD
//Remember that you should not implement functions (with external linkage) in header files, because this would result in a violation of the ODR rule when those headers are included in multiple .cpp files.
//In modern cpp, the term inline evolved to mean "multiple definitions are allowed". 
//thus an inline function is one that is allowed to be defined in multiple transalatin units(without the one-definition rule).
//Inline functions have two primaru requirements:
//- The compiler needs to be able to see the full definition of an inline function in each translation unit where the function is used(a forward declaratin will not suffice on its own)
//  only one such definition can occur per translation unit or it will result in an error
// The definition can occur after the point of useif a forward declaration is also provided.
//  however the compiler will likely not ve able to perform inline expansion until it has seen the definition (any uses between the declaration and definition will  probalby ot be candidates for inline expansion)
// Every definition for an inline function (with external linkage, which functions have by default) must be identical, otherwise undefined behaviour will result


/*
  Inline functions are typically defined in header files, where they can be #included into the top of any code file that
needs to see the full definition of the identifier. This ensures that all inline definitions for an identifier are identical.


*/

///INLINE VARIABLES
// Inline variables are variables that are allowed to be defined in multiple files.
//They work similarly to inline funtions, an have the same requirements