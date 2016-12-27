#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <cstdlib>
#include <iostream>

#include <unistd.h>

class View
{
public:
	void welcome();
	void menucommands();

	void noarg();
	void help();
};

#endif