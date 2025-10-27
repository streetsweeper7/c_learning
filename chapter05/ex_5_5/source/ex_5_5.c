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

#define MAX_LEN (1000)

char *pstrcpy(char *s, const char *t, size_t n);
char *pstrncat(char *s, const char *t, size_t n);
int pstrncmp(const char *cs, const char *ct, size_t n);
int strend(char *s, char *t);

int main()
{

    // Let's test out a few scenarios
    char dest[MAX_LEN];

    /* Test pstrcpy */
    char *t = "Banda";
    size_t len = 3;
    printf("%zu\t%s\t%s\n", len, t, pstrcpy(dest, t, len));

    len = 6;
    printf("%zu\t%s\t%s\n", len, t, pstrcpy(dest, t, len));
    
    /* Test pstrncat */
    // At this point dest should contain Banda
    char *str = "John";
    printf("%d\t%s\t%s\t\n", 5, dest, pstrncat(dest, str, len));

    /* Test strncmp */
    char *str1 = "John";
    char *str2 = "Banda";
    char *str3 = "John";
    len = 4;
    printf("%d:\t%s\t%s\n", pstrncmp(str1, str2, len), str1, str2);
    printf("%d:\t%s\t%s\n", pstrncmp(str1, str3, len), str1, str3);


    return 0;
}

/* strncpy: Copy at most n characters of string ct to
 * s. Pad with '\0's if ct has fewer than n characters */
char *pstrcpy(char *s, const char *t, size_t n)
{
    
    // Copy all the characters from t into s
    while (n && *t)
    {
        *s++ = *t++;
        n--;
    }

    // if t_len is less than n, then we need
    // to pad with '\0'
    while (n--)
        *s++ = '\0';

    // We need to return the beginning of s
    return s - n;
}

/* strncat: Concatenate at most n characters of string
 * t to string s. Terminate s with '\0'; return s */
char *pstrncat(char *s, const char *t, size_t n)
{
    // Check for null values
    if (s == NULL || t == NULL) return NULL;

    char *s_start = s;

    // First find the end of 
    while (*s) s++;

    // Copy n characters from t to s
    // Beware that n might be greater then len(t)
    while (n-- && (*s++ = *t++))
        ;

    // Ensure that s is terminated with a '\0'
    *s = '\0';

    return s_start;
}

/* strncmp: compare at most n characters of string cs to string ct
 * return < 0 if cs < ct, 0 if cs == ct, >0 if cs > ct */
int pstrncmp(const char *cs, const char *ct, size_t n)
{
    while (n-- && (*cs == *ct))
    {
        if (*cs == '\0')
            return 0;

        cs++, ct++;
    }

    // If we get to this point then the strings are not equal
    return *cs - *ct;
}
