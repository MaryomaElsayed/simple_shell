#include "shell.h"

size_t my_strlen(const char *m)
{
	    size_t start_count = 0;

	        while (*m != '\0')
			    {
				            start_count++;
					            m++;
						        }

		    return start_count;
}

char* my_strchr(const char* str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch) 
			return (char*)str;
						        
		str++;
	}

	return NULL;
}

char *my_strcpy(char *destination, const char *source)
{
	    int m = 0;

	        if (destination == NULL)
			    {
				            return NULL;
					        }

		    if (destination == source)
			        {
					        return destination;
						    }

		        while (source[m] != '\0')
				    {
					            destination[m] = source[m];
						            m++;
							        }

			    destination[m] = '\0';

			        return destination;
}

char *my_strdup(const char *src)
{
	    size_t len = my_strlen(src);
	        char *duplicate = (char *)malloc((len + 1) * sizeof(char));

		    if (src == NULL) 
			        {
					        return NULL;
						    }

		        if (duplicate == NULL)
				    {
					            return NULL;
						        }
			    
			    my_strcpy(duplicate, src);
			        return duplicate;
}

int my_strcmp(char *m1, char *m2)
{
	    int Compare_Status = 0;

	        while ((*m1 != '\0' && *m2 != '\0') && *m1 == *m2)
			    {
				            m1++;
					            m2++;
						        }

		    Compare_Status = (*m1 == *m2) ? 0 : (*m1 > *m2) ? 1 : -1;

		        return Compare_Status;
}
