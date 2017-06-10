#include <chrono>
#include <iostream>
#include <cstdint>
#include "catch.hpp"
#include "fib.h"

fibonacci fib_obj{};

uint64_t large_n = 84;
uint64_t large_n_value = 160500643816367088;

// needs a restructure so the speed benchmarks are easier to read, etc
// move them into another section?

TEST_CASE( "classicFib", "[fibonacci]" )  // simple test to ensure correctness
{

    REQUIRE( fib_obj.classicFib(1) == 1 );
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
    REQUIRE( fib_obj.tailRecFib(1) == 1 );
    REQUIRE( fib_obj.tailRecFib(5) == 5 );
    REQUIRE( fib_obj.tailRecFib(13) == 233 );
}


TEST_CASE( "tailRecFib(40)", "[fibonacci]" ) // f(40) to check speed
{
	std::chrono::duration<double> diff;
    auto start = std::chrono::high_resolution_clock::now();
    REQUIRE( fib_obj.tailRecFib(large_n) == large_n_value );
	diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "tail Rec Fib @ " << large_n << ": " << diff.count() << "s" << std::endl;
}

TEST_CASE( "itFib", "[fibonacci]" )  // simple test to ensure correctness
{
    REQUIRE( fib_obj.itFib(1) == 1 );
    REQUIRE( fib_obj.itFib(5) == 5 );
    REQUIRE( fib_obj.itFib(13) == 233 );
}

TEST_CASE( "itFib(40)", "[fibonacci]" ) // f(40) to check speed
{
	std::chrono::duration<double> diff;
    auto start = std::chrono::high_resolution_clock::now();
    REQUIRE( fib_obj.itFib(large_n) == large_n_value );
	diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "it Fib @ " << large_n << ": " << diff.count() << "s" << std::endl;
    
}