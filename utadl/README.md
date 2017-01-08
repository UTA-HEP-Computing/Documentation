utadl is a general cli tool for use on the UTA HEP DL cluster. Created to help users getting familiar 


---------

Use cases: 

general:

1. Torque
  1. form generation based on ldap info
  2. check job status
2. ping general user-access nodes
3. help list commands and usage
4. create ssh keys
5. General system guide

sudoer:

1. create ldap users (leave to phpldapadmin)
2. check user resource usage
3. ping all nodes


---------





utadl:
	-h or -help
	command list

	-ln or -list
	list nodes

	-t or -torque
	runs torque form generator, make one liner option (-c)
		-c [or -create] one liner args that generates 
		-l [or -list] lists torque jobs
	-lu or -users
	list users and if they're running a job (system resource usage)

	-sk or -sshkey
	generates ssh keys for torque node access

	-i or -interact
	interactive mode

	-g or -guide
	Invokes man page with general notes taken from gitwiki guide

---------


General Notes:
- Make install will copy executable to /usr/local/bin which will be in $PATH, a configure file is not provided so if a different directory is desired it will need to be installed by hand.

- 


Code Notes:

- need to validate arguments, seperate class

- also need to validate inputs for form generation

- MVC MVC MVC

- check for tools:
  - fping
  - boost?

- switch to cpp based pinger insteaf of system("nmap") hack.

- Would be neat if -g pulled from web, and if net is down load an offline release. 
