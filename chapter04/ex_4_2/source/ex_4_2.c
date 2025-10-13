/*
* This program converts a string to a double
* Author: John Banda
* Date: 08 September 2025
*/

#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1000

double atof(char s[]);

int main()
{
    double val = 0;
    char line[MAX_LEN];
    int get_line(char line[], int max);

    while (get_line(line, MAX_LEN) > 0)
    {
        // Convert line to double
        val = atof(line);
        printf("Value: %f\n", val);
    }

    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power, retval;
    int i, sign, exp_sign, exponent;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    retval = sign * val / power;

    // check if it has an exponent, assume that the user does
    // a good job to put the value in a correct format
    if (s[i] == 'e' || s[i] == 'E')
    {
        // first increment i
        i++;

        // Check if the next value is the exponent power
        exp_sign = (s[i] == '-' ? -1 : 1);

        if (s[i] == '-' || s[i] == '+')
            i++;

        // Get all the digits after the exponent
        for (exponent = 0; isdigit(s[i]); i++)
            exponent = 10 * exponent + (s[i] - '0');

        // Now that we have the exponent
        if (exp_sign < 0)
        {
            while (exponent-- > 0)
                retval /= 10;
        } else
        {
            while (exponent-- > 0)
                retval *= 10;
        }
    }

    // We now calculate the full value
    return retval;
}


/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
