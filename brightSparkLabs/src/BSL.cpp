#include "BSL.h"

BSL::BSL(void) // constructor - setup string vector
{
	// Slight overhead for using std::vector of std::string instead of string literals
	// but makes editing easier
	strings.push_back("brightSPARK Labs");
	strings.push_back("brightSPARK");
	strings.push_back("Labs");
	
	// Allows for full mapping and extension, but has overhead
	// longer execution time, but more flexibility
	mapper.push_back(std::tuple<uint8_t, std::string>(5, "brightSPARK") );
	mapper.push_back(std::tuple<uint8_t, std::string>(3, "Labs") );
}


// can use a map<int, string> or vector<tuple<int, string> > to map specific numbers to string output, have it be read in to save time 
// iterating thru for every i has longer exec time than if branching
void BSL::brightSparkLabs(void) 
{
	for(uint8_t i = 1; i < max_range; ++i)
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

// allows user to write function to a file/cout
void BSL::brightSparkLabs(std::ostream& out_method) 
{
	for(uint8_t i = 1; i < max_range; ++i)
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
					 
// allows flexibility in printing strings on specific numbers, but exec time is longer
void BSL::mappedBrightSparkLabs(void)
{
	for(uint8_t i = 1; i < max_range; ++i)
	{
		std::cout << std::to_string(i);
		for(auto it = mapper.begin(); it != mapper.end(); ++it)
		{
			if( i % std::get<0>(*it) == 0)
			{
				std::cout << " " << std::get<1>(*it);
			}
		}
		std::cout << "\n";
	}
}		