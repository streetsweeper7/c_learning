/*
* Author: John Banda
* Date  : 04/05/2025
* Description:
* This program copies its input to its output, replacing each tab
* with \t, backspace by \b, and each backslash by \\
*/
#include <stdio.h>

int main()
{
    int c;
    int was_word = 0; 
    while ( (c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\n' && c != '\t')
        {
            was_word = 1;
            putchar(c);
        } else
        {
            // This is a word defining character
            if (was_word)
            {
                putchar('\n'); 
                was_word = 0;
            }
        } 
    }
    
    return 0;
}


