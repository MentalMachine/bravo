#include <iostream>
#include <cstdint>
#include <memory>
#include "fib.h"

// NOTE: all input checking for fibonacci functions is done in fibonacci::getUserInput()

uint64_t fibonacci::getUserInput(void) // change the return type to tuple<bool, uint64_t> so to return failure/return state?
{
	bool correct_user_input_flag = false;
	
	while(!correct_user_input_flag)
	{
		std::cout << "Please enter a number" << std::endl;
		std::string input;
		try
		{
			if(!getline(std::cin, input) )
			{
				std::cout << "I/O error - exiting" << std::endl;
				return 0;
			}
		}
		catch(std::ios_base::failure fail)
		{
			std::cerr << "I/O error exception - exiting" << std::endl;
			exit(1);
		}

		bool invalid_char_flag = false;
		for(auto it = input.begin(); it != input.end(); ++it) // scan thru and check that the user actually entered numbers
		{
			if( (*it) > 0x39 || (*it) < 0x30)
			{
				invalid_char_flag = true;
				break;
			}
		}

		if(invalid_char_flag)
		{
			std::cout << "error: invalid character entered" << std::endl;
			continue;
		}
		
		if(!input.empty() ) // if here and input is not empty then it is a valid input 
		{
			// add check to ensure the number the user enters won't overflow?
			return stoi(input);
		}
		else
		{
			std::cout << "error: empty input entered" << std::endl;
			continue;
		}
	}
	return 0;
}

uint64_t fibonacci::classicFib(uint64_t n) // use recursion to compute fibonacci
{
	if(n < 3) // break condition, as n < 3 is only true for f(2) & f(1) which both equal 1
	{
		return 1;
	}
	return classicFib(n-1) + classicFib(n-2);
}

uint64_t fibonacci::tailRecFib(uint64_t n, uint64_t a, uint64_t b) // tail recursion fibonacci
{
	// NOTE: a & b default args of 1 and 0 respectively
    if(n < 2)
	{
        return a;
	}
    return tailRecFib(n - 1, a + b, a); // tail recursion as this can be directly inlined to prevent stack overflowing
}

uint64_t fibonacci::itFib(uint64_t n) // iterative fibonacci
{
    uint64_t a = 0; uint64_t b = 1; // a and b are the first two fibonaci numbers
    while(n > 0) // break condition, count down from n to -1
    {
        uint64_t c = a; // store as a becomes the sum of a and b, but b needs to be set to a's previous value
        a = a + b;
        b = c;
        --n;
    }
    return a; // holds the desired fibonacci number
}