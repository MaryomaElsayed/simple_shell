#include "shell.h"

char *Read()
{
	char *line = NULL;
	size_t n = 0;

	if(getline(&line, &n, stdin) == EOF)
	{
		perror("Error in getline: ");
		free(line);
		free_list(head_d);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
