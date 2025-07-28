/*
* Author: John Banda
* Date  : 04/05/2025
* Description:
* This program copies its input to its output, replacing each string
* of one or more blanks by a single blank.
*/
#include <stdio.h>

int main()
{
    int c;
    int add_space = 0;
    
    while ( (c = getchar()) != EOF)
    {
    
        if (c == ' ' || c == '\n' || c == '\t')
        {
            add_space = 1;
        } 
        else 
        {
            if (add_space) putchar(' ');
            printf("%c", c); 
            add_space = 0;
        }
        
    }
    
    return 0;
}


