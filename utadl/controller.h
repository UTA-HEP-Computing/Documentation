#ifndef CONTROLLER_H
#define CONTROLLER_H 2016

#include <vector>
#include <string>
#include <iostream>

#include "view.h"
#include "validator.h"

class Controller
{
public:
	void CLI(int argc, char** argv);
	void iCLI(int argc, char** argv);

	void help();
	void nodes();
	void users();
	void torque();
	void sshkey();

	std::vector <std::string> stparser(std::string command, int maxline);


private:
	View v;
	int lflag;

};

#endif