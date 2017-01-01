#include "view.h"

using namespace std;

void View::welcome()
{
	cout
	        << "Welcome "
	        << getenv("USER")
	        << "!"
	        << endl;
}

void View::menucommands()
{
	cout
	        << "Please choose from the following options: \n"
	        << "\t1 - View IP routes and status \n"
	        << "\t2 - View \n" ;
}

void View::help()
{
	cout
	        << "utadl - UTA Deep Learning helper"
	        << endl << endl
	        << "usage: utadl [argument] [tags] \t will run argument with applicable tags"
	        << endl << endl
	        << "Arguments:"
	        << endl
	        << "-h" << '\t' << "-help" << "\t\t" << "will show this usage guide - no tags"
	        << endl
	        << "-i" << '\t' << "-interact" << "\t\t" << "will run an interactive mode of the program - no tags"
	        << endl
	        << "-ln" << '\t' << "-nodes" << "\t\t" << "will list available nodes"
	        << "\n\t\t\t" << "-ln -ip [IP] to view status of a node by IP address"
	        << "\n\t\t\t" << "-ln -hn [HOSTNAME] to view status of a node by Hostname"
	        << endl
	        << "lu" << '\t' << "-users" << "\t\t" << "will list users who are online and job usage if applicable"
	        << endl
	        << "-t" << '\t' << "-torque" << "\t\t" << "will help generate Torque submission file"
	        << endl
	        << "-sk" << '\t' << "-sshkey" << "\t\t" << "will generate sshkey for user, important for Torque usage"
	        << endl;
}


void View::errorout(int errarg)
{
	cerr << "made it here";
	cout << "made it here out";
	switch (errarg)
	{
	case 0:
		cerr
		        << "ERROR 0: Could not parse internal argument." << endl;
		break;

	case 1:
		cerr
		        << "ERROR 1: Could not execute commands." << endl
		        << "Use -h or -help flag for usage." << endl;
		break;

	case 2:
		cerr
		        << "ERROR 2: No arguments specified." << endl
		        << "Use -h or -help flag for usage." << endl;
		break;

	default:
		cerr
		        << "ERROR X: Unknown error occured." << endl;
	}
}