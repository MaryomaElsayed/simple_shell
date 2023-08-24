nclude "shell.h"

/**
 *  * my_strlen - returns the length of a string
 *   * @m: pointer to the string
 *    *
 *     * Return: length of the string
 *      */
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

/**
 *  * my_strchr - Locate the first occurrence of a character in a string.
 *   * @str: Pointer to the input string.
 *    * @ch: The character to be found.
 *     * 
 *      * Return: A pointer to the first occurrence of the character 'ch' in 'str',
 *       *         or NULL if the character is not found.
 *        */
char* my_strchr(const char* str, int ch)
{
	    while (*str != '\0') {
		            if (*str == ch) {
				                return (char*)str;
						        }
			            str++;
				        }
	        return NULL;
}

/**
 *  * my_strcpy - copies the string pointed to by source, including the terminating
 *   * null byte, to the buffer pointed to by destination
 *    * @destination: pointer to the destination buffer
 *     * @source: pointer to the source string
 *      *
 *       * Return: pointer to the destination buffer
 *        */
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

/**
 *  * my_strdup - Duplicates a string in memory.
 *   * @src: Pointer to the source string to be duplicated.
 *    *
 *     * Return: On success, returns a pointer to a newly allocated memory
 *      * containing a duplicate of the source string. On failure, returns NULL.
 *      */
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

/**
 *  * my_strcmp - compares two strings
 *   * @m1: pointer to the first string to be compared
 *    * @m2: pointer to the second string to be compared
 *     *
 *      * Return: 0 if the strings are equal, a positive value if the first non-matching
 *       * character in m1 is greater than the corresponding character in m2, and a negative
 *        * value otherwise
 *         */
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
