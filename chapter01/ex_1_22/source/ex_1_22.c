/*
* Author: John Banda
* Date  : 14/05/2025
* Description:
* This program folds lines greater than LINE_LEN
*/
#include <stdio.h>

#define MAXLINE     (1000)      /* Maximum input line length */
#define LINE_LEN       (3)      /* This is the number of characters to the next
                                    tab stop */
int get_line(char line[], int maxline);
int is_blank(char c);           // Checks if a character is a blank

int main()
{
    int len = 0;    /* current line length */
    char line[MAXLINE]; /* current input line */

    len = get_line(line, MAXLINE);
    if (len > 0)
    {
        putchar('\n');
        printf("%s\n", line);
    }

    return 0;

}

/* get_line:    Read a line into s, return length */
int get_line(char s[], int lim)
{
    int c = 0, i;
    int curr_len = 0;
    int pos_last_non_blank = -1;
    for (i = 0; ((c = getchar()) != EOF) && i < (lim - 1) ; ++i)
    {
        if (is_blank(c) && pos_last_non_blank == -1)
        {
            // Discard all blank characters before the first non-blank character
            --i;
        } 
        // Discard all beginning
        else if (curr_len < LINE_LEN)
        {
            // If the length of the current line is within bounds
            // add the current char to the buffer
            s[i] = c;
            ++curr_len;             // Increase the char count of the current line
            if (!is_blank(c))
            {
                pos_last_non_blank = i; // Track the pos of the last non-blank
            }
        }
        else if (curr_len == LINE_LEN)
        {
            // First if discards line after the last non-blank
            if (is_blank(c)) --i;
            else
            {
                // Change the value of the last i to discard trailing
                // blanks after the non blank character
                i = pos_last_non_blank + 1;
                    
                // Add a new line character to split the lines
                s[i++] = '\n';
                s[i] = c;

                // Reset the line of the new line after adding the first char
                curr_len = 1;
            }
        }
    }
    // Lastly, add the important line stop to the entered line
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

int is_blank(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}
