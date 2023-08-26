#include "shell.h"
/**
 * parse : search, extract, and manipulate strings
 * cpy : copy string
 * @words : pointer to string
 * @i : integer
 * return
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
