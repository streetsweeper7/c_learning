/*
* This program deletes each character in s1 that
* matches any character in s2
*/

#include <stdio.h>
// Let's assume that both s1 and s2 have the same maximimum
// length
#define MAX_LEN 40

typedef enum in_str
{
    NO,YES
} in_str_et;

void read_word(char s[]);
in_str_et in_str(char c, const char s[]);
void squeeze(char s1[], const char s2[]);

    
int main()
{
    char s1[MAX_LEN];
    char s2[MAX_LEN];	
    
    // Enter s1
    printf("Enter s1: ");
    read_word(s1);
    
    // Enter s2
    printf("Enter s2: ");
    read_word(s2);

    printf("s1: %s\ts2: %s\n", s1, s2);
    // Do the squeezing here
    squeeze(s1, s2);

    // Print out the resulting string
	printf("The resulting string is: %s\n", s1);
	
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
// This checks if a character c, appears in the string s
in_str_et in_str(char c, const char s[])
{
    in_str_et in_s = NO;
    int i;
    for (i = 0; s[i] != '\0' && in_s != YES; ++i)
    {
        if (s[i] == c) in_s = YES;
    }

    return in_s;
}

void squeeze(char s1[], const char s2[])
{

    int i, j;
    in_str_et in_s = NO;

    for (i = j = 0; s1[i] != '\0'; ++i)
    {
        in_s = in_str(s1[i], s2);
        
        if (in_s == NO)
        {
            s1[j++] = s1[i];
        }
    }
    
    s1[j] = '\0';

}
    
