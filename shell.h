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

#define cmd_DELIM " \n"
#define pth_DELIM ":"

extern char **environ;

typedef struct dirs_list
{
	    char *dir;
	        int len;
		    struct dirs_list *next;
} list_d;
struct dirs_list *head_d;

/******Execute*****/
char *Read();
char **Parse(char *line, char *delim);
int Execute(char **args);

/*****PATH*****/
list_d *build_dirs();
list_d *add_dir(list_d **head, char *str);
void free_list(list_d *h);
char *find_path(list_d *h, char *cmd);

#endif
