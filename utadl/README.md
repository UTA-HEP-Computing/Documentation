utadl is a cli tool to help get new users started with using torque, checking free nodes, and creating ssh keys. 
Additionally sudoers have the ability to create ldap users, and check if users are running jobs. 


Use cases: 

general:
1. Torque usage and form generation
	a. form generation based on ldap info

2. ping machines for activity
3. help list commands and usage
4. create ssh keys

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

	-lu or -users
	list users and if they're running a job (system resource usage)

	-sk or -sshkey
	generates ssh keys for torque node access

	-i or -interactive
	interactive mode



code notes:


need to validate arguments, seperate class

also need to validate inputs for form generation

