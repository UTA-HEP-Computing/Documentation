#include "validator.h"

const std::vector <std::string> stags = {"-h", "-i", "-ln", "-lu", "-t", "-sk", "-g", "-v"};
const std::vector <std::string> ltags = {"help", "interact", "nodes", "users", "torque", "sshkey", "guide", "virtual"};

const std::vector <std::string> gtags = {"admin", "home", "dlkit"};

const int numtags = stags.size();

// The following IPs are placeholders for final address/hostnames.
// Separated between gener_ips and admin depending if program is run with sudo priv.
/*
const std::vector <std::string> gener_ips = {"192.168.1.13", "192.168.1.5"};
const std::vector <std::string> admin_ips = {"192.168.1.2", "192.168.1.3", "192.168.1.4", "192.168.1.5",
                                             "192.168.1.6", "192.168.1.7", "192.168.1.13"
                                            };
*/
const std::vector <std::string> gener_ips = {"supercomputer", "ditto"};
const std::vector <std::string> admin_ips = {"supercomputer", "ditto", "bigbird", "thingtwo", "thecount"};

const std::vector <std::string> tltags = {""};

const bool isroot()
{
	return geteuid() == 0;
}

const int argselector(int argselect, int parseselect, char ** argv)
{
	switch (parseselect)
	{
	case 0:
		for (int i = 0; i < numtags; i++)
		{
			if (((std::string)argv[argselect]).compare(ltags[i]) == 0 || ((std::string)argv[argselect]).compare(stags[i]) == 0)
			{
				return i;
			}
		}
		break;

	case 1:
		for (int i = 0; i < (int)gtags.size(); i++)
		{
			if (((std::string)argv[argselect]).compare(gtags[i]) == 0)
			{
				return i;
			}
		}
		break;
	}
	return -1;
}

const std::vector <std::string> bashout(std::string command, int maxline = 100)
{
	View v;
	std::vector <std::string> data;
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
