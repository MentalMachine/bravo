#include "BSL.h"

BSL::BSL(void) // constructor - setup string vector
{
	setup();
}

// move all setup code outside of constructor into a specific function
void BSL::setup(void) 
{
	// Slight overhead for using std::vector of std::string instead of string literals
	// but makes editing easier
	strings.push_back("brightSPARK Labs");
	strings.push_back("brightSPARK");
	strings.push_back("Labs");
	
	// Allows for full mapping and extension, but has overhead
	// longer execution time, but more flexibility
	mapper.push_back(std::pair<uint64_t, std::string>(5, "brightSPARK") );
	mapper.push_back(std::pair<uint64_t, std::string>(3, "Labs") );
}

// can use a map<int, string> or vector<tuple<int, string> > to map specific numbers to string output, have it be read in to save time 
// iterating thru for every i has longer exec time than if branching
void BSL::brightSparkLabs(void) 
{
	for(uint64_t i = start_range; i <= end_range; ++i)
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

// allows user to write function to a file/cout if they cannot directly
// pipe the output from standard out to a file
void BSL::brightSparkLabs(std::ostream& out_method) 
{
	for(uint64_t i = start_range; i <= end_range; ++i)
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
	for(uint64_t i = start_range; i <= end_range; ++i)
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

bool BSL::setStartRange(uint64_t new_start_range)
{
	if(new_start_range > end_range)
	{
		std::cout << "New start range is larger than current end range - start range not changed" << std::endl;
		return 0;
	}
	start_range = new_start_range;
	return 1;
}

bool BSL::setEndRange(uint64_t new_end_range)
{
	if(new_end_range < start_range)
	{
		std::cout << "New end range is smaller than current start range - end range not changed" << std::endl;
		return 0;
	}
	end_range = new_end_range;
	return 1;
}

bool BSL::removePair(uint64_t number_to_remove, std::string string_to_remove) // allows user to delete a number to string mapping
{
	auto it = mapper.begin();
	for( ; it != mapper.end(); ++it)
	{
		if(std::get<0>(*it) == number_to_remove)
		{
			if(std::get<1>(*it) == string_to_remove) // ensures no accidental deletes by having the user give the number AND the string
			{
				mapper.erase(it);
				std::cout  << "Number and string successfully deleted" << std::endl;
				return 1; // successfully deleted number/string
			}
			else
			{
				std::cout << "Correct number given but incorrect string given - nothing deleted" << std::endl;
				return 0; // couldn't delete key/value
			}
		}
	}
	std::cout << "Incorrect number given - nothing deleted" << std::endl;
	return 0;
}

bool BSL::addPair(uint64_t number_to_add, std::string string_to_add) // allows user to add a number to string mapping
{
	auto it = mapper.begin();
	for( ; it != mapper.end(); ++it)
	{
		if(std::get<0>(*it) == number_to_add)
		{
			std::cout << "number and string already inserted - nothing added" << std::endl;
			return 0; // couldn't insert new number and string
		}
	}
	mapper.push_back(std::pair<uint64_t, std::string>(number_to_add, string_to_add) ); // number_to_add wasn't in mapper so it can be added
	return 1;
}