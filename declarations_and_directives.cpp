//You have probably come accross "using namespace std" 
//If you see this, run. Your textbook or tutorial is probably out of date
//If you are using the standard library a lot, typing std:: before everything you use from th standard library
//can became repetitive, and in some cases, can make your code harder to read
//C++ provides some solutions to both of these problems, in the form of using statements
//But first let us define two terms
//Qualified and Unqualified names

// A qualified name is a name that includes an associated scope
// Most often, names are qualified with a namespace using the scope resolution operator(::) e.g std::cout  //cout is qualified by namespace std
//::foo   foo is  qualified by the global namespace


//An unqualifed name is a name that does not include a scoping qualifier. For example cout an x re unqualified names, as they do not include an associated scoope


//Using declarations
//One way to reduce the repititon of typing std:: over and over is to utilize  a using-declaration statement.
// A using declaration allows us to use an unqualified name with no scope as an alias for a qualified names

#include <iostream>

int main()
{
    using std::cout ;   //this using declaration tells the compiler that cout should resolve to std::cout 
    cout << "Hello world!\n";

    return 0;
}// the using declaration expires at the end of the scope



//Using directives
//Another way to simplify things is to use a using-directive. 
//A using directive allows all identifiers in a given namespace to be referenced without qualification from ths cope of th using-directive
/*
#include <iostream>
int main()
{
    using namespace std;      //all names from the std namespace now accessible without qualification
    cout << "Hello world!\n" ;
    return 0;
}   //the using-directive ends at the end of the current scope

The using-directive using namespace std; tells the compiler that all of the names in the std namespace should be accessible without qualification in the current scope(in this case function main())

//Problems with using-directives (a.k.a why you should avoid "using namespace std")
  In modern C++, using directives generally offer little benefint(saving some typing) compared to the risk this is due to 2 factors
  1/ allow unqualified access to all the name of the namespace (potentially including lots of names you'll never use).
  2/  Using-directives do not prefor names from the namespace identified by uding=directive over othe names

The end result is that the possibility for naming collisions to occur increases significantly (especially if you import the std namespace)
*/


//The scope of using-statements
//if a using declaration or using directive is used within a block, the names are applicable just to that block (it follows normal block scoping rules).
//This is good as it reduces chances of naming collisions to occur to just within that block.
//If a using-declaration or using-directive is used in a namespace(including the global namespace) the names are applicable to the entir rest of the file( they have file scope)

//Do not use using statement in header files, or before an #include directive
//A good rule of thumb is tha using statements should not be plced anywhere ehery they might have an impct on code in a different file
//Nor should they be place anywihere ehere another file's code might be able to impacth them

//Cancelling or replacing a using-statement
// Once a using-statement has been declared, theres no way to cancel or replace it with a different using statement within the scope it was declared 
//The best way you can do is to intentionally limit the scope of the using statement from the outset using the block scoping rules

[[maybe_unused]] int main()
{
    {
        using namespace Foo;
        // calls to Foo:: stuff here

    }//Using namespace Foo expires here

    {
        using namespace Goo;
        std::cout << name() << '\n';
        //calls to Goo::stuffhere

    } //using namespace Goo expires here

    return  0;
}

//All this headache can be avoided by using the scope resolution operator (::) tbh

//BEST PRACTICE
//Prefer explicit namespace qualifiers over using statements
//Avoid using directives altogether(except using namespace std::literals to access the s and sv literal suffixes)
//Using-declarations are okay in .cp files, after the #include directives.
//Do no use using statements in header files (especially in the global namespace of header files  WELL I TRIED)