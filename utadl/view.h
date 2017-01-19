#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <vector>
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
	void printlist(std::vector <std::string> data);
};

#endif
