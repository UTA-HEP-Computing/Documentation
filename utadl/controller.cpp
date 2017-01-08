#include "controller.h"

using namespace std;

void Controller::CLI(int argc, char** argv)
{
	try
	{
		switch (argselector(1, argv))
		{
		case 0: //HELP
			help();
			break;

		case 1: //INTERACT
			iCLI(argc, argv);
			break;

		case 2: //NODES
			nodes();
			break;

		case 3: //USERS
			users();
			break;

		case 4: //TORQUE
			torque(argc, argv);
			break;

		case 5: //SSHKEY
			sshkey();
			break;

		default:
			v.errorout(1);
		}
	}
	catch (...)
	{
		v.errorout(1);
	}
}

void Controller::iCLI(int argc, char** argv)
{
	v.welcome();
	v.menucommands();
}

void Controller::help()
{
	v.help();
}

void Controller::nodes()
{
	vector <string> cmdout, ips = (isroot() ? admin_ips : gener_ips);
	string command = "fping -t50 ";

	for (auto ip : ips)
	{
		cmdout.push_back(bashout(command + ip, 7)[0]);
	}
	v.printlist(cmdout);
}

void Controller::users()
{
	vector <string> userlist = bashout("who", 1);
	v.printlist(userlist);
}

// Used for generating job files- may require supporting classes
void Controller::torque(int argc, char** argv)
{
	if (argc < 4)
	{

	}
}

void Controller::sshkey()
{
	if (!isroot())
	{
		system("ssh-keygen -f ~/.ssh/id_rsa -q -N \"\" ");
		return;
	}

	v.errorout(3);
}

vector <string> Controller::bashout(string command, int maxline = 100)
{
	vector <string> data;
	try
	{
		FILE *cmdout = popen(command.c_str(), "r");

		const int buffmax = 1024;
		char buffer[buffmax];
		int lines = 0;

		if (cmdout)
		{
			while (!feof(cmdout))
			{
				if (fgets(buffer, buffmax, cmdout) != NULL)
				{
					data.push_back(buffer);
					if (lines == maxline)
					{
						break;
					}
					lines++;
				}
			}
			pclose(cmdout);
		}
	}
	catch (...)
	{
		v.errorout(0);
	}
	return data;
}
