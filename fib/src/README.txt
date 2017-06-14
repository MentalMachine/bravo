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
specific given input:

f(0) = 0
f(1) = 1
f(2) = 1
f(5) = 5
f(13) = 233

The speed part is calculating a large Fibonacci number and using the chrono library to time how long 
each algorithm took to compute a large fibonacci number. 

///////////////////////////
// DEVELOPMENT SUMMARY  //
/////////////////////////

The algorithm development consisted of developing the classic recursion Fibonacci algorithm, and 
then moving onto the tail recursion-based algorithm and the iterative based algorithms.

Via testing, the iterative approach was by far the fastest and most reliable as tail recursion cam often be compiler dependent, however I was curious if there was any other faster methods.
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

All numerical variables are of type uint64_t given [0, (2^64 - 1)] range. This has the draw back of 
integer overflow errors when n->inf. If the end user did require f(n) such that 64 bit unsigned integers could not
hold the result, alternative variables types could be considered such as floating point (however this also brings in the issue
of accuracy) or storing the number as an array of 8 bit unsigned integers, such as a string, each representing the ith fibonacci digit.

The latter idea was impemented as largeNumberFib, which takes in the nth fibonacci number an user wishes to calculate
and a number represting the number of digits they want the answer in. This code executes roughly slightly slower that the 
tail recursion code, however it doesn't have the drawback of overflow, as a string of 1000 characters is not a 
huge amount of data for a program to hold.

The current largeNumberFib does not take into account the possiblity of the user entering insufficient amount of characters to
hold the desired fibonacci number, a means of outputting a warning string that the whole number has been cut off should be implemented
if this posses a sufficent problem.