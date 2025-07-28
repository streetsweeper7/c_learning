/*
* Author: John Banda
* Date  : 04/05/2025
* Description:
* This program prints a histogram of the frequency of particular characters
* from the input stream. Particularly from '!' - 1 to '~' as characters within
* this range can be easily entered using the keyboard
*/
#include <stdio.h>

// Ascii has a total of 256 characters. But we won't use all of them in this
// program
#define MAX_CHARACTERS (256)
int main()
{
    int character_count[MAX_CHARACTERS];
    int c;
   
    // Initialise the array
    for (int k = 0; k < MAX_CHARACTERS; ++k)
    {
        character_count[k] = 0;
    } 

    while ((c = getchar()) != EOF)
    {
        ++character_count[c];
    } 

    // At the end of it all, print a histogram of the frequencies of each character 
    for (int i = '!' - 1; i <= '~'; ++i)
    {
        
        // First display the character
        printf("\t%c |", i); 
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
