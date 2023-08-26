#include "shell.h"

/**my_strlen - a function wich returns the length
 * of a string
 * return : returns the value of length of a string
 * @m : the pointer of the string
 */
size_t my_strlen(const char *m)
{
	size_t ln = 0;

	while (*m != '\0')
	{
		ln++;
		m++;
	}

	return ln;
}

/**
 * my_atrchr : it is a function to locate the first
 * occurence of a specifice character in a string
 * @str : the pointrr for the inpute string
 * return : pointer to the first occurrence of a
 * character in the inpute string
 * or NULL if the character is not found in
 * the string
 * @ch : it is the character to be occurrend
 */
 *
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

/**
 * my_strcpy : It is a function to copy a string 
 * pointied to as source to a buffer pointed to
 * as destination
 * @src : pointer for the source
 * @dst : pointer to the destination
 *
 * Return : pointer to the destination
 */
char *my_strcpy(char *dst, const char *src)
{
	int m = 0;

	if (dst == NULL)
		return NULL;

	if (dst == src)
		return dst;

	while (src[m] != '\0')
	{
		dst[m] = src[m];
		m++;
	}

	dst[m] = '\0';

	return dst;
}

char *my_strdup(const char *src)
{
	size_t ln = my_strlen(src);
	char *dup = (char *)malloc((ln + 1) * sizeof(char));

	if (src == NULL) 
		return NULL;
		
	if (dup == NULL)
		return NULL;

	my_strcpy(dup, src);

	return (dup);
}

int my_strcmp(char *m1, char *m2)
{
	int cmp_st = 0;

	while ((*m1 != '\0' && *m2 != '\0') && *m1 == *m2)
	{
		m1++;
		m2++;
	}
	cmp_st = (*m1 == *m2) ? 0 : (*m1 > *m2) ? 1 : -1;

	return (cmp_st);
}
