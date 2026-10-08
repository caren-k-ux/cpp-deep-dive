//naming collisions occur when two or more identical identifiers are introduded into  the same scope, and the compiler cannot determine which identifier to use.
//scope is where your identifiers are visible and can be accessed. simply where they live in your program.
//during naming collisions, the compiler or linker will produce an error as they do not have enough information to determne the right identifier to use. 
//This is where namespaces come in handy
//always define your identifiers in the smallest scope possible. This will help avoid naming collisions and make your code easier to read and maintain.

//Defining your own namespaces
//A namespace is a declarative region that provides a scope to the identifiers inside it. Namespaces are used to organize code into logical groups and to prevent name collisions that can occur especially when your code base includes multiple libraries
//The syntax for definging a namespace is as follows:

/*
namespace NamespaceIdentifier
{
    //content of the namespace
}
*/
//It is recommended to start namespace names with a capital letter e.g Foo
//You can access  the identifiers or  functions defined in a namespace by using the scope resolution operator or by using  statements

//The scope resolution operator(::) can also be used in front of an identntifier without providing a namepspace name e.g. ::doSomething()
//In such a case, the identifier(e.g. doSomething()) is looked for in the global namespace.

#include <iostream>
void print()  //this print()  lives in the global namespace
{
    std::cout << " there\n";
}
namespace Foo
{
    int x { 5 };     // this is a variable defined in the Foo namespace
    void printX()
    {
        std::cout << "The value of x is: " << x << '\n';
    }

    void print()  // this print() lives in the Foo namespace
    {
        std::cout << "Hello\n";
    }

    void printHelloThere()
    {
        print();  //this will call print() in the Foo namespace
        ::print();  //this will call print() in the global namespace    
    }
}

//namespaes can be nested inside other namespaces. For example, we could have defined the Goo namespace inside the Coo namespace as follows
namespace Coo
{
    namespace Goo
    {
        int add(int x, int y)
        {
            return x + y;
        }
        //we would access the add() function in main as follows:
        //Coo::Goo::add(3, 4);
    }
}
// The above nested namespace can also be defined using the following syntax: 

/*
namespace Coo::Goo
{
    int add(int x, int y)
    {
        return x + y;
    }

    //it will be calld in the same way as before: Coo::Goo::add(3, 4);
}

*/

namespace Goo
{
    int x { 10 };
    void printX()
    {
        std::cout << "The value of x is: " << x << '\n';
    }
}


int main()
{
    Foo::printX();     ///accessing printX() via the scope resolution operator (::)
    Goo::printX();   //accessing printX() in namespace Goo via the scope resolution operator (::)

    //Without namespaces, the compiler would not know which printX() function to call, and it would produce an error.
    //The scope resolution operator is good as it allows us to explicitly specify which namespace we want to look in so there is no ambiguity.
    ::print();  //accessing print() in the global namespace via the scope resolution operator
    Foo::printHelloThere();


    
    return 0;

}


//Explanaton for how print with no scope resolution operator is called in printHelloThere():
//An unqualified name is a name that is not prefixedd by a namespace or simply wihtout a scope resolution operator (::)
//When an unqualified name is used inside a namespace, the compiler  resolves it 
//by  using an INSIDE_OUT search order:

//1. Current local scope(e.g. inside the function printHelloThere()): Checks inside the current function or block.
//2. Containing namespace scope(e.g. inside the Foo namespace): Cheks the enclosing namespace 
//3. Outer/Global namespaace scope: Checks the global namespace if the identifier is not found in the current local scope or the containing namespace scope

//Note as soon as a matching declaration is found at any level, the search stops immediately.
//Outer matching names will be hidden (shadowed) by inner matching names. This is called name hiding or shadowing.