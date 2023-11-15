#include"main.h"
/**
 * interactive_shell - function that executes the shell
 * Return: void
*/
void interactive_shell(void)
{
	char *pro = "$ ";
	char *line;
	char **argv;
	int i, j;

	while (1)
	{
		printf("%s", pro);
		line = read_line();
		if (line == NULL)
		{
			exit(EXIT_FAILURE);
		}
		argv = argv_array(line);
		j = fork();
		if (j == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (j == 0)
		{
			exec_command(argv);
			exit(0);
		} else
		{
			wait(NULL);
		}
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
		free(line);
	}
}
/**
 * non_interactive_shell - function that executes the shell
 * Return: void
*/
void non_interactive_shell(void)
{
	char *pro = "($) ";
	char *line;
	char **argv;
	int i, j;

	while (1)
	{
		printf("%s", pro);
		line = read_line();
		if (line == NULL)
		{
			exit(EXIT_FAILURE);
		}
		argv = argv_array(line);
		j = fork();
		if (j == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (j == 0)
		{
			exec_command(argv);
			exit(0);
		} else
		{
			wait(NULL);
		}
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
		free(line);
	}
}
