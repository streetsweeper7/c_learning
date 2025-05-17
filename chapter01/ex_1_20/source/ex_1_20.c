/*
* Author: John Banda
* Date  : 14/05/2025
* Description:
* This program replaces tabs in the input with the proper number of blanks
* to space to the next tab stop. There's a maximum number of tab stops
* based on tha maximum size of the input 
* passed as input.
*/
#include <stdio.h>

#define MAXLINE (1000) /* Maximum input line length */
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
    }
    return 0;

}

/* get_line:    Read a line into s, return length */
int get_line(char s[], int lim)
{
    int c = 0, i;
    int next_ts; // Index to the next tab stop

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (c != '\t')
        {
            s[i] = c;
        }
        else
        {
            // Find the next stop
            next_ts = next_tab_stop(i, TAB_STOP_LEN);
            next_ts = next_ts > lim - 1 ? lim - 1 : next_ts;

            while (i < next_ts)
            {
                s[i++] = ' ';
            }
            i--;
        }
    }

    if (c == '\n')
    {
        if (i < lim - 1)
        {
            s[i] = c;
        }
        ++i;
    }

    if (i < lim) 
    {
        s[i] = '\0';
    }
    else
    {
        s[lim - 1] = '\0';
    }
   
    return i; 
}

// next tab stop
int next_tab_stop(int curr_index, int spaces_to_tabstop)
{
    int i = 0;
    i = spaces_to_tabstop - (curr_index % spaces_to_tabstop) + curr_index; 

    return i;
}
