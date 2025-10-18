/*
* Question:
* Recursive version of reverse 
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000 /* maximum string length */

void reverse(char s[]);
void reverse_r(char s[], int i, int len);

/* find all lines matching pattern */
int main()
{
    char s[] = "frog";
    
    reverse(s);

    printf("%s\n", s);

    return 0;
}

/* This is a recursive version of reverse
* which reverses string, in place
*/
void reverse(char s[])
{
    int len = strlen(s);

    // Reverse it in place
    reverse_r(s, 0, len);
    
    return;

}

void reverse_r(char s[], int i, int len)
{
    if (i >= (len - 1))
        return;
    else
    {
        char temp = s[i];
        
        // Reverse the characters 
        s[i] = s[len - 1];
        s[len - 1] = temp;
    
        reverse_r(s, ++i, --len);
    }
}
