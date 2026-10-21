#include <iostream>

//void means the function does not return a value to the caller

void printHi () 
{
    std::cout << "Hi!" << '\n';
    //this function does not return a value so  no return statement  is needed
}

int main() {
    printHi();
    //printHi is called; no return value is returned
    return 0;
}





//void return values
//a function that does not return a value is  called a non-value returning function or a void function
//functions are not required to return a value back to the caller
//A return statement should not be put in such a function
//to tell the compiler that  a function does not return  a value, a return type void is used.
// your program  implements undefined behavior if it exhibits any of the following symptoms:
//produces a  value in a function that is declared to return void
// consistently produces the same  incrrect result 