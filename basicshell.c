#include "simple_shell.h"

/**
* my_handler - a signal handler
* @var: Variable type int.
* Return: void function.
*/
void my_handler(int var)
{
	(void) var;
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}
/**
* _line - Function that use getline.
* Return: Variable type char *.
*/
char *_line(void)
{
	char *buff = NULL;
	size_t size = 0;
	int var_get;

	var_get = getline(&buff, &size, stdin);
	if (var_get == EOF)
	{
		free(buff);
		exit(0);
	}
	if (buff == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(buff);
		exit(-1);
	}
	buff[_strlen(buff) - 1] = '\0';
	return (buff);
}
/**
* usetok - Shell functions
* @buff: to save info
* Return: A char value.
*/
char **usetok(char *buff)
{
	unsigned int n = 0;
	char *tok, **toks;

	toks = malloc(64 * sizeof(char *));
	if (toks == NULL)
	{
		return (NULL);
		exit(-1);
	}
	tok = _strtok(buff, " \n\t");

	while (tok != NULL)
	{
		toks[n] = tok;
		n++;
		tok = _strtok(NULL, " \n\t");
	}
	toks[n] = NULL;
	return (toks);
}
/**
* main - Contains the basic Shell functions
* Return: void.
*/
int main(void)
{
	char **args, *buff;
	int other;
	pid_t pid;

	signal(SIGINT, my_handler);
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		buff = _line();
		args = usetok(buff);
		if (args[0] == NULL)
		{	free(buff);
			free(args);
			continue;
		}
		if (_strcmp(buff, "env") == 0)
			_printenv();
		else if (_strcmp(buff, "exit") == 0)
		{	fflush(stdout);
			free(args);
			free(buff);
			exit(0);
		}
		pid = fork();
		if (pid == 0)
		{	_execve(args);
		}
		else
			waitpid(pid, &other, WUNTRACED);
		free(args);
		free(buff);
	}
	return (0);
}
