/*
 * Versions of the library functions strncpy, strncat,
 * and strcmp which operate on at most the first n
 * characters of their argument strings.
 *
 * Author: John Banda
 * Date: 27 September 2025
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE (1000) /* Maximum input line length */

int get_line(char *s, size_t lim);
int patoi(char *s);
void pitoa(int n, char *s);
void reverse(char *s);
int strindex(char *s, char *t);

/* Print the longest input line */
int main()
{
    int len;    /* current line length */
    char line[MAXLINE]; /* current input line */

    // 1. Read a line 12345 from the input
    len = get_line(line, MAXLINE);
    printf("%d:\t%s\n", len, line);

    // 2. Convert s to an integer where s = '12345'
    char *s = "12345";
    int val = patoi(s);  
    printf("%s\t%d\n", s, val);

    // 3. Reverse the string "12345"
    char rev_s[] = "12345";
    reverse(rev_s);
    printf("%s\t%s\n", s, rev_s);

    // 4. Change the value -12345 to a string
    val = -12345;
    char val_str[MAXLINE];
    pitoa(val, val_str);
    printf("%d\t%s\n", val, val_str);

    // 5. Find the index of cat in vacation 
    // value returned should be 2
    char *t = "cat";
    char *sw = "vacation";
    int idx = strindex(sw, t);
    printf("%s\t%s\t%d\n", sw, t, idx);

    return 0;

}

/* get_line: Read a line into s, return length */
int get_line(char *s, size_t buf_size)
{
    if (buf_size == 0) return 0;

    char *s_start = s;
    size_t n_chars = buf_size - 1;  // Only read this number of
                                    // chars. Leave room for the
                                    // null termination

    int c = 0;
    while (n_chars && (c = getchar()) != EOF && c != '\n')
    {
        n_chars--;
        *s++ = c;
    }

    // The while loop above will not allow us to read more
    // than buf_size - 1 characters. So there's enough room for
    // a null termination and a new line if any
    if (c == '\n') *s++ = c;

    // There's still enough room for the null termination 
    // char
    *s = '\0';
   
    // Return the length of the string
    return s - s_start;
}

/* atoi: convert s to integer */
int patoi(char *s)
{
    int n = 0;

    while (*s >= '0' && *s <= '9')
    {
        n = 10 * n + (*s - '0');
        s++;
    }

    return n;
}
/*
* itoa: convert n to characters in s 
*/
void pitoa(int n, char *s)
{
    
    char *s_start = s;
    int is_negative = (n < 0) ? 1 : 0;

    do 
    {
        *s++ = abs(n % 10) + '0';   /* get the next digit */
    } while ((n /= 10) != 0);       /* delete it */

    if (is_negative)
    {
        *s++ = '-';
    }

    *s = '\0';

    reverse(s_start);

}

/* reverse: reverse string s */
void reverse(char *s)
{
    char *s_start = s;

    while (*s != '\0') s++;
        
    --s;                    // Back off from '\0'
    
    // Leave newline in place
    if (*s == '\n')
        --s;

    // Swap the values
    char temp;
    while (s_start < s)
    {
        temp = *s_start;
        *s_start++ = *s; // Swap the characters
        *s-- = temp;
    }
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{

    char *s_start = s;
    char *t_start = t;

    for (; *s != '\0'; s++)
    {
        for (t = t_start; *t != '\0' && *s++ == *t++; )
            ;
        if (t > t_start && *t == '\0')
            // The index is the value of s minus the 
            // length of t
            return s - s_start - (t - t_start);
    }
    return -1;
}
