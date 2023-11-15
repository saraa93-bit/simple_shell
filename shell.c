#include"main.h"
/**
 * interactive_shell - function that executes the shell
 * Return: void
*/
void interactive_shell(void)
{
	char *pro = "$ ";
	char *line = NULL;
	char **argv;
	char *c;
	const char *d = " \a\n\t";
	char **t;

	t = f_path(environ);
	printf("%s", pro);
	while (1)
	{
		line = read_line();
		argv = splits(line, d);
		c = args_path(argv, t);
		if (c == NULL)
		{
			execute(argv);
		}
		_free(line);
		_free(argv);
		_free(c);
	}
	return (0);

}
/**
 * non_interactive_shell - function that executes the shell
 * Return: void
*/
void non_interactive_shell(void)
{
	char *pro = "($) ";
	char *line = NULL;
	char **argv;
	char *c;
	const char *d = " \a\n\t";
	char **t;

	t = f_path(environ);
	printf("%s", pro);
	while (1)
	{
		line = read_line();
		argv = splits(line, d);
		c = args_path(argv, t);
		if (c == NULL)
		{
			execute(argv);
		}
		_free(line);
		_free(argv);
		_free(c);
	}
	return (0);

}
