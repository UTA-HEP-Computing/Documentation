#include <string>
#include <cstdlib>
#include <iostream>

#include "controller.h"

using namespace std;

int main(int argc, char* argv[])
{
	Controller c;
	View v;
	
	if (argc < 2)
	{
		v.noarg();
		return 0;
	}

	c.CLI(argc, argv);
	
	return 0;
}
