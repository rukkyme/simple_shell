#include "simple_shell.h"

/**
* _printenv - Function to print.
*/
void _printenv(void)
{
	char **envp;

	for (envp = environ; *envp; envp++)
	{
		write(STDOUT_FILENO, *envp, _strlen(*envp));
		write(STDOUT_FILENO, "\n", 1);
	}
}
