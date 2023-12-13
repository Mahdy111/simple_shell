#include "shell.h"

/**
 * execom - checks and executes the commands
 * @command: is the input string of the command to be executed.
 * @name: is the file name.
 * Return: void.
 */
void execom(char *command, char *name)
{
char *path = getenv("PATH");
char *commandpath = NULL;
char *token1;
char *token2 = _strtok(command, ' ');
char *error1 = "Failed to obtain PATH enviroment variable.\n";

if (path == NULL)
{
write(STDOUT_FILENO, error1, _strlen(error1));
return;
}
token1 = _strtok(path, ':');
while (token1 != NULL)
{
commandpath = _strcat(token1, "/");
commandpath = _strcat(commandpath, token2);
if (_strcmp(token2, "echo") == 0)
{
echo(command);
return;
}
if (_strcmp(token2, "env") == 0)
{
env();
return;
}
if (access(commandpath, F_OK) == 0)
{
execute(command, commandpath);
return;
}
token1 = _strtok(NULL, ':');
}
error(token2, name);
return;
}
