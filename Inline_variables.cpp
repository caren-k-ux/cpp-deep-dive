//In some applications, certain symbolic constants may need to be used throughout your code(not just in one location).
//These include physics or mathematical constants that don't cahnge e.g pi or Avagadro's number
//Instead of redifining this constants in every file that needs them(a violation of the "Dont Repeat Yourself" rule), it is better to declare them once in a central locatioon and use them wherever needed
//That way if you ever need to change them, you only need to change them in one place, and those changes can be propagated out
//Global constants as internal variales
/*
 1. Create a header file to hold these constants.
 2. Inside this header file, define a namespace
 3. Add all your constants inside  the namespace make sure they are constexpr
 4. #include the header file wherever you need it
 Example.
 constants.h

 #ifndef CONSTANTS_H
 #define CONSTANTS_H
 
 //define your own namespace holding constants
 namespace constants
 {
    //Global constants have internal linkage by default
    constexpr double pi { 3.14159 };
    constexpr double avagadro { 6.0221413e23 };
    constexpr double myGravity { 9.2 };
    //m/s^2 --gravity is light on this planet

    //other constants
 }
 #endif

 main.cpp

 #include "constants.h"
 #include <iostream>

 int main()
 {
    std::cout << "Enter a radiur: ";
    double radius { };
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
 }

 Because const glo al have internal linkage, each .cpp file gets an independent version of the global variable that the linker cannot see. In most cases, because  these are constexr, the compiler will simply optimize the variables away
 While this is simple and fine for smaller programs, everytime constants.h gets #included into a different cone file, each of these variables is duplicated 20 timts.
 header guards wont stop this from happening, as they only prevent a header file from being included more thant once in single file,  not form being included one time into multiple dfferent code files.
 This introduces two challenges:
 1. Changing a single constant value would require recompiling everyfile tha #includes the constants header, whicah can lead to lengthy rebuilde times for larger prijects.
 3. It the constants are large in size and cannot be optimized away, this can use a lot of memory
 */


 /*
Global constants as external variables
If you’re actively changing values or adding new constants, the internal variable method can lead to long rebuild times, as every file must be recompiled when a header changes.

One way to avoid these problems is by turning these constants into external variables, allowing a single variable (initialized once) to be shared across all files. In this method, we define the constants in a .cpp file (to ensure definitions only exist in one place) and put forward declarations in the header file.

constants.cpp:
#include "constants.h"
namespace constants
{
    // We use extern to ensure these have external linkage
    extern constexpr double pi { 3.14159 };
    extern constexpr double avagadro { 6.0221413e23 };
    extern constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
}

constants.h:
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
    // Since actual variables are inside a namespace, forward declarations must also be inside it.
    // We can't forward declare variables as constexpr, but we can forward declare them as (runtime) const.
    extern const double pi;
    extern const double avagadro;
    extern const double myGravity;
}

#endif

Usage in main.cpp stays identical, but now the symbolic constants get instantiated only once (in constants.cpp) instead of in every code file where constants.h is included.

Key Insight & Downsides:
- For variables to be usable in compile-time contexts (like array sizes), the compiler must see the variable's definition, not just a forward declaration. 
- Because definitions in constants.cpp are not visible when compiling other files, these variables cannot be used in constant expressions outside of constants.cpp.
- Compiler optimization may be reduced because they act more like runtime expressions outside their defining file.

Advantages:
- Works prior to C++17.
- Only one copy of each variable is required.
- Only requires recompilation of constants.cpp if a value changes.

Disadvantages:
- Forward declarations and variable definitions are in separate files and must be kept manually in sync.
- Variables are not usable in constant expressions outside of the file in which they are defined.


Global constants as inline variables (C++17)
In C++17, inline variables were introduced. These are variables that can have more than one definition, as long as all definitions are identical. By making constexpr variables inline, we can define them directly in a header file and #include them into any code file without violating the One Definition Rule (ODR) or duplicating variables.

A reminder: Constexpr functions are implicitly inline, but constexpr variables are not. You must explicitly mark an inline constexpr variable with the `inline` keyword. Inline variables have external linkage by default so the linker can de-duplicate them.

constants.h:
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
    inline constexpr double pi { 3.14159 };
    inline constexpr double avagadro { 6.0221413e23 };
    inline constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
}

#endif

main.cpp:
#include "constants.h"
#include <iostream>

int main()
{
    std::cout << "Enter a radius: ";
    double radius { };
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}

Advantages:
- Can be used in constant expressions in any translation unit that includes them.
- Only one copy of each variable is required.

Disdownsides:
- Only works in C++17 onward.
- Changing anything in the header file still requires recompiling files that include the header.

Best Practice:
If you need global constants and your compiler is C++17 capable, prefer defining inline constexpr global variables in a header file. 
(Note: Use std::string_view for constexpr strings if needed).
*/

