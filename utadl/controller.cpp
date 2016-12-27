#include "controller.h"


using namespace std;

//CLI 
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
			cerr << "Could not execute command." << endl;
		}

	}
	catch (...)
	{
		cerr << "Could not execute command." << endl;
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

void Controller::torque()
{

}

void Controller::sshkey()
{
	//v.sskgenmsg(1);
	system("ssh-keygen -f ~/.ssh/id_rsa");



}

vector <string> Controller::stparser(string command, int maxline)
{
	vector <string> data;
	try
	{
		FILE *stream = popen(command.c_str(), "r");

		const int max_buffer = 1024;
		char buffer[max_buffer];
		int lines = 0;

		if (stream)
		{
			while (!feof(stream))
			{
				if (fgets(buffer, max_buffer, stream) != NULL)
				{
					data.push_back(buffer);
					if (lines == maxline)
					{
						break;
					}
					lines++;
				}
			}
			pclose(stream);
		}
	}
	catch (...)
	{
		cerr << "Could not parse internal argument." << endl;
	}
	return data;
}