//Software testing(also called software validation) is the process of determining whether or not the software actually works as expected.
//Before we talk about some practical ways to test your code, let's talk about why testing you program comprehensively is difficult
//consider a simple program

#include <iostream>

void compare(int x, int y)
{
    if ( x > y )
        std::cout << x << " is greater than " << y << '\n'; //case 1

    else if ( x < y)
        std::cout <<  x << " is less than " << y << '\n';  //case 2
    
    else
        std::cout << x << " is equal to " << y << '\n';  //case 3
    
}

int main()
{
    std::cout << "Enter a number: ";
    int x { };
    std::cin >> x;
    
    std::cout << "Enter another number: ";

    int y {};
    std::cin >> y;

    compare(x, y);
    return 0;
}

//Assuming a 4 byte integer, explicitly testing this program with every possible combination of inputs would require that you run the program 18 quintillion time. Clearly not a feasible task!
//This may seem backwards because considering a signed integer  4 bytes = 32 bits which equal 2 ^ 31 -1  and probably -(2 ^ 31) which is roughly 4.29 possible values
//But they are 2 integer values x and y and to test all possible combination of pairs you must multiply them together 
//Total combinations = 2^32 x 2^ 32 = 2^ 64  which = 18.4 quintillion values

//Your intuition should be telling you that you don't really need to run this program 18 quintillion times to ensure it works.
//You only need to run this program avout three times (once to exercise each of the three cases in the function compare()) to have a high degree of confidnce it works as desired.

//There  are several other ways of testing your code
//Test your program in small spaces
//You are  much better of writing small functions (or classes), and then compiling and testing them immediately
//If yor make a mistake, you'll know it has to be the small amount of code that you changed since the last time you compiled or tested.
//That means fewer places to look, and far less time spaent debbugging
//Testing your a small part of your code in isolation to ensure that "unit" of code is correct is called unit testing. 
//Each unit test is designed to ensure that a particular behaviour of the unit is correct

//BEST PRACTICE 
//write your program in small, well defined units(functions or classes),compile often and test your code as you go.
//If a program is short and accepts user input, trying a  variety of user input might be sufficient.
// But as your program gets longer and longer, this becomes less sufficient, and ther is more value in testing individual functions and classes before intergrating them into the rest of the program 
//so how can we test our code in units?

//1. Informal testing
//Afer writing a unit of code (a function, a class, or some other discrete "package" of code), you can write some code to test the unit that was just added and then erase the test once the test passes. 
//For example consider this program

//we want to test the following program
//for simplicity we'll ignore that 'y' is sometimes counted as a vowel
//NOTE: I am writing this function after main() because it is a documentation
bool isLowerVowel(char vowel)
{
    switch ( vowel )
    {
        case 'a' :
        case 'e' :
        case 'o' :
        case 'i' :
        case 'u' :
            return true;
        default:
            return false;
    }

}

[[maybe_unused]] int main()
{ 
   //Temporary tests to validate it works
    std::cout << isLowerVowel('a') << '\n';   //temporary test code, should produce 1

    std::cout << isLowerVowel('q') << '\n';    //temporary test code,  should produce 0

    return 0;
}

//If the results come back as 1 and 0, then you're good to go. You know your functions works for some baic cases, and  you can test if the code works for the other cases 'e, i , o, u''
//Remember if you want your program to return true or false instead of 1 or 0 you can use std::boolalpha
// std::cout << std::boolalpha << isLowerVowel('e') << '\n';    //Returns true instead of 1

//2.Preserving your tests
//Although writing temporary test is  a quick and easy way to test some code, at some point you mmay want to test the same code again later.
//perhaps of you modified a function to add a new capability, and want to make sure it did not break anuthign that was already working
//For this reason it makes more sense to  preserve your tests so they can be run again in future.
//For example, instead of erasing your temporary test code, you coudl move the tests into a testVowel function

[[maybe_unused]] bool isLowerVowel( char vowel)
{
    switch (vowel)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    
    
    default:
        return false;
    }
}

//here if you need to retest thing later

void testVowel()
{
    //Temporary tests to validate it works
    std::cout << isLowerVowel('a') << '\n';   //temporary test code, should produce 1

    std::cout << isLowerVowel('q') << '\n';    //temporary test code,  should produce 0

}

[[maybe_unsused]] int main()
{
    return 0;
}

//AS you create more tests you can simply add them in the testVowel() function
//3.Automating your test functions
// One problem with the above test function is that it relies on you to manually verify the results when you run it 
//This require you to remeber what the expected answer was at worst (assuming you didn't document it). and manually compare the actual results to the expected results.
//we can do better by writing a test function that contsings both the tests and expected answers and compares them so we don't have to

int testVowel2()
{
    //returns the number of the test that failed, or zero if all tests passed
    if(!isLowerVowel('a')) return 1;

    if (isLowerVowel('q')) return 2;

    return 0;

}

int main()
{
    int result {testVowel2()};
    if (result != 0)
        std::cout << "testVowel2 test " << result << "failed.\n";

    else
        std::cout << "testVowel2 tests passed\n";

    return 0;
}

//Now you can call testVowel() at anytime to re-prove that you have not broken anything, and the test 

//4.Unit testing frameworks
//third party libraries exists that are used to test code

//You should start testing your code as soon as you have written a non-trivial function.
