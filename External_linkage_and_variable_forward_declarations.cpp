//remember an objects internal linkage limits the use of an identifier to a single file
//-An identifier with external linkage can be seen and used both from the file 
//in which it is defined and from other code files(via a forward declaration).

//Identifiers with external linkage are visible to the linker. This allows the linker to do two things with:
//- connect an identifier used in one translation unit with  the appropriate definition in another translation unit
// -Deduplicate inline idenitifiers so one canonical definition remains
//Remember variables or objectw with internal linkage may not be visible to the linker
//or if visible are ignored by the linker as they maybe contain big tags or are marked as belonging to the single translation unit they belong in I guess

//Functions have external linkage by default
//normally you can use a function defined in another file by forward declaring the function in the current file you are in
//This is because functions have external linkage by default
//forward declaration tell ths compiler about the existence of the function, an the linker connects the function call to the actual function definition.

//Example
#include <iostream>

//a.cpp
[[maybe_unsused]] void sayHi() //this function has external linkage, 
//and can be seen by other files apart from a.cpp
{
    std::cout << "Hi!\n";
}

//main.cpp

void sayHi();  //foward declaration for function sayHi, makes sayHi accessible in file main.cpp

int main()
{
    sayHi(); //call to a function defined in another file, linker will connect this call to the function definintion
}