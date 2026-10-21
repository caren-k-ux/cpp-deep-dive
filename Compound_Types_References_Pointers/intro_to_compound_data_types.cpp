#include <iostream>

int main()
{
    int denominator1 {};
    int numerator1 {};

    int numerator2 {};
    int denominator2 {};

    //Used to eat (remove) the sllash between the numeator and denominator
    char ignore {};

    std::cout << "Enter a fraction: ";
    std::cin >> numerator1 >> ignore >> denominator1;

    std::cout << "Enter a fraction: ";
    std::cin >> numerator2 >> ignore >> denominator2;

    std::cout << "The  two fractions multiplied: " << numerator1 * numerator2 << '/' << denominator1 * denominator2 << '\n';
}