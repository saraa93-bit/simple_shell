#include "main.h"
/**
* exec_command - handling the command execution.
* @argv: an argument.
* Return: nothing.
*/
void exec_command(char **argv)
{
char *nd = NULL;

if (argv)
{
	nd = argv[0];

	if (execve(nd, argv, NULL) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}
}
/**
 * h_exit - function that terminate the prog when
 * user types "exit".
 * @c: the string to be read.
 * Return: nothing.
 */
void h_exit(char *c)
{
	int i;

	i = _strcmp("exit", c);
	if (i == 0)
	{
		free(c);
		exit(EXIT_SUCCESS);
	}
}
/**
 * _getenv - function that gets the value of the
 * @n: the name of the variable.
 * Return: the value of the variable.
*/
char *_getenv(char *n)
{
	int l;
	char **env;

	env = environ;
	l = _strlen(n);
	while (env)
	{
		if (strncmp(n, *env, l) == 0 && (*env)[l] == '=')
		{
			return (*env + l + 1);
		}
		env++;
	}
	return (NULL);
}
