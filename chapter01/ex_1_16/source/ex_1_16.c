/*
* Author: John Banda
* Date  : 14/05/2025
* Description:
* This program prints the length of arbitrarily long input lines and 
* as much as possible of the text. 
*/
#include <stdio.h>

#define MAXLINE (1000) /* Maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* Print the longest input lnie */
int main()
{
    int len;    /* current line length */
    int max;    /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        // Print the line that was gotten
        printf("%s, %d\n", line, len);
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    return 0;

}

/* get_line: Read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    c = i = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i < lim - 1)
        {
            s[i] = c;
        }
    }
    if (c == '\n')
    {
        if (i < lim - 1)
            s[i] = c;
        ++i;
    }

    if (i < lim) 
        s[i] = '\0';
    else
        s[lim - 1] = '\0';
    
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    
    while ((to[i] = from[i]) != '\0')
        ++i;
}
