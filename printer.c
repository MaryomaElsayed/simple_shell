#include "shell.h"

int my_putchar(char c)
{
	return (write(1, &c, 1));
}

void my_puts(char *str)/*with out new line*/
{
	while (*str != '\0') 
	{
		my_putchar(*str);
		str++;
	}
}
