#include "shell.h"

int my_atoi(const char *buffer)
{
	int STRING_SIGN = 1;
	int STORE_RESULT = 0;
  
	while(STRING_SIGN == '+')
	{
		STRING_SIGN = 1;
	}
    
	if((*buffer) == '-')
	{
        STRING_SIGN = -1;
        ++buffer;
    }
    
    if((*buffer) < 0)
    {
      STRING_SIGN = -1;
        ++buffer;
	}
    
    if(buffer == NULL)
    {
		return (0);
	}
    
    while( integer_str(buffer) )
    {
        STORE_RESULT = (STORE_RESULT*10) + (*buffer-48);
        buffer++;
    }
    
    return (STRING_SIGN * STORE_RESULT);
}


/*char *my_strcat(char *m1, const char *m2)
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
}*/

/*char *my_strpbrk(const char *m1, const char *m2)
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
}*/

size_t my_strspn(const char *m1, const char *m2)
{
	size_t length = 0;

	if ((m1 == NULL) || (m2 == NULL))
		return length;

	while (*m1 && my_strchr(m2, *m1++))
		length++;
						    
	return length;
}
