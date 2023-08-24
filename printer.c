#include "shell.h"

int _putchar(char c)
{
		return (write(1, &c, 1));
}

void print_line(char *str)
{
	    while (*str != '\0') {
		            putchar(*str);
			            str++;
				        }
}

