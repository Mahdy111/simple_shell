#include "shell.h"
/**
 * execute - executes the command.
 * @str: is the command.
 * @path: is the full path of the command.
 * Return: void.
 */
void execute(char *str, char *path)
{
char *commands[2];
pid_t pid;

commands[0] = _strtok(str, ' ');
commands[1] = NULL;
pid = fork();
if (pid < 0)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execve(path, commands, NULL);
perror("execve failed");
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
return;
}
}
