#include <stdio.h>
#include <string.h>

unsigned int is_delim(char c, const char *delim)
{
	    while (*delim != '\0')
		        {
				        if (c == *delim)
						            return 1;
					        delim++;
						    }
	        return 0;
}

char *my_strtok(char *srcString, const char *delim)
{
	    static char *backup_string = NULL;
	        if (srcString == NULL)
			    {
				            srcString = backup_string;
					            if (srcString == NULL)
							            {
									                return NULL;
											        }
						        }

		    while (1)
			        {
					        if (is_delim(*srcString, delim))
							        {
									            srcString++;
										                continue;
												        }
						        if (*srcString == '\0')
								        {
										            return NULL;
											            }
							        break;
								    }

		        char *ret = srcString;
			    while (1)
				        {
						        if (*srcString == '\0')
								        {
										            backup_string = srcString;
											                return ret;
													        }
							        if (is_delim(*srcString, delim))
									        {
											            *srcString = '\0';
												                backup_string = srcString + 1;
														            return ret;
															            }
								        srcString++;
									    }
}

int main()
{
	    // Input string
	    //     char srcString[] = "simple shell project";
	    //         // Delimiter
	    //             const char *delim = "; ";
	    //
	    //                 char *token = my_strtok(srcString, delim);
	    //                     while (token != NULL)
	    //                         {
	    //                                 printf("%s\n", token);
	    //                                         token = my_strtok(NULL, delim);
	    //                                             }
	    //                                                 return 0;
	    //                                                 }
	    //
