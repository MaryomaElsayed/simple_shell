#include "shell.h"

int Execute(char **args)
{
    char **en = NULL;
    pid_t id;
    int st;
            
    id = fork();
    if (id ==  0)
    {
        if (execve(args[0], args, en) == -1)
        {
            perror("Error in execve: ");
            exit(EXIT_FAILURE);
        }
    }
    else if (id < 0)
    {
        perror("Error in fork: ");
        exit(EXIT_FAILURE);
    }
    else
    {
        do {
            waitpid(id, &st, WUNTRACED);
        } while (!WIFEXITED(st) && !WIFSIGNALED(st));
    } 

    return (-1);
}
