//A compound statement(also called a block, or a block statement) is a group of zero or more statements that is treated by a compiler as if it were a single statement
//Blocks begin with a { symbol and end with a } symbol, with the statements  to be executed in between
//Blocks can be used anywhere a single statement is allowed. No semicolon is required after the closing } of a block, unless the block is used in a context that requires a semicolon (e.g. as the body of a function definition)
#include <iostream>

int add(int x, int y)
{   //start block
    return x + y ;

} //end block; no semicolon

int main()
{ //start block 
    // multiple statements

   
    add(3,4);
    //blocks can be nested inside other blocks
    {   //inner/ nested block
        int x { 5 };  //this is an initialization statement, not a block

        std::cout << "The value of x is: " << x << '\n';
    }     //end inner/ nested block

    //using blocks to execute multiple statement in an if statement
    std::cout << "Enter an integer value: ";

    int value {};      //this is an initialization statement , not a block
    std::cin >> value;

    if (value >= 0)
    {  // start of nested block
        std::cout << value << " is a positive integer(or zero)\n";
        std::cout << "The square of " << value << " is: " << value * value << '\n';
    }   //end of nested block

    else 
    {
        std::cout << value << " is a negative integer\n";
        std::cout << "The absolute value of " << value << " is: " << -value << '\n';
    }

    // It is even possible to put blocks inside of blocks, although this is not a common practice. For example, we could have written the above if statement as follows:
    std::cout << "Enter a floating point value: ";
    double dvalue {};
    std::cin >> dvalue;
    if (dvalue >= 0)
    {   //start of outer block
        std::cout << dvalue << " is a positive floating poing number(or zero)\n";

        bool isInteger { (value % 2 == 0) && (static_cast<int>(dvalue) == dvalue) };
        if (isInteger)
        {   //start of inner block
            std::cout << dvalue << " is an even integer\n";
        }   //end of inner block
        else 
        {
            std::cout << dvalue << " is an odd integer or has decimals\n";
        }
    }
    return 0;
}  //end block; no semicolon



//one of the most common use cases for blocks is in conjunction with if statements
//By default if statements only execute a single stament if the condition evaluates to true.
//we can replace that single statement with a block statements if we want multiple statements to execute if the condition is true

//The nesing level(also called depth)  of a function is the maximum no of nested blocks that can be contained within a function. The C++ standard does not specify a maximum nesting level, but most compilers have a limit of 256 nested blocks
//Keep the nesting level of your functionss to 3 or less. if your function needs more nested blocks consider refactoring your functions.