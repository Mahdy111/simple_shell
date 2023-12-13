#include "shell.h"

/**
 * main - Simple shell Project.
 * @argc: The number of arguments to the program.
 * @argv: An array of pointers to the arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
char *Userinput = malloc(256);
int i = 1;

if (argc > 1)
{
while (i < argc)
{
_strcat(Userinput, argv[i]);
if ((i + 1) != argc)
{
_strcat(Userinput, " ");
}
i++;
}
execom(Userinput, argv[0]);
}
while (argc == 1)
{
Userinput = _getline();
if (_strcmp(Userinput, "exit") == 0)
{
break;
}
execom(Userinput, argv[0]);
}
if (_strcmp(Userinput, "exit") != 0)
{
_putchar('\n');
}
free(Userinput);
return (0);
}
