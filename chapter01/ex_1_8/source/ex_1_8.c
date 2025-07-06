/*
* Author: John Banda
* Date  : 04/05/2025
* Description:
* This program counts the number of blanks, tabs, and newlines
*/
#include <stdio.h>

int main()
{
    long blanks = 0, tabs = 0, newlines = 0;
    int c;
    
    while ( (c = getchar()) != EOF)
    {
        if (c == ' ') ++blanks;
        else if (c == '\t') ++tabs;
        else if (c == '\n') ++newlines;
        else
        {
            ;
        }
    }
    
    // Display the characters counted
    printf("Character count summary\n");
    printf("=======================\n");
    printf("Blanks:%ld\n", blanks);   
    printf("Tabs: %ld\n", tabs);
    printf("Newlines: %ld\n", newlines);

    return 0;
}


