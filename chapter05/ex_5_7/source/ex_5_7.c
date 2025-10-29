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
#include "my_lib.h"

#define MAXLINES (5000)
#define BUFSIZE  (5000)

char *lineptr[MAXLINES];

void mqsort(char *v[], int left, int right);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
int readlines_v2(char *lineptr[], int maxlines, char *buffer);

/* sort input lines */
int main()
{
    int nlines;     /* number of input lines read */

    /* Assuming that we can store
     up to BUFSIZE chars, 
     if a line is made up of 50 chars
     Then this is 50 lines. */
    char buffer[BUFSIZE];

    if ((nlines = readlines_v2(lineptr, MAXLINES, buffer)) >= 0)
    {
        mqsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }

}

#define MAXLEN (1000) /* max length of any input line */

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return - 1;
        else
        {
            line[len - 1] = '\0';   /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}


/* readlines: read input lines */
int readlines_v2(char *lineptr[], int maxlines, char *buffer)
{
    int len, nlines;
    char line[MAXLEN];
    char *buffer_top = buffer;

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (buffer_top + len >= buffer + BUFSIZE))
            return - 1;
        else
        {
            line[len - 1] = '\0';   /* delete newline */
            strcpy(buffer_top, line);
            lineptr[nlines++] = buffer_top;
            buffer_top += len;
        }

    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);

    return;
}

/* qsort: sort v[left]...v[right] into increasing order */
void mqsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *[], int i, int j);

    if (left >= right)  /* do nothing if array contains fewer */
       return;          /* than two elements */

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    mqsort(v, left, last - 1);
    mqsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

