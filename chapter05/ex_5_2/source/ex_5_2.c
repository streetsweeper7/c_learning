/*
* This program gets a number from the input
* Author: John Banda
* Date: 18 September 2025
*/

#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1000
#define BUFSIZE 1000

int getch(void);
void ungetch(int);
int getfloat(double *pn);

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int main()
{
    double val;

    // Read val from the input
    while (getfloat(&val) != EOF)
    {
        printf("Value: %g\n", val);
    }

    return 0;
}

/* getint: get next integer from input into *pn */
int getfloat(double *pn)
{
    int c, sign;

    while (isspace(c = getch()))    /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        
        char s = c;

        c = getch();
        // Check if c is a number
        if (!isdigit(c) && c != '.')
        {
            if (c != EOF) ungetch(c);

            ungetch(s);
           
            return 0; /* not a number */
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    double multiplier = 1;
    
    if (c == '.')
    {
        for (c = getch(); isdigit(c); c = getch())
        {
            *pn = 10 * *pn + (c - '0');
            multiplier *= 10;
        }
    }

    // get the decimal
    *pn /= (sign * multiplier);

    if (c != EOF)
        ungetch(c);

    return c;
}

int getch(void)     /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) 
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }else
    {
        buf[bufp++] = c;
    }
}
