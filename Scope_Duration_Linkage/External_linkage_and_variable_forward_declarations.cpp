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

int g_x { 3 };   //non const globals are external by default (no need to use extern)

extern const int g_y { 3 };    // const globals can be defined as extern making them exterm

extern constexpr int g_z { 3 };    //constexpr globals can be difined as extern, makeing them external (but this is useless)

//a.cpp
[[maybe_unsused]] void sayHi() //this function has external linkage, 
//and can be seen by other files apart from a.cpp
{
    std::cout << "Hi!\n";
}

//main.cpp

[[maybe_unsed]]void sayHi();  //foward declaration for function sayHi, makes sayHi accessible in file main.cpp

int main()
{
    sayHi(); //call to a function defined in another file, linker will connect this call to the function definintion
    return 0;

    //in a multifile setup the above program prints Hi!
}



//Global variables with external linkage can sometimes be called external variables
//Tomake a glo al variable external and thus accessible by other files, we can use the extern keyword to do so:
//Non const global variables are external by default and do not need the extern keyword
//To actually use an external global bariable that has been defined in another file, you must place a forward declaration in files wishing to use the variable
//For variables forward declaron is also done via the extern keyword( wiht no initialization value).

/*
//main.cpp

#include <iostream>
extern int g_x;                  //this extern is a forward declaration of a variable named g_x defined somewhre else
extern const int g_y;            //this exern is a forward declaraion of a const variable named g_y  that is defined somewhere else

int main()
{
    std::cout << g_x << ' ' << g_y << '\n';   //print 2 3
    return 0;
}

//here is the definition of those variables
//a.cpp

//global variables definition

int g_x { 2 };                        // non-const globals have external linkage by default

extern const int g_y { 3 };            //this extern gives g_y external linkage


Note that the extern keyword has different meanings in different contexts. In some contexts
extern means "give this variable external linkage". In other context extern means
"this is a forward declaration for an external variable that is defined somewhere else"
*/

//If you want to define an uniitialized non-const global baraibale, do not use the extern keyword, otherwise C++ will think you are trying o make a foward declaration to the variable


/*
    Although constexpr variables can be given external linkage via the extern keyword, the cannot be forward declared as constexpr.
    This is vecause the compiler needs to know the value of the constexpr variable(at compile time)).
    If that value is defined in some other file, the compiler has no visibility on what value wa defined in thatothe file
    However, you can forward declare a constexpr variable as const, whic ht compiler will treat as a runtimie const. this is not particularly useful
*/

//function foward declarations do not need the extern keyword.However, variables foward declaratin need  the extern keyword
// to help differenctite  uniniialized variable definitions from variable forward declarations, othewise they look similar

//Avoid using extern on a non-const global bariable with an initializer
//Only use extern for global variable forward declarations or const global bariable definitions
//Do not use extern gor non-const global variable definitions ( they are implicity extern)


// EXTERN KEYWORD QUICK REFERENCE SUMMARY
// 1. Definition vs. Forward Declaration:
//    - int g_a;             -> Uninitialized DEFINITION (default external, initialized to 0)
//    - int g_a { 5 };       -> Initialized DEFINITION (default external)
//    - extern const int g_b { 5 }; -> Initialized DEFINITION (forces const to external linkage)
//    - extern int g_a;      -> FORWARD DECLARATION (no storage allocated, defined elsewhere)
//    - extern const int g_b;-> FORWARD DECLARATION for external const variable
//
// 2. Best practice:
//    - Do NOT use 'extern' when defining non-const global variables (they are already external).
//    - DO use 'extern' when defining global const variables you want to share across files.
//    - DO use 'extern' when forward declaring variables defined in another translation unit.