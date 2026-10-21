//An identifiers linkage determines whether other declarations of that name refers to the same object or not
//remember local variables have no linkage meaning each declaration of a local variable is unique
//Global variables and function identifiers can have either internal linkage or external linkage 
//I will mostly be talking about internal linkage in this file
//an identifier with internal linkage can be seen and usde within a single translation unit, but  is not accessible from other translation units
//This means that if two source files have identically named identifiers with internal linkage, those identifiers will be treated as independent( and do not violate the ODR rule for dupllicate definitions)
//Identifiers with internal linkage may not be visible to the linker at all. alternatively they may be visible to the linker, but marked for use in a specific translation unit
//it is funny right the compiler sees everything  but the linker and preprocessor are blind to each other
//it is like the compiler is the puppetier while the preprocessor and linker are puppets unware of each other out of topic though
//remembrer a translation unit results when the prepocessor has finished preprocessing a code file
//the translation unit is what is compiled by the compiler
/*
    More about the preprocessor
    when you compile your project, you might expect that the compiler compiles each code file exactly as you have written it
    this is not actually the case
    prior to compilation each .cpp file goes through preprocessing phase.
    In this phase, the preprocessor makes various changes to the text of the code file
    the preprocessor strips out comments, and ensures each code file ends in a  newline
    The most important work of the preprocessor is that  it processes #include directives
    When a preprocessor runs, it scans through the code file from top to bottom looking for preprocessor directives often just called directives(the insturctions that start with a #symbol and ends with a newline not a semicolon)
    when you include a #include file say #include <iostream>, the preprocessor replaces the #include directives with the contents included in the file
    it is like ctrl  + v 
    nevermind I will create a file about preprocessors in the future if I get time
    What is important to note is that each translation unit typically consists of a single .cpp file and all header files it #includes( applied recursively since  header files can include header files) 
    with everything in the #include directives pasted in it  for the compiler to see

*/

//Global variable with internal linkage
//global variable with internal linkage are sometimes called internal variables
//To make a non-const global variable internal, we use the static keyword.

#include <iostream>

static int g_x {};  //non-constant global variables have external linkage by default, but can be given internal linkage via the static keyword

const int g_y  { 1 };  //const global variables have internal linkage by default

constexpr int g_z { 2 };    //constexpr global variables have internal linkage by default

int main()
{
    std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';
    return 0;
}



//you might wonder why const variables have internal linkage by default
// Why const variables have internal linkage by default (C++11 rationale):
// 
// 1. Compile-Time Evaluation:
//    To use a const object in a constant expression, the compiler requires 
//    its full definition (not just a declaration) in the current translation unit.
//
// 2. Header File Propagation & The ODR:
//    If const objects had external linkage by default, defining one in a header 
//    included by multiple source files would trigger One Definition Rule (ODR) violations.
//
// 3. The Solution (Internal Linkage):
//    By making const internal by default, each translation unit gets its own local 
//    definition when #including the header. This satisfies compile-time evaluation 
//    needs without causing duplicate symbol linker errors.
//
// Note: C++17 introduced inline variables, which allow global constants with 
// external linkage to be defined in headers without violating the ODR.

//key note
//Internal linkage = header friendly: making const internal by defalult lets you #include constant 
//definitions accross multiple file without the linker complaining about multiple definition, while ensuring every file can evaluate those constantss at compile time

//FUNCTIONS WITH INTERNAL LINKAGE
//just like global   variables, functions default to external linkage
//we can use the static keyword to give a function internal linkage
//This makes the function accessible ONLY within the translation unit it is defined

[[maybe_unused]] static int add (int x, int y) //Internal linkage
{
    return x + y;
}

//This function is declared as static, and can now onl be used within this file
//Attempts to access it from another file vea a function foward declaration will fail

//Why make functions internal?
//1.Enscapsulation: Hides helper functions so other files cannot call  or misuse them.
//2.Pewvents naming collisions: Allows multiple .cpp files to have helper functions 
// with identical names without causind ODR linker files.

//The one-definition rule and internal linkage
//  note that the one-definition rule(ODR) says that an object or function cannot have more than one definition, either withing a file or program.
//However, internal objects(and functions) that are defined in diff file are 
//considered independen entities(even if their names are identical), so there is no vialation of ODR. Each internal object has only one definition
//In modern C++, using 'static' for internal linkage at namespace scope is considered legacy.
//The preffered modern way to give variables, functions, types and templates internal linkage
//is by placing them in an unnamed namespace

namespace
{
    [[maybe_unused]] int g_internal_variable { 10 }; //internal linkage

    [[maybe_unused]] void doSomethingInternal()  //Internal linkage
    {
        std::cout << "Doing something inside this translation unit only\n";
    }
}

//Everything defined in an unnamed namespacee is treated ad if it has internal linkage.

//BEST PRACTICE
/*  
    Give variables internal linkage when uou have an explicit reason to disallow access from other files.
    Consider giving all identifier you do not want accessible to other file internal linkage 
    (Use an unnamed namespace for this).
*/


// summary 
// - Internal identifiers exist ONLY within their translation unit.
// - Non-const global variables: DEFAULT external -> Make internal via 'static'.
// - Const / Constexpr global variables: DEFAULT internal (no keyword needed).
// - Functions: DEFAULT external -> Make internal via 'static'.
// - Modern C++ Best Practice: Use unnamed namespaces over 'static' for internal definitions.
//  as static only works for variables and functions . Unamed namespacees work for structs, classes, typedefs, and templates too
