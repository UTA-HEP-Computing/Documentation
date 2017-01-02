utadl is a cli tool to help get new users started with using torque, checking free nodes, and creating ssh keys. 

Created to be used on linux cluster


Use cases: 

general:
1. Torque usage and form generation
	a. form generation based on ldap info
	b. check job status
2. ping to see if nodes are up
3. help list commands and usage
4. create ssh keys
5. 

sudoer:
1. create ldap users
2. check user resource usage
3. 







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



code notes:


need to validate arguments, seperate class

also need to validate inputs for form generation

MVC MVC MVC

Dockerize for nmap? boost? 

switch to cpp based pinger insteaf of system("nmap") hack.

