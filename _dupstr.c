#include "shell.h"

/**
 *_dupstr - duplicates a string
 *@str: string to dupplicate
 *Return: return duplicated string
 */

char *_dupstr(char *str)
{
	int i;
	int j;
	char *ch;

	if (str == 0)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		;
	}
	ch = malloc(sizeof(char) * (i + 1));
	if (ch == 0)
	{
		return (NULL);
	}
	for (j = 0; str[j] != '\0'; j++)
	{
		ch[j] = str[j];
	}
	ch[j] = '\0';
	return (ch);
}
