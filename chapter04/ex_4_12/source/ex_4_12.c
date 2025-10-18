/*
* Question: Adapt the idea of printd to write a recursive
* version of itoa; that is, convert an integer into a string
* by calling a recursive routine
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLINE 1000 /* maximum string length */


void itoa_r(int num, char s[]);

/* find all lines matching pattern */
int main()
{
    char s[MAXLINE];
    
    // Convert the integer to a string
    int val = 123456;
    
    itoa_r(val, s);

    printf("%s\n", s);

    return 0;
}


/* This is a recursive version of itoa 
* char s[] is where the string will be stored */
void itoa_r(int num, char s[])
{
    // Before anything let's come up with a plan

    static int index = 0;

    // Do static indices persist in recursion??

    if (num / 10)
    {
        // This means this is the biggest unit
        itoa_r(num / 10, s);
    }  
    else
    {
        if (num < 0)
        {
            s[index++] = '-';
        }
    }
    
    s[index++] = '0' + (abs(num) % 10); 
    
    // Add '\0' to the string
    s[index]   = '\0';
}

