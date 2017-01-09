#include "controller.h"

int main(int argc, char* argv[])
{
	Controller c;
	View v;
	
	if (argc < 2)
	{
		v.errorout(2);
		return 0;
	}

	c.CLI(argc, argv);
	return 0;
}
