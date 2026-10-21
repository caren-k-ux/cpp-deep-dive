//The ability to generate random numbers can be useful in certain kinds of programs particularly in games
// take games for example without random events monsters would attack you the same way, you'd always find the same treasure, the dungen layou would never change etc...and that would not make a really good game
// computers are generally incapable of generating truly random numbers(atleast through software). Instead modern programs typically simulate randomness using and algorithm
// Algorithms and states
//An algorithm is a finite sequence of instructions that can be followed to solve some problem or produce some useful result
//Because computers can execute instructions and manipulate  data more quickly than we do, algorithms are often written using programmng languages allowing us to automate asks, in C++ algorithms are typically implemented using reusable functions


//here is a simple algorithm

#include <iostream>

int plusOne()
{
    static int s_state { 3 }; // only initialized the first time this function is called
    //static ensures this local variable is  not destroyed at the end of the function but retains memory of it first value  for the entire lifespan  of the program 
    //Generate the next number

    ++s_state;

}

int main()
{
    std::cout << plusOne() << '\n';    //4
    std::cout << plusOne() << '\n';    //5
    std::cout << plusOne() << '\n';     // 6 

    return 0;
}

// this algorithm is pretty simple. The first time we call plusOne(), s_state is initialized to the value 3. Then the next number in the output is sequence is generated and returned
// An algorithm is considered to be satful if it retains some info across calls 
//conversly stateless algorithm does not store any information( and must bbe given all the information if it needs to work with it whenever it is called).
//our plusOne() is staeful, in that it uses the static variable s_state to store the last number that was generated.
//When applied to algorithms, tha term STATE refers o the current values held in stateful variables(those retained across function calls)
// our algogrithm is considered deterministic, meaning hat for a given input( the value provided for start), it will always produce the same output sequence  every time it is executed

//Pseudo-random number generators (PRNGs)
//to simulate randomness programs typically use a pseudo-random number generator, an algorithm that generates a sequence of numbers whose properties simulate a sequence of random numbers

unsigned int LCG16()
{
    static unsigned int s_state { 0 };

    s_state = 8253729 * s_state + 2396403;

    return s_state % 32768;
}


int main()
{
    for (int count { 1 }; count <= 100; ++count)
    {
        if (count % 10 == 0) 
            std::cout << '\n';

    }

    return 0;


}
