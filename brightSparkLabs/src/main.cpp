#include <iostream>
#include <fstream>
#include <chrono>
#include "BSL.h"

int main()
{
	BSL BSL_obj{};
	BSL_obj.setStartRange(20);
	BSL_obj.setStartRange(20000);
	BSL_obj.setEndRange(50);
	BSL_obj.setEndRange(5);
	BSL_obj.mappedBrightSparkLabs();
	BSL_obj.setStartRange(1);
	BSL_obj.setEndRange(99);
	BSL_obj.mappedBrightSparkLabs();
	return 0;
}
