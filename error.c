#include "shell.h"
/**
 * error - prints error message on to stdout.
 * @str: is the command string.
 * @name: is the file name.
 * Return: void.
 */
void error(char *name)
{
char *error2 = ": No such file or directory\n";

write(STDOUT_FILENO, name, _strlen(name));
write(STDOUT_FILENO, error2, _strlen(error2));
}
