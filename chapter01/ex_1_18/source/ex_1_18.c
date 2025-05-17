/*
* Author: John Banda
* Date  : 14/05/2025
* Description:
* This programs removes trailing blanks and tabs from each line of
* input and deletes entirely blank lines. 
*/
#include <stdio.h>

#define MAXLINE (1000) /* Maximum input line length */

int get_line(char line[], int maxline);

int main()
{
    int len;    /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0)
            printf("%s", line);
    return 0;

}

/* get_line:    Read a line into s, return length 
                Trailing blank spaces are removed from the final
                line */
int get_line(char s[], int lim)
{
    int c, i;
    c = 0;
    int non_blank_found_at = -1;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (c != '\t' && c != ' ') non_blank_found_at = i; 
        
        if (i < lim - 1)
        {
            s[i] = c;
        }
    }

    if (c == '\n')
    {
        if (i < lim - 1)
        {
            s[non_blank_found_at + 1] = c;
            ++non_blank_found_at;
        }
        ++i;
    }

    // One important bit of this exercise is the terminating character
    // It doesn't matter what the rest of the array has, as long as the
    // terminating character is rightly placed. 
    if (i < lim) 
    {
        s[non_blank_found_at + 1] = '\0';
    }
    else
    {
        s[lim - 1] = '\0';
    }
   
    int len = 0;
    if (non_blank_found_at >= 0) len = i; 
    else
        len = 0;
    // If no non_blank character was found, this will return zero.
    // Otherwise, it'll return the correct length minus discarded
    // trailing blanks 
    return len; 
}

