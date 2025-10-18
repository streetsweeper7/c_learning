/*
* This program rewrites the for loop:
* for (i = 0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
*   s[i] = c;
* without using && or ||
*/

#include <stdio.h>
#define MAX_LINE 1000

int main()
{
    int i;
    int lim = MAX_LINE;
    char c;
    char s[MAX_LINE];
    for (i = 0; (i < lim - 1) * ((c = getchar()) != '\n') * (c != EOF); ++i)
    {
        s[i];
    }
	return 0;
}


