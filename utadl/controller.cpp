#include "controller.h"

using namespace std;

void Controller::CLI(int argc, char** argv)
{
	try
	{
		for (int i = 0; i < numtags; i++)
		{
			if (((string)argv[1]).compare(ltags[i]) == 0 || ((string)argv[1]).compare(stags[i]) == 0)
			{
				lflag = i;
				break;
			}
		}

		switch(lflag)
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
			torque();
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
	vector <string> data;
	string command = "nmap ";
	command.append("192.168.1.254");
	
	data = stparser(command, 7);

	for (int i = 0; i < (int)data.size(); i++)
	{
		cout << data[i];
	}	
}

void Controller::users()
{
	
	vector <string> data = stparser("users", 1);
	
	for (int i = 0; i < (int)data.size(); i++)
	{
		cout << data[i];
	}
}


// Used for generating job files- may require supporting classes
void Controller::torque()
{

}

void Controller::sshkey()
{
	//v.sskgenmsg(true);
	system("ssh-keygen -f ~/.ssh/id_rsa");



}

// Update this function 
// Need cleaner way of storing system calls
vector <string> Controller::stparser(string command, int maxline)
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
