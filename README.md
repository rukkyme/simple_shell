# simple_shell

# Description!

The shell is the command interpretor in an operating system such as Unix or GNU/Linux, it is a program that executes other programs. This shell has the basic functionality, it provides a computer user an interface so that the user can run different commands with some input data.

### Files

| File | Description |
| ------ | ------ |
| AUTHORS | Provides names and contacts to all the people that collaborated to this project |
| README | A simple description of the project |
| _execve.c | Function that verify for the arguments and accede to the path |
| _getenv.c | Function that search and return the environment and printed |
| _strcat.c | Function that concatenate two strings |
| _strcmp.c | Function that compare two strings |
| _strcpy.c | Function that copy strings |
| _strlen.c | Function that take the lenght of the string |
| basicshell.c | Contains the main function |
| man_1_simple_shell | Is the manual of the simple_shell |
| simple_shell.h | Header file, it addresses all the function prototypes we used |

### Requirements

simple_shell is designed to run in the Ubuntu linux environment and to be compiled using the GNU compiler collection v. gcc 4.8.4 with flags -Wall, -Werror, -Wextra, and -pedantic.

### Installation

* Clone this repository: https://github.com/igwevictor1/simple_shell.git
* Change directories into the repository: acd simple_shell
* Compile: gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
* Run the shell: ./hsh

### Authors

 - Victor Imeh
 - Joy Notie
