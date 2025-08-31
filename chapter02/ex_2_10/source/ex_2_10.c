/*
* Author: John Banda
* Date  : 06/08/2025
* Description:
* This program converts upper case characters to lower case 
*/
#include <stdio.h>

unsigned char lower(unsigned char upper);

int main()
{
    // Let's loop around all the characters of the alphabet and print out their
    // lowercase versions
    // Print out the header here
    printf("Upper\tLower\n");
    printf("---------------\n");
    for (unsigned char c = 'A'; c <= 'Z'; c++)
    {
        printf("%c\t%c\n", c, lower(c));
    }
        
    return 0;

}

unsigned char lower(unsigned char upper)
{
    // We need to check if the passed character is between 'A' and 'Z'
    unsigned char low = (upper >= 'A' && upper <= 'Z') ? 'a' + upper - 'A' : upper;
    return low;
}
