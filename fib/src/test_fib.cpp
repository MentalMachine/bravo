// tests-factorial.cpp
#include "catch.hpp"
#include "fib.h"

TEST_CASE( "Fibonacci numbers are computed", "[fibonacci]" ) {
    REQUIRE( fib(1) == 1 );
    REQUIRE( fib(2) == 1 );
    REQUIRE( fib(3) == 2 );
}


TEST_CASE( "40th Fibonacci number is computed", "[fibonacci]" ) {
    REQUIRE( fib(40) == 102334155 );
}
