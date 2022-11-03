#include "simple_shell.h"
/**
* concat - concatenate strings
* @s1: pointer to args1
* @s2: pointer to args2
* Return: char result
*/
char *concat(char *s1, char *s2)
{
	char *result = malloc(_strlen(s1) + _strlen(s2) + 1);

	_strcpy(result, s1);
	_strcat(result, s2);
	return (result);
}
/**
* get_path -  obtain path
* Return: void function.
*/
char *get_path(void)
{
	char *var;
	int i = 0;

	while (environ[i])
	{
		var = _strtok(environ[i], "=");
			if (!_strcmp(var, "PATH"))
			{
				return (_strtok(NULL, "="));
			}
			var = _strtok(NULL, "=");
			i++;
	}
	return (NULL);
}
/**
* concat_path - concatenate path
* @args: double pointer to args
* Return: void function.
*/
char **concat_path(char **args)
{
	char *path, **paths, *tok, *tmp;
	int n = 0;

	path = get_path();
	tok = _strtok(path, ":");
	paths = malloc(64 * sizeof(char *));

	while (tok != NULL)
	{
		tmp = concat("/", args[0]);
		paths[n] = concat(tok, tmp);
		n++;
		tok = _strtok(NULL, ":");
		free(tmp);
	}
	paths[n] = NULL;
	return (paths);
}
/**
* _execve -  execute program
* @args: double pointer to args
* Return: void function.
*/
void _execve(char **args)
{
	int n = 0, exist = 0;
	char **path;

	path = concat_path(args);

	exist = access(args[0], F_OK | X_OK);

	if (exist == -1)
	{
		while (path[n])
		{
			exist = access(path[n], F_OK | X_OK);

			if (exist != -1)
			{
				args[0] = path[n];
				break;
			}
			n++;
		}
	}

	if (execve(args[0], args, environ) == -1)
	{
		perror("Error");
		free_double(path);
		free_double(args);
		exit(127);
	}
}
