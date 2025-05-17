/*
* Author: John Banda
* Date  : 14/05/2025
* Description:
* This program reverses the character string s, which has been
* passed as input.
*/
#include <stdio.h>

#define MAXLINE (1000) /* Maximum input line length */

int get_line(char line[], int maxline);
void reverse(char line[], int len);

int main()
{
    int len;    /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        // Reverse the line
        reverse(line, len);
        printf("%s", line);
    }
    return 0;

}

/* get_line:    Read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

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

// Reverse a line
void reverse(char s[], int len)
{
    // If the length is zero, do nothing
    if (!len) return;

    char c;
    
    // Calculate the length of the string
    // Remove the newline from the line before reversing it
    int size = len;
    if (s[len - 1] == '\n')
    {
        --size;
    }
     
    for (int i = 0; i < size / 2; i++)
    {
        c = s[i];
        s[i] = s[size - i - 1];
        s[size - i - 1] = c;
    }
}
