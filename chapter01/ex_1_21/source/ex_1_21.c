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
#define INVALID_INDEX (-1)

int get_line(char line[], int maxline);
int next_tab_stop(int curr_index, int spaces_to_tabstop);

int main()
{
    int len = 0;    /* current line length */
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
    int first_blank = INVALID_INDEX;
    int last_blank  = INVALID_INDEX;
    int no_blanks_found = 0;
    int curr_index = 0;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (c == ' ')
        {
            // If c is a blank store this value for now
            if (first_blank == INVALID_INDEX) first_blank = i;
            //printf("First blank found @: %d\n", first_blank);
        } else
        {
            // This means we have found a non blank character
            if (first_blank != INVALID_INDEX)
            {
                // This means that the last character was a blank
                last_blank = i - 1;
                no_blanks_found = last_blank - first_blank + 1;
                // printf("No blanks found is: %d\n", no_blanks_found); 
                if (no_blanks_found == 1)
                {
                    s[first_blank] = ' ';
                    //printf("%c <---%d]0\n", s[first_blank], first_blank);
                } else
                {
                    // More than one blank was found
                    // First thing to do is to check where the next tab stop
                    // is and count the number of tabs until the next index
                    // Is greater or equal to the current index
                    int no_spaces = 0;
                    curr_index = first_blank; 
                    int next_ts;
                    // Just initialise the first tab stop to the first position
                    int last_tab_stop = curr_index; 
                    do
                    {
                        next_ts = next_tab_stop(last_tab_stop, TAB_STOP_LEN);
                        printf("first ts: %d\tnext tx: %d\n", last_tab_stop, next_ts);
                        printf("i is :%d\n", i);
                        if (next_ts > i) 
                        {
                            // This means that we need to find the number
                            // of spaces we need to the current i
                            no_spaces = i - last_tab_stop;
                            printf("No spaces found: %d\n", no_spaces);
                            while (no_spaces)
                            {   
                                s[curr_index++] = '*';
                                --no_spaces;
                            }
                        } else
                        {
                            // In this case we just write the tab to the array
                            no_spaces = next_ts - last_tab_stop;
                            printf("[t < i] .. spaces: %d\n", no_spaces);
                            if (no_spaces > 1) s[curr_index++] = '\\';
                            else
                                s[curr_index++] = '*';
                        }
                        last_tab_stop = next_ts;
                    } while (next_ts < i);

                    // Update i to be where the current character, c should be
                    i = curr_index; 
                }
                // Write the current current character to carry on to the next
                s[i] = c;
                //printf("%c <---%d]1\n", s[i], i);
                no_blanks_found = 0;
                first_blank = INVALID_INDEX;
            } else
            {
                // This means that this is just a character 
                // So we can just go ahead and write it
                s[i] = c;
               // printf("%c <---%d]2\n", s[i], i);
            }

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
