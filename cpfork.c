#include "main.h"
/**
 * chilp_pid - function that creates a child process
 * Return: 0 if successful, 1 if not
*/
int chilp_pid(void)
{
	pid_t chilp;

	chilp = fork();

	if (chilp < 0)
	{
		printf(stderr, "Fork failed\n");
		return (1);
	}
	else if (chilp == 0)
	{
	printf("\n");
	}
	else
	{
		perror("Error");

		free(chilp);

		return (0);
	}
}
