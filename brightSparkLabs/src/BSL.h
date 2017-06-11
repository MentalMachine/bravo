#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class BSL
{
	public:
		BSL(); // specific constructor
		~BSL() = default; // defualt destructor
		BSL (const BSL& rhs) = delete; // delete Copy constructor not needed, etc
		BSL (BSL&& rhs) = delete; // delete Move constructor
		BSL& operator = (const BSL& rhs ) = delete; // delete Copy assignment
		BSL& operator = (BSL&& rhs)  = delete; // delete Move assignment
		
		void brightSparkLabs();
		void brightSparkLabs(std::ostream& out_method);
	private:
		std::vector<std::string> strings;
	protected:
};