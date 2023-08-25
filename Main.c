#include "shell.h"

/*void pr(char **w)
{
	int i;

	for (i = 0; w[i] != NULL; i++)
		printf("[%d] = %s\n", i, w[i]);
}*/

void active()
{
	char *prompt = "($) ";
	char *line, *path, *temp;
	char **words;
	int st = -1, shift = 0;

	head_d = build_dirs();
	while (1)
	{
		my_puts(prompt);
		line = Read();
		shift = my_strspn(line, cmd_DELIM);
		words = Parse(line, cmd_DELIM);

		if (words != NULL)
		{
			if(my_strchr(words[0], '/'))           
				st = Execute(words);
			else if ((path = find_path(head_d, words[0])))
			{
				temp = words[0];
				words[0] = path;
				st = Execute(words);
				free(temp - shift);
				shift = 0;
			}
			else
				perror("Not Found--->");

			free(words[0] - shift);
			free(words);
		}
		free(line);

		if (st >= 0)
			exit(st);
	}
}

void lazy()
{
	char *line, *path, *temp;
	char **words;
	int st = -1, shift = 0;

	head_d = build_dirs();
	while (1)
	{
		line = Read();
		shift = my_strspn(line, cmd_DELIM);
		words = Parse(line, cmd_DELIM);

		if (words != NULL)
		{
			if(my_strchr(words[0], '/'))           
				st = Execute(words);
			else if ((path = find_path(head_d, words[0])))
			{
				temp = words[0];
				words[0] = path;
				st = Execute(words);
				free(temp - shift);
				shift = 0;
			}
			else
				perror("Not Found--->");

			free(words[0] - shift);
			free(words);
		}
		free(line);

		if (st >= 0)
			exit(st);
	}
}

int main(void)
{
		if (isatty(STDIN_FILENO))
			active();
		else
			lazy();

		return (0);
}
