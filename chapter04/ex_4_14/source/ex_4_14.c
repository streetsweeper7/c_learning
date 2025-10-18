/*
* Question:
* Recursive version of reverse 
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(t, x, y)   t temp;         \
                        temp = x;       \
                        x    = y;       \
                        y    = temp;    \

/* find all lines matching pattern */
int main()
{
    int a = 20; 
    int b = 40;
 
    printf("Original-->\ta: %d\tb: %d\n", a, b);

    swap(int, a, b);

    printf("Swapped-->\ta: %d\tb: %d\n", a, b);

    return 0;
}
