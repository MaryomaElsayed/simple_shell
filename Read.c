#include "shell.h"

int my_getchar()
{
	unsigned char c;
	
	if (read(0, &c, 1) != 1)
		return (EOF);
	
	return ((int)c);
}

char *read_stream(void)
{
	int i = 0;
	char c;
	char *line = (char *)malloc(sizeof(char) * 1024);

	while (1)
	{
		c = getchar();

		if (c == EOF)
		{
			free(line);
			free_list(head_d);
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
			line[i] = c;
		i++;
	}
}

char *read_line()
{
	char *line = NULL;
	size_t n = 0;

	if(getline(&line, &n, stdin) == EOF)
	{
		free(line);
		free_list(head_d);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
