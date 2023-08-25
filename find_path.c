#include "shell.h"

char *find_path(list_d *h, char *cmd)
{
	char *path;
	int sz, i, j;

	while(h)
	{
		sz = strlen(cmd) + h->len + 2;
		path = (char *) malloc(sizeof(char) * sz);
							        
		for(i = 0; i < h->len; i++)
			path[i] = h->dir[i];
		path[i] = '/';
		i++;
		for(j = 0; i < sz - 1; i++, j++)
			path[i] = cmd[j];
		path[i] = '\0';

		if (!access(path, F_OK | X_OK))
			return (path);/*you should free path*/

		h = h->next;
		free(path);
	}

	return (NULL);
}
