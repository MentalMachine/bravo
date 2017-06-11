#include <iostream>
#include <fstream>
#include "BSL.h"

int main()
{
	BSL BSL_obj{};
	
	std::ofstream output("output.txt");
	BSL_obj.brightSparkLabs(output);
	output.close();
	return 0;
}
