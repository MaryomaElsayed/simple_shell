#include "shell.h"

/**
 * check_cmd - check
 * @words: args
 * @line: line
 * @h: head
 * Return: integer
*/
int check_cmd(char **words, char *line, list_d *h)
{
	int st = -1, shift = 0, flag;
	char *path = NULL, *temp;

	shift = my_strspn(line, cmd_DELIM);
	if (words != NULL)
	{
		flag = Built_in(words[0]);
		if (h != NULL)
			path = find_path(h, words[0]);

		if (my_strchr(words[0], '/'))
			st = Execute(words);
		else if (flag)
			st = Ex_Built_in(words, h);
		else if (path)
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

/**
 * active - interactive
*/
void active(void)
{
	char *prompt = "($) ";
	char *line;
	char **words;
	int st;
	struct dirs_list *h;

	h = build_dirs();
	while (1)
	{
		my_print(prompt);
		line = read_line(h);
		words = Parse(line, cmd_DELIM);
		st = check_cmd(words, line, h);

		free(line);

		if (st >= 0)
			exit(st);
	}
}

/**
 * lazy - non_interactive
*/
void lazy(void)
{
	char *line;
	char **words;
	int st;
	struct dirs_list *h;


	h = build_dirs();
	while (1)
	{
		line = read_line(h);
		words = Parse(line, cmd_DELIM);

		st = check_cmd(words, line, h);

		free(line);

		if (st >= 0)
			exit(st);
	}
}

/**
 * main - start
 * Return: 0
*/
int main(void)
{
		if (isatty(STDIN_FILENO))
			active();
		else
			lazy();

		return (0);
}
