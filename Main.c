#include "shell.h"

/*void pr(char **w)
{
	int i;

	for (i = 0; w[i] != NULL; i++)
		printf("[%d] = %s\n", i, w[i]);
}*/

int check_cmd(char **words, char *line)
{
	int st = -1, shift = 0, flag;
	char *path, *temp;

	shift = my_strspn(line, cmd_DELIM);
	if (words != NULL)
	{
		flag = Built_in(words[0]);

		if(my_strchr(words[0], '/'))           
			st = Execute(words);
		else if(flag)
			st = Ex_Built_in(words);
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

	return (st);
}

void active()
{
	char *prompt = "($) ";
	char *line;
	char **words;
	int st;

	head_d = build_dirs();
	while (1)
	{
		my_print(prompt);
		line = read_line();
		words = Parse(line, cmd_DELIM);
		st = check_cmd (words, line);

		free(line);

		if (st >= 0)
			exit(st);
	}
}

void lazy()
{
	char *line;
	char **words;
	int st;

	head_d = build_dirs();
	while (1)
	{
		line = read_line();
		words = Parse(line, cmd_DELIM);

		st = check_cmd (words, line);
		
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
