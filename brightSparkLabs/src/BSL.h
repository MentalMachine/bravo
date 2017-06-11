#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <cstdint>

class BSL
{
	public:
		BSL(); // specific constructor
		~BSL() = default; // defualt destructor
		BSL (const BSL& rhs) = delete; // delete Copy constructor not needed, etc
		BSL (BSL&& rhs) = delete; // delete Move constructor
		BSL& operator = (const BSL& rhs ) = delete; // delete Copy assignment
		BSL& operator = (BSL&& rhs)  = delete; // delete Move assignment
		
		void brightSparkLabs(); // prints specific strings on specific numbers
		void brightSparkLabs(std::ostream& out_method); // same as above but allows output to be piped to file (useful for platforms that don't natively support shell output redirection or file needs to kept in memory)
		void mappedBrightSparkLabs(void); // allows flexibility in printing strings on specific numbers, but exec time is longer
	private:
		std::vector<std::string> strings; // allows flexibility in printing strings but not on what number
		std::vector<std::tuple<uint64_t, std::string> > mapper; // stores numbers and strings to print
		uint64_t max_range = 100; 
	protected:
};