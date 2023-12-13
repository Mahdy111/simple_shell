#include "shell.h"

/**
 *_strtok - a function that tokenize the string given as an argument.
 *@str: is a string to be tokenized.
 *Return:  pointer to the tokenized string.
 */
char *_strtok(char *str, char deli)
{
static char *currentstanding = NULL;
char *token;
int c = 0;
int i = 0;

if (str != NULL)
{
currentstanding = str;
}
else if (_strcmp(currentstanding, NULL) == 0 || *currentstanding == '\0')
{
return NULL;
}
while (*currentstanding == deli)
{
currentstanding++;
}

while (currentstanding[i] != deli && currentstanding[i] != '\0')
{
c++;
i++;
}

if (c == 0)
{
return NULL;
}

token = (char *)malloc(c + 1);

if (token == NULL)
{
return NULL;
}

for (i = 0; i < c; i++)
{
token[i] = currentstanding[i];
}
token[i] = '\0';

currentstanding += c;

return token;
}
