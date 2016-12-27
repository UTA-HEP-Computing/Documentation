#include "validator.h"


const std::vector <std::string> stags = {"-h", "-i", "-ln", "-lu", "-t", "-sk"};
const std::vector <std::string> ltags = {"-help", "-interact", "-nodes", "-users", "-torque", "-sshkey"};
const int numtags = stags.size();

// The following IPs are placeholders for final address/hostnames.
// Separated between gener_ips and admin depending if program is run with sudo priv.

const std::vector <std::string> gener_ips = {"192.168.1.13", "192.168.1.5"};
const std::vector <std::string> admin_ips = {"192.168.1.3", "192.168.1.4", "192.168.1.5", "192.168.1.7"}; 