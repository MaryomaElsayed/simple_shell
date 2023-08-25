#include "shell.h"

list_d *build_dirs()
{
    int i;
    list_d *head = NULL;
    char **dirs = Parse(my_getenv("PATH"), pth_DELIM);

    for(i = 0; dirs[i] != NULL; i++)
        add_dir(&head, dirs[i]);
    
    free(dirs[0]);
    free(dirs);
 
    return (head);  
}

list_d *add_dir(list_d **head, char *str)
{
    list_d *New = malloc(sizeof(list_d));
    int l = my_strlen(str);

    New->len = l;
	New->dir = my_strdup(str);
	New->next = *head;
	*head = New;

    return(New);
}

void free_list(list_d *h)
{
    list_d *temp;

    while (h)
    {
        temp = h;
        h = h->next;
        free(temp->dir);
        free(temp);
    }
}
