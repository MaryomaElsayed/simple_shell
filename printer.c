#include "shell.h"

int my_putchar(char c)
{
	return (write(1, &c, 1));
}

void print_line(char *str)
{
	while (*str != '\0') 
	{
		my_putchar(*str);
		str++;
	}
}
