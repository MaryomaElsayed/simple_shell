#include "shell.h"
/**
 * my_putchar : writes a single character to the 
 * standard output
 * @c : charachter
 * Return : prints outpuy
 */
int my_putchar(char c)
{
	return (write(1, &c, 1));
}

void my_puts(char *str)
{
	while (*str != '\0') 
	{
		my_putchar(*str);
		str++;
	}
	my_putchar('\n');
}

void my_print(char *str)
{
	while (*str != '\0') 
	{
		my_putchar(*str);
		str++;
	}
}
