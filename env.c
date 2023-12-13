#include "shell.h"
/**
 * env - prints env message on to stdout.
 * Return: void.
 */
void env(void)
{
char **env_var;

env_var = environ;
while (*env_var != NULL)
{
write(STDOUT_FILENO, *env_var, _strlen(*env_var));
write(STDOUT_FILENO, "\n", 1);
env_var++;
}
}
