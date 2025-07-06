/*
* Author: John Banda
* Date  : 14/05/2025
* Description:
* This program prints all lines that have a length longer than 80 chars 
*/
#include <stdio.h>

#define MAXLINE (1000) /* Maximum input line length */
#define THRESHOLD (80) /* Lines greater than the threshold will be printed*/

int get_line(char line[], int maxline);

/* Print the longest input line */
int main()
{
    int len;    /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > THRESHOLD) /* there was a line */
            printf("%s", line);
    return 0;

}

/* get_line: Read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    c = 0;
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

