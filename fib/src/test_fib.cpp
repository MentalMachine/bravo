#include <chrono>
#include <iostream>
#include <cstdint>
#include "catch.hpp"
#include "fib.h"

fibonacci fib_obj{};

uint64_t large_n = 90;
uint64_t large_n_value = 2880067194370816120ULL; 

// needs a restructure so the speed benchmarks are easier to read, etc
// move them into another section?

TEST_CASE( "classicFib", "[fibonacci]" )  // simple test to ensure correctness
{
	REQUIRE( fib_obj.classicFib(0) == 0 );
    REQUIRE( fib_obj.classicFib(1) == 1 );
	REQUIRE( fib_obj.classicFib(3) == 2 );
    REQUIRE( fib_obj.classicFib(5) == 5 );
    REQUIRE( fib_obj.classicFib(13) == 233 );
}


TEST_CASE( "classicFib(40)", "[fibonacci]" ) // f(40) to check speed
{
	std::chrono::duration<double> diff;
    auto start = std::chrono::high_resolution_clock::now();
    REQUIRE( fib_obj.classicFib(40) == 102334155 );
	diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "classic Fib @ 40: " << diff.count() << "s" << std::endl;
}

TEST_CASE( "tailRecFib", "[fibonacci]" )  // simple test to ensure correctness
{
    REQUIRE( fib_obj.tailRecFib(0) == 0 );
	REQUIRE( fib_obj.tailRecFib(1) == 1 );
	REQUIRE( fib_obj.tailRecFib(3) == 2 );
    REQUIRE( fib_obj.tailRecFib(5) == 5 );
    REQUIRE( fib_obj.tailRecFib(13) == 233 );
}


TEST_CASE( "tailRecFib(large_n)", "[fibonacci]" ) // f(large_n) to check speed
{
	std::chrono::duration<double> diff;
    auto start = std::chrono::high_resolution_clock::now();
    REQUIRE( fib_obj.tailRecFib(large_n) == large_n_value );
	diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "tail Rec Fib @ " << large_n << ": " << diff.count() << "s" << std::endl;
}

TEST_CASE( "itFib", "[fibonacci]" )  // simple test to ensure correctness
{
	REQUIRE( fib_obj.itFib(0) == 0 );
    REQUIRE( fib_obj.itFib(1) == 1 );
	REQUIRE( fib_obj.itFib(3) == 2 );
    REQUIRE( fib_obj.itFib(5) == 5 );
    REQUIRE( fib_obj.itFib(13) == 233 );
}

TEST_CASE( "itFib(large_n)", "[fibonacci]" ) // f(large_n) to check speed
{
	std::chrono::duration<double> diff;
    auto start = std::chrono::high_resolution_clock::now();
    REQUIRE( fib_obj.itFib(large_n) == large_n_value );
	diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "it Fib @ " << large_n << ": " << diff.count() << "s" << std::endl;
    
}

TEST_CASE( "matrixFib", "[fibonacci]" )  // simple test to ensure correctness
{
	REQUIRE( fib_obj.matrixFib(0) == 0 );
    REQUIRE( fib_obj.matrixFib(1) == 1 );
	REQUIRE( fib_obj.matrixFib(3) == 2 );
    REQUIRE( fib_obj.matrixFib(5) == 5 );
    REQUIRE( fib_obj.matrixFib(13) == 233 );
}

TEST_CASE( "matrixFib(large_n)", "[fibonacci]" ) // f(large_n) to check speed
{
	std::chrono::duration<double> diff;
    auto start = std::chrono::high_resolution_clock::now();
    REQUIRE( fib_obj.matrixFib(large_n) == large_n_value );
	diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "matrix Fib @ " << large_n << ": " << diff.count() << "s" << std::endl;
    
}

TEST_CASE( "largeNumberFib", "[fibonacci]" )  // simple test to ensure correctness
{
	REQUIRE( fib_obj.largeNumberFib(0, 5) == "00000" );
    REQUIRE( fib_obj.largeNumberFib(1, 5) == "00001" );
	REQUIRE( fib_obj.largeNumberFib(3, 5) == "00002" );
    REQUIRE( fib_obj.largeNumberFib(5, 5) == "00005" );
    REQUIRE( fib_obj.largeNumberFib(13, 5) == "00233" );
}

TEST_CASE( "largeNumberFib(large_n)", "[fibonacci]" ) // f(large_n) to check speed
{
	std::chrono::duration<double> diff;
    auto start = std::chrono::high_resolution_clock::now();
    REQUIRE( fib_obj.largeNumberFib(large_n, 20)  == "02880067194370816120" );
	diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "large Number Fib @ " << large_n << ": " << diff.count() << "s" << std::endl;
    
}