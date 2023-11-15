#include "main.h"
/**
* read_line - function that reads a line from stdin
*
* Return: pointer to the line
*/
char *read_line(void)
{
	char *lineptr = NULL;
	size_t num = 0;
	ssize_t tnchars;

	tnchars = getline(&lineptr, &num, stdin);
	if (tnchars == -1)
	{
		_free(lineptr);
		return (NULL);
	}
	return (lineptr);
}
/**
 * copy_line - function that copies a line
 * @line: pointer to the line
 * Return: pointer to the copy of the line
*/
char *copy_line(char *line)
{
	char *copy_lineptr = NULL;
	size_t len = _strlen(line);

	copy_lineptr = malloc(sizeof(char) * (len + 1));
	if (copy_lineptr == NULL)
	{
		perror("error");
		return (NULL);
	}
	_strcpy(copy_lineptr, line);
	return (copy_lineptr);
}
/**
 * tokens_number - function that counts the number of tokens
 * @line: pointer to the line
 * Return: number of tokens
 */
int tokens_number(char *line)
{
	char *lineptr = _strdup(line);
	const char *delim = "\t \a\n";
	int tn_tokens = 0;
	char *token;

	token = strtok(lineptr, delim);

	while (token != NULL)
	{
		tn_tokens++;
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	tn_tokens++;

	_free(lineptr);

	return (tn_tokens);
}
/**
 * argv_array - function that creates an array of tokens
 * @line: pointer to the line
 * Return: pointer to the array of tokens
*/
char **argv_array(char *line)
{
	int n;
	char *copy_lineptr = _strdup(line);
	char **argv = malloc(sizeof(char *));
	char *token;
	const char *delim = "\t \a\n";

	token = strtok(copy_lineptr, delim);

	for (n = 0; token != NULL; n++)
	{
		argv = realloc(argv, (n + 1) * sizeof(char *));
		argv[n] = _strdup(token);
		token = strtok(NULL, delim);
	}
	argv = realloc(argv, (n + 1) * sizeof(char *));
	argv[n] = NULL;

	_free(copy_lineptr);

	return (argv);
}
