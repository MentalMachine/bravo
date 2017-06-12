fib Readme

///////////////////////
//	COMPILING	//
///////////////////////

All compiling can be done via make and the commands are as follows:

make fib // produces the Fibonacci program called fib

make test // produces a test program

make test_run // produces and runs the test program

make clean // deletes all object and program files in the directory

////////////////////
//	TESTING	//
///////////////////
Testing is done via the header-based testing library Catch, and consists of a setup file (tests_main.cpp)
and the file containing the actual tests (tests_fib.cpp)

The testing was broken down into two sections: algorithm correctness and algorithm speed.

The correctness part consists of verifying the algorithms are correct with specific values expected for
specific given input

The speed part is calculating a large Fibonacci number and using the chrono library to time how long 
each algorithm took to compute a large fibonacci number. 

///////////////////////
// DEV SUMMARY //
///////////////////////

The algorithm development consisted of developing the classic recursion Fibonacci algorithm, and 
then moving onto the tail recursion-based algorithm and the iterative based algorithms.

Via testing, the iterative approach was by far the fastest, however I was curious if there was any other faster methods.
Doing some research online, I found another method called Matrix Exponentiation, which is based translating the fibonacci
series to matrix form:

{ {1, 1}, {1, 0} } = { {F(n+1), F(n) }, {F(n), F(n-1)} }

and using

A^m = { iff even: (A^(m/2) ) ^ 2, iff odd A*(A^( (m-1)/2 )^2

to derive a reasonably simple recursion based method for calculating the fibonacci numbers.

This method does take longer or about the same as the iterative method at small numbers, but after f(200 ) or so,
the Matrix Exponentiation method becomes superior. 

In addition, a method to ensure the user enters the correct input (an integer from 0->inf) was implemented. This is a while loop that repeatedly takes
in string input until a suitable input string has been entered. The string is then returned as a uint64_t.