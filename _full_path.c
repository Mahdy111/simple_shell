#include "shell.h"

/**
 * full_path - gets the full path for execve
 *@arr: array
 *@environ: environ
 * Return: arr
 */
char *full_path(char arr[], char *environ[])
{
	int i = 0, str = 69;
	char *tmp = NULL, *token = NULL;
	static char *bff;
	struct stat st;

	for (i = 0; environ[i] != NULL; i++)
		if (strncmp(environ[i], "PATH=", 4) == 0)
			break;
	tmp = _dupstr(environ[i]);
	token = _strtok(tmp, ":");
	for (i = 0; token != NULL; i++)
	{
		bff = malloc((_strlen(token) + _strlen(arr) + 2) * sizeof(char));
		if (bff == NULL)
		{
			free(bff);
			return (arr);

		}
		_strcpy(bff, token);
		_strcat(bff, "/");
		_strcat(bff, arr);
		str = stat(bff, &st);
		if (str == 0)
			return (bff);
		free(bff);
		token = _strtok(NULL, ":");
	}
	free(tmp);
	return (arr);
}
