#include "shell.h"

int my_exit(char **words)
{
    free_list(head_d);
    if (words[1])
    {
        return (atoi(words[1]));
    }
    else
    {
        return (0);
    }
}

int my_env()
{
    int i;

    for (i = 0; environ[i] != NULL; i++)
        my_puts(environ[i]);

    return (-1);
}
