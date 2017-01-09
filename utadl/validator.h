#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "view.h"
#include <vector>
#include <string>
#include <sstream>
#include <unistd.h>
#include <iostream>
#include <exception>

extern const std::vector <std::string> stags;
extern const std::vector <std::string> ltags;
extern const std::vector <std::string> gtags;
extern const int numtags;

extern const std::vector <std::string> gener_ips;
extern const std::vector <std::string> admin_ips;

extern const bool isroot();
extern const int argselector(int argselect, int parseselect, char ** argv);
extern const std::vector <std::string> bashout(std::string command, int maxline);

#endif