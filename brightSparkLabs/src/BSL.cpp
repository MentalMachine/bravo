#include "BSL.h"

BSL::BSL(void) // constructor - setup string vector
{
	strings.push_back("brightSPARK Labs");
	strings.push_back("brightSPARK");
	strings.push_back("Labs");
}

void BSL::brightSparkLabs(void) // can use a map<int, string> or vector<tuple<int, string> > to map specific numbers to string output, have it be read in to save time - iterating thru for every i has longer exec time
{
	for(uint8_t i = 1; i < 100; ++i)
	{
		std::cout << std::to_string(i);
		if(i % 5 == 0 && i % 3 == 0)
		{
			std::cout << " " << strings[0]; 
		}
		else if(i % 5 == 0)
		{
			std::cout << " " <<  strings[1];
		}
		else if(i % 3 == 0)
		{
			std::cout << " " <<  strings[2];
		}
		std::cout << "\n";
	}
}

void BSL::brightSparkLabs(std::ostream& out_method) // allows user to write function to a file/cout
{
	for(uint8_t i = 1; i < 100; ++i)
	{
		out_method << std::to_string(i);
		if(i % 5 == 0 && i % 3 == 0)
		{
			out_method << " " << strings[0]; 
		}
		else if(i % 5 == 0)
		{
			out_method << " " <<  strings[1];
		}
		else if(i % 3 == 0)
		{
			out_method << " " <<  strings[2];
		}
		out_method << "\n";
	}
}