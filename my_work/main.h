#ifndef MAIN_H
#define MAIN_H

/* librairies*/
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>

/* User input */
#define MAX_USER_INPUT_COMMAND 100

/* Proptotypes */
int _printstr(char *s);
int _putchar(char c);
char *_strtok(char *str, const char *delim);

#endif /*main.h*/
