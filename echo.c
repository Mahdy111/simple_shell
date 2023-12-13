#include "shell.h"
/**
 * echo - prints env message on to stdout.
 * @str: is the command
 * Return: void.
 */
void echo(char *str)
{
int i = 5;
while (str[i] != '\0')
{
if (str[i] != '"')
{
_putchar(str[i]);
}
i++;
}
_putchar('\n');
}
