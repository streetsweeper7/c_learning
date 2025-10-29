#ifndef MY_LIB_H
#define MY_LIB_H

int get_line(char s[], int lim);
char *alloc(int n);  /* return pointer to n characters */
void afree(char *p); /* free storage pointed to by p */

#endif // my_lib
