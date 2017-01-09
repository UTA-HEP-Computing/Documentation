#include "controller.h"

using namespace std;

void Controller::CLI(int argc, char** argv)
{
	try
	{
		switch (argselector(1, 0, argv))
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

		case 6:
			guide(argv);
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
		system("cat ~/.ssh/id_rsa.pub >> ~/.ssh/authorized_keys");
		return;
	}

	v.errorout(3);
}

void Controller::guide(char ** argv)
{
	switch (argselector(2, 1, argv))
	{
	case 0:
		system("man utadl_admin");
		break;

	case 1:
		system("man utadl_home");
		break;

	case 2:
		system("man utadl_dlkit");
		break;

	default:
		v.errorout(1);
	}
}
