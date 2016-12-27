#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>

#include <unistd.h>

class View
{
public:
	void welcome();
	void menucommands();

	void help();
	void errorout(int errarg);
};

#endif