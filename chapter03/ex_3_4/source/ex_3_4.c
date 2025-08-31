/*
* This program deletes each character in s1 that
* matches any character in s2
*/

#include <stdio.h>
#define MAX_LEN 1000
#define abs(x) ((x) > 0 ? (x) : -(x))

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int x = -8;
    char s[MAX_LEN];    

    // Convert x to a string
    itoa(x, s);

    // Print s
    printf("%s\n", s);

	return 0;
}

/*
* itoa: convert n to characters in s 
*/
void itoa(int n, char s[])
{
    int i;
    
    int is_negative = (n < 0) ? 1 : 0;

    do
    {
        s[i++] = abs(n % 10) + '0'; /* get the next digit */
    } while ((n /= 10) != 0); /* delete it */


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
