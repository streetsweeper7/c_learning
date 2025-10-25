/*
* This program concatenates two strings
* Author: John Banda
* Date: 25 September 2025
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void pstrcat(char *s, char *t);

int main()
{

    char source[] = "def";
    char dest[MAX_LEN];
    strcpy(dest, "abc");
    
    // Copy source into dest
    pstrcat(dest, source);

    // Check if we have the right value
    printf("%s\n", dest);
    return 0;
}

/* strcat: concatenate t to the end of s; s must be big
 * enough */
void pstrcat(char *s, char *t)
{
    while (*s) s++; /* find end of s */
       ; 
    while (*s++ = *t++) /* copy t */
        ;
}

