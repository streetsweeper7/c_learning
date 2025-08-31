/*
* Author: John Banda
* Date  : 30/08/2025
* Description:
* This program prints the total number of 1 bits in an integer 
*/
#include <stdio.h>

#define MAX_LEN (1000)

void itoa(int n, char s[], int min_width);
void reverse(char s[]);

int main()
{
    int x = -25;
    char s[MAX_LEN];

    // convert x to string, with padding
    itoa(x, s, 10); 

    // print s
    printf("%s\n", s);
    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int min_width)
{
    int i, sign;

    if ((sign = n) < 0)     /* record sign */
        n = -n;             /* make n positive */
    i = 0;


    do                          /* generate digits in reverse order */
    {
        s[i++] = n % 10 + '0';  /* get next digit */

    } while ((n /= 10) > 0);    /* delete it      */

    if (sign < 0)
        s[i++] = '-';

    if (i < (min_width - 1))
    {
        for (; i < min_width; i++)
        {
            s[i] = ' ';
        }
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
