/*
* Author: John Banda
* Date  : 02/07/2025
* Description:
* This program removes all comments from a C program.
*/
#include <stdio.h>

#define MAXLINE (1000)      /* Maximum input line length */
#define TAB_STOP_LEN (3u)   /* This is the number of characters to the next
                             tab stop */

int get_line(char line[], int maxline);
int next_tab_stop(int curr_index, int spaces_to_tabstop);

int main()
{
    int len;    /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%s", line);
        printf("\n");
    }
    return 0;

}

/* get_line:    Read a line into s, return length */
int get_line(char s[], int lim)
{
    int c = 0, i = 0, last_char = 0;
    int comment_type    = 0; // (1) //  (2) /*
    int quote_type      = 0;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && (c != '\n' || comment_type == 2); )
    {
        // Find out if we are within a quote here 
        if (comment_type == 0)
        {
            if (quote_type == 1 && c == '\'' && last_char != '\\')
            {
                quote_type = 0;
            } else if (quote_type == 2 && c == '\"' && last_char != '\\')
            {
                quote_type = 0;
            } else if (!quote_type && c == '\'')
            {
                quote_type = 1;
            } else if (!quote_type && c == '\"')
            {
                quote_type = 2;
            }
        }
        
        if ( quote_type == 0 && comment_type == 0 && c == '/' && last_char == '/')
        {
            // If the last character was a '/', then we know we are in a comment
            comment_type = 1;

        } else if (quote_type == 0 && comment_type == 0 && c == '*' && last_char == '/')
        {
            // If the last character was a '/', and we currently have a '*', then
            // We know we have started a comment     
            comment_type = 2;
        }

        if (comment_type == 0) 
        {
           // Let us anticipate a comment first
            if (quote_type == 0 && c == '/')
            {

            } else 
            { 
                s[i] = c;
                ++i;
            }
        } else
        {
            (void) s;
        }

        if (comment_type == 2 && c == '/' && last_char == '*')
        {
            comment_type = 0;
        }
        
        last_char = c;
    }
    return i; 
}
