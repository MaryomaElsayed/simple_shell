#include "shell.h"

void active()
{
	char *prompt = "($) ";
	char *line, *path, *temp;
	char **words;
	int st = -1, shift = 0;

	head_d = build_dirs();
	while (1)
	{
		printf("%s", prompt);
		line = Read();
		shift = strspn(line, cmd_DELIM);
		words = Parse(line, cmd_DELIM);

		if (words != NULL)
		{
			if(my_strchr(words[0], '/'))           
				st = Execute(words);
			else if ((path = find_path(head_d, words[0])))
			{
				temp = words[0];
				words[0] = path;
				free(temp - shift);
				shift = 0;
				st = Execute(words);
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
		shift = strspn(line, cmd_DELIM);
		words = Parse(line, cmd_DELIM);

		if (words != NULL)
		{
			if(my_strchr(words[0], '/'))           
				st = Execute(words);
			else if ((path = find_path(head_d, words[0])))
			{
				temp = words[0];
				words[0] = path;
				free(temp - shift);
				shift = 0;
				st = Execute(words);
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
