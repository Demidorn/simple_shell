/*--------CREATING SIMPLE SHELL PROJECT -----*/
This simple shell displays a prompt and waits for user to insert/type in coomands to the terminal.

Resources
Read or watch:

Unix shell
Thompson shell
Ken Thompson
Everything you need to know to start coding your own shell concept page
man or help:

sh (Run sh as well)

Requirements
General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (why?)
Write a README with the description of your project
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker
GitHub
*There should be one project repository per group. If you and your partner have a repository with the same name in both your accounts, you risk a 0% score. Add your partner as a collaborator. *

Compilation
Your shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

TASK 0
	Write a beautiful code that passes the Betty checks
TASK 1
	Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:

use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments
execve will be the core part of your Shell, don’t forget to pass the environ to it…

TASK 2
	Handle command lines with arguments
TASK 3
	Handle the PATH
 	fork must not be called if the command doesn’t exist

TASK 4
	Implement the exit built-in, that exits the shell
        Usage: exit You don’t have to handle any argument to the built-in exit

TASK 5
	Implement the env built-in, that prints the current environment
TASK 6
	Write your own getline function
	Use a buffer to read many chars at once and call the least possible the read system call
	You will need to use static variables
	You are not allowed to use getline
	You don’t have to:

	be able to move the cursor

TASK 7
	You are not allowed to use strtok
TASK 8
	handle arguments for the built-in exit
Usage: exit status, where status is an integer used to exit the shell

TASK 9
	mplement the setenv and unsetenv builtin commands

setenv
Initialize a new environment variable, or modify an existing one
Command syntax: setenv VARIABLE VALUE
Should print something on stderr on failure
unsetenv
Remove an environment variable
Command syntax: unsetenv VARIABLE
Should print something on stderr on failure

TASK 10
	Implement the builtin command cd:

Changes the current directory of the process.
Command syntax: cd [DIRECTORY]
If no argument is given to cd the command must be interpreted like cd $HOME
You have to handle the command cd -
You have to update the environment variable PWD when you change directory
man chdir, man getcwd

TASK 11
	Handle the commands separator ;
TASK 12
	Handle the && and || shell logical operators
TASK 13
	Implement the alias builtin command
Usage: alias [name[='value'] ...]
alias: Prints a list of all aliases, one per line, in the form name='value'
alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value

TASK 14
	Handle variables replacement
Handle the $? variable
Handle the $$ variable

TASK 15
	Handle comments (#)

TASK 16
	Usage: simple_shell [filename]
Your shell can take a file as a command line argument
The file contains all the commands that your shell should run before exiting
The file should contain one command per line
In this mode, the shell should not print a prompt and should not read from stdin
