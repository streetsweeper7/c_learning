/**
This converts degrees celcius to fahrenheit.
Author: John Banda
* This program converts a hexadecimal string to 
* its integer representation
* e.g: 0x20 = 32
*/

#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 6

// This function converts hexadecimal strigns to
// their integer values
int htoi(const char s[]);

int main()
{
    char s[MAX_LEN];
    int i, c;
    //< 1. The first step is to collect the strings, we'll assume
    //      that we'll place it in s;	
    printf("Please enter a hex value: ");
    for (i = 0; i < MAX_LEN - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    {
        s[i] = c;
    }

    s[MAX_LEN - 1] = '\0'; 
	
    // Convert the string to an integer value
    int result = htoi(s);

    printf("The converted value is: %d\n", result);
    
	return 0;
}

int htoi(const char s[])
{
    int i;
    // Check if the value starts with a 0x or a 0X
    if (s[0] == '0' && (tolower(s[1]) == 'x'))

    {
        i = 2;
    } else
    {
        i = 0;
    }

    int v;
    int n = 0;

    for (; s[i] != '\0'; ++i)
    {
        if ( isxdigit(s[i]) )
        {
            // This is a hexadecimal value so we need to convert
            if (isdigit(s[i]))
            {
                // This means this value is 0 to 9
                v = s[i] - '0';
            }
            else
            {
                // This means that this value is between a/A and f/F
                v = tolower(s[i]) - 'a' + 10;
            }
            
            n = n * 16 + v;
        } 
        else
        {
            n = 0;
            v = 0;
            break; 
        }
    }

    return n;
}
