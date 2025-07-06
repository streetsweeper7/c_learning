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
    
    while ( (c = getchar()) != EOF)
    {
    
        if (c == '\t')
        {
            printf("\\t");
        } 
        else if (c == '\b')
        {
            printf("\\b");
        }
        else if (c == '\\')
        {
            printf("\\\\");
        }
        
    }
    
    return 0;
}


