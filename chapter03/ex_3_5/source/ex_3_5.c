/*
* Author: John Banda
* Date  : 28/07/2025
* Description:
* 
* Problem:
* Write the function any(s1, s2), which returns the first
* location in a string s1 where any character from the string
* s1 occurs, or -1 if s1 contains no characters from s2.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

// Declare some functions
char itoc(int n);
void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    
    int x = -20;
    char s[MAX_LEN];
   
    // convert x to a string representation
    itob(x, s, 16);

    // print s
    printf("%s\n", s);

    return 0;
}

/* itoc: convert int to char representation */
char itoc(int n)
{
    return (n > 9) ? 'a' + n - 10 : n + '0';
}

void itob(int n, char s[], int b)
{
    int i = 0;
    
    int is_negative = (n < 0) ? 1 : 0;

    do
    {
        s[i++] = itoc(abs(n % b));  /* get the next digit */
    } while ((n /= b) != 0);        /* delete it */


    if (is_negative)
    {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);

}

/* reverse: reverse string s */
void reverse(char s[])
{
    int i, j;
    char temp;

    i = 0;
    while (s[i] != '\0')    // Find the end of string s
        ++i;
    --i;                    // Back off from '\0'

    if (s[i] == '\n')
        --i;                // Leave newline in place
    j = 0;                  // Beginning of new string s

    while (j < i)
    {
        temp = s[j];
        s[j] = s[i];        // Swap the characters
        s[i] = temp;
        --i, ++j;
    }
}
