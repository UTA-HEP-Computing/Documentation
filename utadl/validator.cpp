#include "validator.h"

const std::vector <std::string> stags = {"-h", "-i", "-ln", "-lu", "-t", "-sk"};
const std::vector <std::string> ltags = {"-help", "-interact", "-nodes", "-users", "-torque", "-sshkey"};
const int numtags = stags.size();

// The following IPs are placeholders for final address/hostnames.
// Separated between gener_ips and admin depending if program is run with sudo priv.

const std::vector <std::string> gener_ips = {"192.168.1.13", "192.168.1.5"};
const std::vector <std::string> admin_ips = {"192.168.1.2", "192.168.1.3", "192.168.1.4", "192.168.1.5",
                                             "192.168.1.6", "192.168.1.7", "192.168.1.13"
                                            };

const std::vector <std::string> tltags = {""};


const bool isroot()
{
	return geteuid() == 0;
}

const int argselector(int argselect, char ** argv)
{
	for (int i = 0; i < numtags; i++)
	{
		if (((std::string)argv[argselect]).compare(ltags[i]) == 0 || ((std::string)argv[argselect]).compare(stags[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}