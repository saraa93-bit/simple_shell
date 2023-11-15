#include "main.h"
/**
* exec_command - handling the command execution.
* @argv: an argument.
* Return: nothing.
*/
void exec_command(char **argv)
{
	pid_t i;
	int status;

	i = fork();
	if (i == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
			exit(1);
		}
	}
	else if (i > 0)
	{
		wait(&status);
	}
	else
		perror("Error:");

	return (0);
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
		_free(c);
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
		int k, i;
		char *v, *f;

	for (i = 0; environ[i]; i++)
	{
		v = malloc(1024);

		for (k = 0; environ[i][k] != '='; k++)
			v[k] = environ[i][k];

		if (_strcmp(v, n))
		{
			f = _strlen(environ[i]);
			_free(v);
			return (f);

		}
		_free(v);
	}
	return (NULL);
}
