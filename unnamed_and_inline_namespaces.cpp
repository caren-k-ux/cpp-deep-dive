//C++ supports two variants of namespaces that are worth at least knowing about
//Unamed (anonymous) namespaces
//An unamed namespace (also called anonymous namespace) is a namespace that is defined without an name
//Example:

#include <iostream>

namespace //unnamed namespace
{
    void doSomething() //can only be accessed in this file
    {
        std::cout << "v1\n";
    }
}

int main()
{
    doSomething();   //we can call doSomething() without a namespace prefix

    return 0;
}

//All content declared in an unnamed namespace is treated as if it is part of the parent namespace.
//even though the function doSomething() is definced in the unamed namespace, the function is accessible from the global namespace which is why we call do something from main() without any qualifiers
//This might make unnamed namespaces seems useless
//But the other effect of unnamed namespace are treated as if they have internal linkage, which means that the content of an unnamed namespace cannot be seen outside of the file in which the unnamed namespace is defined.
//For functions, this is effectively the same as defining all funcions in the unnamed namespace as static functions
//This program is identical to the one above

/*
#include <iostream>

static void doSomething()  //can  only be accessed in this file
{
    std::cout << "v1\n";
}

int main()
{
    doSomething();  //we can call doSomething() without a namespace prefic
    return 0;
}

Unnamed namespaces should generally not be used in heder files

Prefer unnamed namespaces when  you have content you want to keep local to a translation  unit
Avoid namespaces in header files
*/

///INLINE NAMESPACES
//members defined inside an inline namespace are automatically reated as if they belong to the parent namespace(enclosing namespace)
//Allows direct access without using the nested namespace qualifier (e.g calling Parent::func directly relsolves to Parent::InlineChild:func())
//An inline namespace is typically used for version content.
//much like an unnamed namespace, anything declared inside an inline namespace is considered part of the parent namespace .However, unlike unamed namespaces, inline namepaces do not affect linkage
//It is used to mantain backward compatability while shipping major updates
//Allows library authors to set a "default " version that updates automatically for users without breaking legacy code that explicitly targets older versions.

namespace MyLibrary
{
    //current default version
    inline namespace v2
    {
        void processData()
        {
            //Updated, optimized algorithm
        }
    }

    //Legacy veersion
    namespace v1 
    {
        void processData()
        {
            //Old algorithm
        }
    }
}

[[maybe_unused]]int main()
{
    // 1.Defaults to v2 automatically because v2 is inline:
    MyLibrary::processData();

    //1.Explicitly targets v1 if needed:
    MyLibrary::v1::processData();
    return 0;

}