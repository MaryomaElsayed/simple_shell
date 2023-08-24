#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

char *Read();
char **Parse(char *line);
int Execute(char **args);

char *find_path(char *COM);
char *check_path(char *com);

size_t my_strlen(const char *m);
char* my_strchr(const char* str, int ch);
char *my_strcpy(char *destination, const char *source);
char *my_strdup(const char *src);
int my_strcmp(char *m1, char *m2);

char *my_strcat(char *m1, const char *m2);
size_t my_strspn(const char *m1, const char *m2);
char *my_strpbrk(const char *m1, const char *m2);

int my_putchar(char c);
void my_pstr(const char *str);

#endif
