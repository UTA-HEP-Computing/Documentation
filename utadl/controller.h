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
	void guide(char ** argv);
	void virtualsetup();


private:
	View v;
};

#endif
