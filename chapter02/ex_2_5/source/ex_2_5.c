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
#define MAX_LEN 20

int any(const char s1[], const char s2[]);
int find(char c, const char s[]);
void read_word(char s[]);

int main()
{
    
    char s1[MAX_LEN];	
    char s2[MAX_LEN];
   
    printf("Enter s1: ");
    read_word(s1);

    printf("Enter s2: ");
    read_word(s2);
    
    printf("The first location is: %d\n", any(s1, s2)); 
    return 0;
}

void read_word(char s[])
{
    int i, c;
    for (i = 0; i < MAX_LEN - 1 && (c = getchar()) != '\n'; ++i)
    {
        s[i] = c;
    }

    s[i] = '\0';

}

int any(const char s1[], const char s2[])
{

    int lowest_index = -1;
    int i            = 0;

    while (s2[i] != '\0')
    {
    
        lowest_index = find(s2[i], s1);
        if (lowest_index > -1) break;

        ++i;
    }
    
    return lowest_index;
}

int find(char c, const char s[])
{
    int char_pos = -1;
    int i        = 0;

    while (s[i] != '\0')
    {
        if (c == s[i])
        {
            char_pos = i;
            break;
        }
        ++i;
    }
    return char_pos;
}
