#include "shell.h"
/**
 * error - prints error message on to stdout.
 * @str: is the command string.
 * @name: is the file name.
 * Return: void.
 */
void error(char *str, char *name)
{
char *error2 = ": command not found\n";
int i = 2;
int b = 0;
char *namefinal = malloc(_strlen(name) - 1);

while (name[i] != '\0')
{
namefinal[b] = name[i];
i++;
b++;
}
namefinal[b] = '\0';
write(STDOUT_FILENO, namefinal, _strlen(namefinal));
write(STDOUT_FILENO, ": ", _strlen(": "));
write(STDOUT_FILENO, str, _strlen(str));
write(STDOUT_FILENO, error2, _strlen(error2));
free(namefinal);
}
