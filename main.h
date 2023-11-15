#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* functions prototype */

char* read_line(void);
void interactive_shell(void);
void non_interactive_shell(void);
char** argv_array(char* line);
int tokens_number(char* line);
char* copy_line(char* line);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
void h_exit(char *c);
void exec_command(char **argv);
char *_getenv (char *n);

#endif
