//local variables are variables that are declared inside a function including function parameters.
//Again, an identifiers scope determines where an identifier can be accessed or used within its source code
//when an identifier can be acessed we say it is "in scope" and when an identifier cannot be accessed we say it is "out of scope"

//scope  is a compile time property  and trying to access an identifier outside its scope will result in a compile time error.

//Local variables have block scope, meaning they are only acessible from their point of definition to the end of the block they are defined in.
//All variable names must be unique within their scope otherwise the compiler will produce an error due to naming collisions.
//Example:
/*
void myFunction( int x)
{
    int x{ 5 };      //error as x is already defined as a parameter  and is in the sames scope as the x variable inside the function
}
*/

//Local variables duration
//A variable's storage duration(or just dureation) determine the rules that govern when and how a variable will be created or destroyed.
//A variables duration determines its lifetime; the time taken from when the variable is instatieted to the point it is destroyed
//Local variables have automatic storage duration, meaning they are automatically created at their point of definition and destroyed at the end of the block the are defined in.

//Local variables  have no linkage
//An identifiers linkage  determines wheter a declaration  of that same identifier  in a different scope  refers to the same object or function
//Local variables have nolinkage meaning each declaration fo an identifer refers to a unique object or function.
/*
NOTE: 
Scope and linkage may seem similar. However scope determines where a declaraion of a single identifier can be seen and used in code.
Linkage determines whether multiple declarations of the same identifier refer to the same object or not
*/

#include <iostream>

int max(int x, int y)  // x and y are local variable to max() and enter scope here
{
    int maxValue { (x > y) ? x : y};       //maxValue enters scope here

    return maxValue;  //maxValue is still in scope here
}//  x, y, maxValue go out of scope here at the end of max()

//variables in the same block are destroyed in the REVERSE order of their creation(Last-In, First Out/ LIFO on the stack)
//maxValue is destroyed first then y then x last


int main()
{
    int x { 7 };   //x enters scope here and is accessible from this point to the end of  main()
    double d { 3.14 };  //d enters scope here and is acessible from this point...


    //Local variables can be defined inside nested blocks.
    {// nested blocks
        int y { 7 };  //y enters scope and is created here

    }           //y goes out of scope and is destroyed here

    //y cannot ve used here becaues i s out of scope  in this block


    return 0;  //x and d are still in scope here
}      //x and d go out of scope here at the end of main()



//Again variables should be defined in the  most limited scope
//example

/*
#include <iostream>

int main()
{
    //do nnot define y here
    {
        //y is only used inside this block so we define it here
        int y { 5 };

        std::cout << y << '\n';
    }

    //otherwise y could still be used here where it is not needed
    return 0;
}

also if a variable is needed in the outer block it needs to be declared in the outer block
*/