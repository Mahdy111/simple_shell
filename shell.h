#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

#define MAX_COMMAND 100
#define MAX_ARGS 10

char *_getline(void);
char *_strtok(char *str, char deli);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
void execom(char *command, char *name);
int _strcmp(char *s1, char *s2);
void error(char *name);
void env(void);
void execute(char *str, char *path);
extern char **environ;
int _putchar(char c);
void echo(char *str);
void dubfree(char **arrptr);
char *full_path(char arr[], char *environ[]);

#endif
