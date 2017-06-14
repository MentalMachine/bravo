#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
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
		
		void setup(void); // setup strings and mapper
		void brightSparkLabs(); // prints specific strings on specific numbers
		void brightSparkLabs(std::ostream& out_method); // same as above but allows output to be piped to file (useful for platforms that don't natively support shell output redirection or file needs to kept in memory)
		void mappedBrightSparkLabs(void); // allows flexibility in printing strings on specific numbers, but exec time is longer
		
		bool setStartRange(uint64_t new_start_range);
		bool setEndRange(uint64_t new_end_range);
		
		bool removePair(uint64_t number_to_remove, std::string string_to_remove); // allows user to remove number to string mapping
		bool addPair(uint64_t number_to_add, std::string string_to_add); // allows user to add number to string mapping
	private:
		std::vector<std::string> strings; // allows flexibility in printing strings but not on what number
		std::vector<std::pair<uint64_t, std::string> > mapper; // stores numbers and strings to print - vector chosen over map to allow for specific ordering of strings
		uint64_t start_range = 1; // default to 1
		uint64_t end_range = 99;  // default to 99
	protected:
};