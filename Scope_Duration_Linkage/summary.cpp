//Scope summary
//An identifier's scope determines where it is accessible within the source code;
/*
*Variables with block(local) scope can only be accessed from the point of declaration until the end of the block in which they are declared (including nested blocks)
 This includes:
    -Local Variables
    -Function parameters
    -Program defined type definitions(such as enums and classes) declared inside a block.

*Variables and functions with global scope can be accessed from the point of declaration until the end of the file
 This includes:
    -Global variables
    -Functions
    -program defined type definitions (such as enums and classes) declared inside a namespace or in the global scope
*/


//Duration summary
//A variables duration are the actual rules that determeines when a  variable is created and destroyed.
/*
* Variables with automatic duration are created at the point of definition , and destroyed when the  block they are defined in is exited.
  This includes:
    -Local variables
    -Function parameters

* Variables with static duration are created when the program starts and are destroyed at the end of the program
  This includes:
    -Global Variables
    -Static local variables

* Variables with dynamic duration are created and destroyed by the programmer request.
  This includes:
    =Dynamically allocated variables
*/

//Linkage summary
//An identifiers linkage determines whether a declaration of that same identifier in a different scope refers to the same entity (obect, function, reference, etc) or not.
//Local variables have no linkage. Each declaraion of an identifier with no linkage refers to a unique object or function
/*
*An identifier with no linkage means any other declaration of the same identifier refers to a unique enitiy. 
 Entities whose identifiers have no linkage include:
    -Local variables
    -Program defined type identifiers(such as enums and classes) declared inside a block.

* An identifier with internal linkage means  a declaration of the same identifier within the same tanslation unit refers to the same object or function, 
  Entities whose identifiers have internal linkage include:
    -static global variables(initialized or uninitialized)
    -Static functions
    -Const global variables
    -Unamed namespaces and anything defined in them

* An identifier with external linkage means the declaration of the same identifier within the entire programa refers to the same object or function.
  Entities whose idenitfies have external linkage include:
    =Non-static functions
    -Non-const global variables
    -Extern const global variables
    -Inline const global variables
    -Namespaces
Functions have externa linkage by default
they can be made internal by using the static keyword or definining them inside unnamed namespaces;
*/