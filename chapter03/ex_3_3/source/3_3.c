/**
* This function expands shorthand notations like a-z in
* the string s1 into the equivalent list abc...xyz in s2.
* It allows for letters of either case and digits, and
* handles cases like a-b-c and a-z0-9. A trailing or
* leading - is taken literally.
*
* Author:   John Banda
* Date:     30 August 2025
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 1000

// Declare some functions
bool is_whitespace(char c);
void expand(char s1[], char s2[]);

int main()
{
    // Initialise the strings
    char s1[MAX_LEN];
    char s2[MAX_LEN];
    int c = 0;

    // Prompt the user to enter s1
    printf("Enter s1: ");

    // Initialise s1
    int i = 0;
    for(; (c = getchar()) != EOF && c != '\n'; i++)
    {
        s1[i] = c;
    }
    // Terminate the string
    s1[i] = '\0';


    // Expand s1 into s2
    expand(s1, s2);

    // Print out s2
    printf("Original: %s\nExpanded: %s\n", s1, s2);

    // Return pass
    return 0;

}

bool is_whitespace(char c)
{
    bool retval = false;
    switch (c)
    {
        case '\n':
        case '\t':
        case ' ':
            retval = true;
            break;
        default:
            retval = false;
            break;
    }
    return retval;
}

void expand(char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    
    while (s1[i] != '\0')
    {
        if ((s1[i] != '-' && s1[i] != '\0') &&
                (s1[i + 1] == '-') &&
                (s1[i + 2] != '-' && s1[i + 2] != '\0'))
        {
            // Expand the notation
            // First, assuming that s1[i + 2] < s1[i];
            for (char c = s1[i]; c <= s1[i + 2]; j++, c++)
            {
                s2[j] = c;
            } 
            // Increase i
            i += 3;
        } else
        {
            s2[j] = s1[i];
            j++, i++;
        }

    }
    // Close the string
    s2[j] = '\0';
}

