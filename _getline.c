#include "shell.h"
/**
 * _getline - is function that takes input from the user
 * and keeps on asking the user for input until he enters one.
 * Return: a pointer to the user input.
 */

char *_getline(void)
{
char *temp;
char *end;
int i;

do {
write(STDOUT_FILENO, "$ ", _strlen("$ "));
temp = malloc(256);
fgets(temp, 256, stdin);
} while (temp[0] == '\n');
end = malloc(strlen(temp));
i = 0;

while (i <= _strlen(temp))
{
if (temp[i] != '\n')
{
end[i] = temp[i];
}
i++;
}
end[i] = temp[i];
free(temp);
return (end);
}
