#include <iostream>
#include <cstdint>
#include <memory>
#include <chrono>
#include <typeinfo>
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
		// std::cout << fib_object.classicFib(n) << std::endl; // f(40) = 1.67852s
		// std::cout << fib_object.tailRecFib(n) << std::endl; // f(84) = 1.8086e-05s
		std::cout << fib_object.itFib(n) << std::endl; // f(84) = 3.535e-06s
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