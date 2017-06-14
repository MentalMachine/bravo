#include <iostream>
#include <cstdint>
#include <memory>
#include <chrono>
#include "fib.h"

using namespace std;

int main()
{
	std::unique_ptr<uint8_t[]> reservedMemory(new uint8_t[32768]); //reserve memory in case run out of memory from large fib call
	try
	{
		fibonacci fib_object{};
		
		uint64_t n = fib_object.getUserInput(); //ensures user only enters an integer
		
		// timings averaged via chrono testing in test files
		// std::cout << fib_object.classicFib(n) << std::endl; 	// f(40) = 1.31s
		// std::cout << fib_object.tailRecFib(n) << std::endl; 	// f(90) = 4.07e-6s
		// std::cout << fib_object.itFib(n) << std::endl; 		// f(90) = 3.73e-6s
		// std::cout << fib_object.matrixFib(n) << std::endl; 	// f(90) = 3.65e-6s
		uint64_t number_of_digits = fib_object.getUserInput(); // ensures user only enters an integer
		std::cout << fib_object.largeNumberFib(n, number_of_digits) << std::endl; // 4.14e-5s
	}
	catch(std::bad_alloc ex)
	{
		reservedMemory.reset(); // clear memory to ensure cerr can run
		cerr << "Program ran out of memory" << endl;
		exit(1);
	}
	reservedMemory.reset(nullptr); // clear memory
	return 0;
}