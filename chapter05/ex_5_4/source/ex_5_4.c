/*
* This program checks if a string, t, occurs at the end
* of the string s.
* Author: John Banda
* Date: 25 September 2025
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int strend(char *s, char *t);

int main()
{

    // Let's test out a few scenarios
    
    // 1. 
    char *s = "John";
    char *t = "Banda";
    printf("%s\t%s\t:%d\n", s, t, strend(s, t));

    t = "ohn";
    printf("%s\t%s\t:%d\n", s, t, strend(s, t));

    t = "ohnz";
    printf("%s\t%s\t:%d\n", s, t, strend(s, t));

    t = "ohnzohn";
    printf("%s\t%s\t:%d\n", s, t, strend(s, t));
    return 0;
}

/* strend: returns 1 if string t occurs at the end
 * of the string s, and zero otherwise */

int strend(char *s, char *t)
{
    // Let's store the initial value of t
    char *t_start = t;

    // Lets walk to the ends of  s and t
    while (*s) s++;
    while (*t) t++;

    // Now that both s and t are at the tails 
    do
    {
        s--, t--;

        if (*s != *t) return 0;

    } while ( t != t_start);

    return 1;

} 
