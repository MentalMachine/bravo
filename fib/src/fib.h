#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>
#include <cstdio>

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
		void fibMatrixProduct(uint64_t fib_matrix_A[2][2], uint64_t fib_matrix_B[2][2]); // store the product of two matrices into fib_matrix_A
		void fibMatrixRaiseByPower(uint64_t fib_matrix[2][2], uint64_t n); // matrix exponentiation fibonacci
		uint64_t matrixFib(uint64_t n); // matrix implementation of fibonacci
		std::string largeNumberFib(uint64_t n, uint64_t number_of_digits);
	private:
	protected:
};