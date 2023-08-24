#include <stddef.h>

char *strtok(char *str, const char *delim)
{
	    static char *nextToken = NULL;

	        if (str != NULL) {
			        nextToken = str;
				    } else if (nextToken == NULL) {
					            return NULL;
						        }

		    char *start = nextToken;

		        while (*nextToken != '\0') {
				        const char *d = delim;
					        while (*d != '\0') {
							            if (*nextToken == *d) {
									                    *nextToken = '\0';
											                    nextToken++;
													                    if (start != nextToken - 1) {
																                        return start;
																			                } else {
																						                    start = nextToken;
																								                        break;
																											                }
															                }
								                d++;
										        }
						        nextToken++;
							    }

			    if (start == nextToken) {
				            return NULL;
					        } else {
							        return start;
								    }
}
int main()
{return 0;}
