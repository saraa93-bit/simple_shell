#include "main.h"
/**
 * main - function that executes the shell
 * @ac: number of arguments
 * @argv: array of arguments
 * Return: zero on success
*/

int main(int ac, char **argv)
{
	(void)ac;
	(void)argv;

	if (isatty(STDIN_FILENO) == 1)
		interactive_shell();
/*call the execution function*/
	else
		non_interactive_shell();
	return (0);
}
