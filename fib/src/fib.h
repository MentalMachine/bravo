#pragma once
#include <iostream>
#include <cstdint>
#include <memory>
#include <map>

class fibonacci
{
	public:
		fibonacci() = default; // defualt constructor
		~fibonacci() = default; // defualt destructor
		fibonacci (const fibonacci& rhs) = delete; // delete Copy constructor not needed, etc
		fibonacci (fibonacci&& rhs) = delete; // delete Move constructor
		fibonacci& operator = (const fibonacci& rhs ) = delete; // delete Copy assignment
		fibonacci& operator = (fibonacci&& rhs)  = delete; // delete Move assignment
		
		uint64_t getUserInput(void);
		uint64_t classicFib(uint64_t n); // use recursion to compute fibonacci
		uint64_t tailRecFib(uint64_t n, uint64_t a = 1, uint64_t b = 0); // tail recursion fibonacci
		uint64_t itFib(uint64_t n); // iterative implementation of fibonacci
	private:
	protected:
};