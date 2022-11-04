#ifndef _SIMPLESHELL_
#define _SIMPLESHELL_
/* Libraries */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
/* Prototypes */
char **usetok(char *buff);
extern char **environ;
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strtok(char *str, char *limi);
char *_strchr(char *stri, char car);
unsigned int _strcspn(char *str, char *pre);
void _printenv(void);
char *concat(char *s1, char *s2);
char *get_path(void);
char **concat_path(char **args);
void _execve(char **args);
void free_double(char **ptr);
#endif
