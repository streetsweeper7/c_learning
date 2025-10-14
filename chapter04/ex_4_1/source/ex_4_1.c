/*
* This program implements a binary search with only
* one conditional check within the loop instead of
* two. 
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);

// Declare some useful functions
int strindex_r(char source[], char searchfor[]);

char pattern[] = "cat\0";    /* pattern to search for */ 

/* find all lines matching pattern */
int main()
{
    char line[MAXLINE];
    int found = 0;
    int index = -1;

    while (get_line(line, MAXLINE) > 0)
    {
        if ((index = strindex_r(line, pattern)) >= 0)
        {
            printf("%s", line);
            printf("Rightmost: %d\n", index); 
            found++;
        }
        return found;
    }
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{

    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* strindex_r: return the position of the rightmost
   occurence of t in s, or -1 if there is none. */
int strindex_r(char s[], char t[])
{
    int i, j, k;
    int source_len = strlen(s);
    int pattern_len = strlen(t);


    for (i = source_len-1; i >= 0; i--)
    {
        for (j=i, k=pattern_len-1; k >= 0 && s[j]==t[k]; j--, k--)
            ;
        if (k < 0)
            return i - pattern_len + 1;
    }
    return -1;
}
