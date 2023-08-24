#include "shell.h"

/**
 *  * my_strcat - concatenates two strings
 *   * @m1: pointer to the original string
 *    * @m2: pointer to the string to be concatenated
 *     *
 *      * Return: pointer to the concatenated string
 *       */
char *my_strcat(char *m1, const char *m2)
{
	        char *word1 = m1;

		    if ((m1 == NULL) || (m2 == NULL))
			            return NULL;

		        while (*word1 != '\0')
				    {
					            word1++;
						        }

			    while (*m2 != '\0')
				        {
						        *word1++ = *m2++;
							    }

			        *word1 = '\0';
				    return m1;
}

/**
 *  * my_strpbrk - locates the first occurrence in a string of any character
 *   * from a second string
 *    * @m1: pointer to the string to be searched
 *     * @m2: pointer to the string containing the characters to match
 *      *
 *       * Return: a pointer to the byte in s that matches one of the bytes in accept,
 *        * or NULL if no such byte is found
 *         */
char *my_strpbrk(const char *m1, const char *m2)
{
	    if ((m1 == NULL) || (m2 == NULL))
		        {
				        return NULL;
					    }

	        while (*m1)
			    {
				            if (strchr(m2, *m1))
						            {
								                return (char *)m1;
										        }
					            else
							            {
									                m1++;
											        }
						        }

		    return NULL;
}

/**
 *  * my_strspn - gets the length of a prefix substring
 *   * @m1: pointer to the string to be checked
 *    * @m2: pointer to the string containing the characters to match
 *     *
 *      * Return: the length of the prefix substring
 *       */
size_t my_strspn(const char *m1, const char *m2)
{
	    size_t length = 0;

	        if ((m1 == NULL) || (m2 == NULL))
			        return length;

		    while (*m1 && strchr(m2, *m1++))
			        {
					        length++;
						    }

		        return length;
}
