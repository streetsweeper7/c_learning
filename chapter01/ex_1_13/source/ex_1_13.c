/*
* Author: John Banda
* Date  : 04/05/2025
* Description:
* This program prints a histogram of the length of words in its
* input
*/
#include <stdio.h>

// Let's assume that the user enters a max of 10 words
#define MAX_WORDS (10u)
int main()
{
    int character_count[MAX_WORDS];
    int c, index;
    
    // Initialise the index and the character array
    index = 0;
    int was_char = 0;

    while ((c = getchar()) != EOF && index < MAX_WORDS)
    {
        // If c is a white space just discard it
        if ( c == ' ' || c == '\t' || c == '\n')
        {
            // If we previously had a character, increase the index
            // in anticipation of another word
            if (was_char) ++index; 
            // Do nothing
            was_char = 0;
        } else
        {
            // This means that c is not a whitespace character
            ++character_count[index]; 
            was_char = 1;
        }

    } 

    // At the end of it all, print a histogram of the lengths of each word
    for (int i = 0; character_count[i] != 0; ++i)
    {
        
        int j = 0;

        while (j < character_count[i])
        {
            putchar('=');
            ++j;
        }
        // End the line
        putchar('\n'); 
    }
    return 0;
}
