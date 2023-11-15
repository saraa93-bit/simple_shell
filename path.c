#include"main.h"
/**
 * 
*/
char *h_path(char **p, char **n)
{
	char *t, **cat;
	int i, j, k;
	struct stat status;

	for (i = 0; n[i]; i++)
	{
		t = malloc(60);
		_strcat(t, n[i]);
		_strcat(t, "/");
		_strcat(t, p[0]);

		if (stat(t, &status) == 0)
		{
			for (k = 0; p[k] != '\0'; k++)
				;
			cat = malloc(sizeof(char *) * (k + 1));
			cat[k] = NULL;
			cat[0] = _strdup(t);

			for (j = 1; p[j]; j++)
				cat[j] = _strdup(p[j]);
			execute(cat);
			return (t);
		}
		_free(t);
	}
	return (NULL);
}
/**
 * 
*/
char **f_path(void)
{
	char *p;
    char **t; 
    char *d;

	d = ":";
	p = _getenv("PATH");
	t = splits(p, d);
	return (t);
}
