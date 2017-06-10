#include <iostream>
#include <cstdint>
#include <memory>
#include <chrono>
#include <typeinfo>
#include "fib.h"

using namespace std;

int main()
{
	std::unique_ptr<uint8_t> reservedMemory(new uint8_t[32768]); //reserve memory in case run out of memory from large fib call
	try
	{
		fibonacci fib_object{};
		
		uint64_t n = fib_object.getUserInput();
		
		std::cout << fib_object.classicFib(n) << std::endl;
	}
	catch(std::bad_alloc ex)
	{
		reservedMemory.reset(); // clear memory to ensure cerrcan run
		cerr << "Program ran out of memory" << endl;
		exit(1);
	}
	return 0;
}