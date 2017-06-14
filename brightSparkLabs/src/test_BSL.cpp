#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include "catch.hpp"
#include "BSL.h"

BSL BSL_obj{};

bool matcher(std::ifstream& one, std::ifstream& two)
{
	std::string input1, input2;
	uint64_t input1_size = 0, input2_size = 0;
	while(getline(one, input1) )
	{
		++input1_size;
	}
	while(getline(two, input2) )
	{
		++input2_size;
	}
	if(input1_size != input2_size)
	{
		std::cout << "incorrect file sizes" << std::endl;
		std::cout << "input1: " << input1_size << " " << "input2: " << input1_size << std::endl;
		return 0;
	}
	while(getline(one, input1) )
	{
		getline(two, input2);
		if(input1 != input2)
		{
			std::cout << "input1: " << input1 << " " << "input2: " << input2 << std::endl;
			return 0;
		}
	}	if(!two.is_open())
	{
		exit(1);
	}
	return 1;
}

TEST_CASE( "brightSPARK Labs text matcher", "[]" )  // simple test to ensure correctness
{

//	REQUIRE( BSL_obj.brightSparkLabs() == 1 );
	std::string file1 = "output_test.txt";
	std::string file2 = "required_output.txt";
	
	std::ofstream output(file1.c_str() );
	BSL_obj.brightSparkLabs(output);
	output.close();
	
	std::ifstream one(file1.c_str() );
	std::ifstream two(file2.c_str() );
	if(!one.is_open() || !two.is_open())
	{
		exit(1);
	}
	
	REQUIRE( matcher(one, two) == 1 );	if(!two.is_open())
	{
		exit(1);
	}
}