#include "fib.h"

// NOTE: all input checking for fibonacci functions is done in fibonacci::getUserInput()

// Get and checks user input
uint64_t fibonacci::getUserInput(void) 
{
	bool correct_user_input_flag = false;
	
	while(!correct_user_input_flag)
	{
		std::cout << "Please enter a number" << std::endl;
		std::string input;
		try
		{
			if(!getline(std::cin, input) )
			{
				std::cout << "I/O error - exiting" << std::endl;
				exit(EXIT_FAILURE);
			}
		}
		catch(std::ios_base::failure fail) // iff exception is thrown
		{
			std::cerr << "I/O error exception - exiting" << std::endl;
			exit(EXIT_FAILURE);
		}

		bool invalid_char_flag = false;
		for(auto it = input.begin(); it != input.end(); ++it) // scan thru and check that the user actually entered numbers
		{
			if( (*it) > 0x39 || (*it) < 0x30)
			{
				invalid_char_flag = true;
				break;
			}
		}

		if(invalid_char_flag)
		{
			std::cout << "error: invalid character entered" << std::endl;
			continue;
		}
		
		if(!input.empty() ) // if here and input is not empty then it is a valid input 
		{
			// add check to ensure the number the user enters won't overflow?
			return stoi(input);
		}
		else
		{
			std::cout << "error: empty input entered" << std::endl;
			continue;
		}
	}
	std::cout << "control escaped while loop - exiting" << std::endl; // worse case condition
	exit(EXIT_FAILURE);
}

// arrays are passed directly if size is constant
// stores the product of 2x2 matrixes in fib_matrix_A
void fibonacci::fibMatrixProduct(uint64_t fib_matrix_A[2][2], uint64_t fib_matrix_B[2][2])
{
	uint64_t a00 =  fib_matrix_A[0][0] * fib_matrix_B[0][0] + fib_matrix_A[0][1] * fib_matrix_B[1][0]; // matrix multiplication
    uint64_t a01 =  fib_matrix_A[0][0] * fib_matrix_B[0][1] + fib_matrix_A[0][1] * fib_matrix_B[1][1];
    uint64_t a10 =  fib_matrix_A[1][0] * fib_matrix_B[0][0] + fib_matrix_A[1][1] * fib_matrix_B[1][0];
    uint64_t a11 =  fib_matrix_A[1][0] * fib_matrix_B[0][1] + fib_matrix_A[1][1] * fib_matrix_B[1][1];
    fib_matrix_A[0][0] = a00;
    fib_matrix_A[0][1] = a01;
    fib_matrix_A[1][0] = a10;
    fib_matrix_A[1][1] = a11;
}

// implementation of Matrix Exponentiation 
// proceeds to recursivly [sic] itself wile dividing n by 2
// until n == 1 || 0, at which point control resumes in each
// previous control point and if then raises the power of the fibonacci matrix
// by 2 and then IFF n is odd, raises it by 1 again.
// this is repeated until the top control stack ends
void fibonacci::fibMatrixRaiseByPower(uint64_t fib_matrix[2][2], uint64_t n)
{
    if (n == 0 || n == 1) // break point
	{
        return;
	}
    uint64_t temp_fib[2][2] = {{1,1},{1,0}}; // base fibonacci matrix
    fibMatrixRaiseByPower(fib_matrix, n / 2); // recursion call here, multiple points of control stack here
    fibMatrixProduct(fib_matrix, fib_matrix); // raise the power by 2
    if (n % 2 != 0) // iff n is odd
	{
        fibMatrixProduct(fib_matrix, temp_fib); // raise the power by 1
	}
}

uint64_t fibonacci::classicFib(uint64_t n) // use recursion to compute fibonacci
{
	if(n == 0) // edge case of f(0) & break condition
	{
		return 0;
	}
	if(n < 3) // break condition, as n < 3 is only true for f(2) & f(1) which both equal 1
	{
		return 1;
	}
	return classicFib(n-1) + classicFib(n-2);
}

uint64_t fibonacci::tailRecFib(uint64_t n, uint64_t a, uint64_t b) // tail recursion fibonacci
{
	// NOTE: a & b default args of 1 and 0 respectively
	if(n == 0) // edge case of f(0)
	{
		return 0;
	}
    if(n < 2) // min n can be is 1, so n < 2 is sufficient
	{
        return a;
	}
    return tailRecFib(n - 1, a + b, a); // tail recursion as this can be directly inlined to prevent stack overflowing
}

uint64_t fibonacci::itFib(uint64_t n) // iterative fibonacci
{
    uint64_t a = 0; uint64_t b = 1; // a and b are the first two fibonaci numbers
    while(n > 0) // break condition, count down from n to 0
    {
        uint64_t c = a; // store as a becomes the sum of a and b, but b needs to be set to a's previous value
        a = a + b;
        b = c;
        --n;
    }
    return a; // holds the desired fibonacci number
}


// matrix based fibonacci - see 'fibMatrixRaiseByPower' for more detail
uint64_t fibonacci::matrixFib(uint64_t n) 
{
    uint64_t fib_matrix[2][2] = {{1,1},{1,0}}; // base fibonacci matrix
    if (n == 0)
	{
        return 0;
	}
    fibMatrixRaiseByPower(fib_matrix, n-1); // all of the work is done here via tail recursion calls.
    return fib_matrix[0][0]; // return F(n+1)
}

// set all elements to a specific value
void set(std::string& arr, uint8_t value)
{
    for(auto it = arr.begin(); it != arr.end(); ++it)
    {
        (*it) = value;
    }
}


// Algorithm is an iterative fibonacci, but
// instead of using regular integer variables to
// store values, use an array of chars (8-bit unsigned
// integers) to instead hold each digit of the result
// allowing for extremely large fibonacci results

// wrapped in std::string for easier printing and handling
std::string fibonacci::largeNumberFib(uint64_t n, uint64_t number_of_digits)
{

    std::string a;
    a.resize(number_of_digits); 
    set(a, 48+0);
	
	if(n==0)
	{
		return a;
	}
	
    a[0] = 48+1; // a = [0... 01] == 1
    std::string b;
    b.resize(number_of_digits);
    set(b, 48+0); // b = [0... 0] == 0
	
	while(n > 1)
	{
		uint8_t carry_over = 0; 
		for(uint64_t i = 0; i <number_of_digits; ++i)
		{
			uint8_t temp = a[i]; // store current digit of a
			a[i]  = ( a[i] + b[i] + carry_over) - 48; // add current digits plus carry over from last iteration, subtract 48 to get back to 0-9 ascii range
			if(a[i] > 57) // 57 == '9' ie sum of a[i], b[i] is 10 or more
			{
				carry_over = 1;
				a[i]-=10; // subtract 10 to go from 13 to 3 etc
			}
			else
			{
				carry_over = 0; // prevent flow on carry on
			}
			b[i] = temp;
		}
		--n;
	}
	
    std::reverse(a.begin(), a.end()); // ensure the number is readible
    return a;
}