#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * executeCommand - execute commands
 * @ptr: pointer value
 * @environ: Environment variable.
 * @array: Command.
 * @buff: Buffer.
 * @pt: Exit pointer
 * @status: Status
 * Return: Zero
 */
 
void executeCommand(char **ptr, char **environ, char **array, char *buff, int *pt, int status)
{
pid_t pid;
char errors[100];
int i = 0, execs = 0;

pid = fork(), execs++;
if (pid == 0)
{
	array[0] = full_path(array[0], environ);
	if (execve(array[0], array, environ) == -1)
	{	sprintf(errors, "%s: %d: %s: not found\n", ptr[0], execs, array[0]);
		write(STDERR_FILENO, errors, _strlen(errors)), free(buff);
		dubfree(array);
		i = 0;
		while (errors[i])
			errors[i++] = 0;
		exit(127);
	}
} else
	wait(&status), dubfree(array);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	*pt = WEXITSTATUS(status);
	return (0);
}

/**
 * dubfree - frees a double pointer
 * @arrptr: pointer to be freed
 */
 
void dubfree(char **arrptr)
{
	int i = 0;

	while (arrptr[i])
	{
		free(arrptr[i]);
		i++;
	}
	if (arrptr)
		free(arrptr);
}
