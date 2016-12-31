#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <string>

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
	void torque(int argc, char** argv);
	void sshkey();

	std::vector <std::string> stparser(std::string command, int maxline);

private:
	View v;
	int lflag;
};

#endif