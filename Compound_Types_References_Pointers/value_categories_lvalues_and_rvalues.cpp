//An expression is a combination of literals, variables, operators, and function calls that can be executed to produce a singular value
#include <iostream>

int return5()
{
    return 5;

}


int main()
{
    std::cout << 2 + 3 << '\n'; // the expression 2 + 3 produces the value 5

    //expressions with side effects that outlive an expression
    int x { 5 };
    ++x;                         // This expression statement has the side effect of incrementing x

    std::cout << x << '\n';

    //Properties of an expression
    // all expressions in C++ have properties: a type and a value category 
    //The type of an expressioon s equivalent to the type of the value, object, or function that results from the evaluated expression. For example
    auto v1 {12 / 4 };              //int / int  => int
    auto v2 {12.0 / 4 };            // double / int  => double

    //The compiler can use the type of an expression to determine whether an expression is valid in a given context
    //The compiler always determines the type of an expression at compile time(so it can run type deduction and checing). The value of the expression however may be determined at either compile time(if the expression is constexpr) or runtime(if the expression is not constexpr).
    //The value category of an expression
    int y {};

    x = 5;                      //valid: we can assign 5 to x
    // 5 = x;                      //error cannot assign value of x to the literal value
    //The value category of an expression resolves whether an expression resolves to a value, a function or an obkect of some kind
    //An lvalue(pronounced "ell-value", short for "left value" or locator value, ans sometimes written as "l-value") is an expression that evaluates to an identifiable objet or functon (or bit-field).
    //lvalues evaluate to an identifiable object : can be modifiable or non-modifiable(const/ constexpr)
    //rvalues evaluate to a value -right value

    int f { 5 };          // 5 is an rvalue expresson
    const double d {1.2 };  // 1.2 is an rvalue expression

    int g { f };  // x is a modfiable lvalue expresson
    const double e { d }; //d is a non modifiable lvalue expression

    int z { return5() };    // return5 is an rvalue expression(since the result is returned by value)

    int w { f + 1 };   // f+ 1 is an rvalue expression
    int q {static_cast<int>(d) };   //the result of static castng d to an nt s an rvalue expression

    return 0;
}


