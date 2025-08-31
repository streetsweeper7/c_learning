/*
* This program rewrites the for loop:
* for (i = 0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
*   s[i] = c;
* without using && or ||
*/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000

void escape(char s[], char t[]);
void descape(char s[], char t[]);

int main()
{
    char from[MAX_LEN];
    char to[MAX_LEN];
    char to_2[MAX_LEN];

    // Let's initialise to, to something
    strcpy(from, "What\tis\tyour\tname?\nMy name is John.\0");

    printf("Original:\n%s\n", from);

    // Let's do the copying
    escape(to, from);

    // Let's print out to, to see what the value is
    printf("%s\n", to);

    // Let's use descape to change it back
    descape(to_2, to);
    printf("%s\n", to_2);

	return 0;
}

void escape(char s[], char t[])
{
    int i = 0;
    int i_temp = 0;
    int c = 'z'; // Arbitral initialisation of c;

    // Copy the string t to s
    while (c != '\0')
    {
        c = t[i];
        switch (c)
        {
            case '\n':
                s[i_temp] = '\\';
                i_temp++;
                s[i_temp] = 'n';
                break;
            case '\t':
                s[i_temp] = '\\';
                i_temp++;
                s[i_temp] = 't';
                break;
            default:
                s[i_temp] = t[i];
                break;
        }
        i++;
        i_temp++;
        
    }
}

void descape(char s[], char t[])
{
    int i = 0;
    int i_temp = 0;
    int c = 'z'; // Arbitral initialisation of c

    // Copy the string t to s
    while (c != '\0')
    {
        c = t[i];
        switch (c)
        {
            case '\\':
                // Check the next character
                if (t[i + 1] == 'n')
                {
                    s[i_temp] = '\n';
                    i++;
                } else if (t[i + 1] == 't')
                {
                    s[i_temp] = '\t';
                    i++;
                } else
                {
                    s[i_temp] = '\\';
                }
                break;

            default:
                s[i_temp] = t[i];
                break;
        }

        i++;
        i_temp++;
    }
}
