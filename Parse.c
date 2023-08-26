#include "shell.h"

/**
 * Parse - split
 * @line: pointer to string
 * @delim: integer
 * Return: char**
 */
char **Parse(char *line, char *delim)
{
	char *cpy = my_strdup(line);
	char *token;
	char **words;
	int i;

	token = strtok(cpy, delim);
	if (token == NULL)
	{
		free(cpy);
		return (NULL);
	}

	words = (char **)malloc(sizeof(char *) * 64);
	for (i = 0; token != NULL; i++)
	{
		words[i] = token;
		token = strtok(NULL, delim);
	}
	words[i] = NULL;

	return (words);
}
