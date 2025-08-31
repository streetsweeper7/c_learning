/*
* Author: John Banda
* Date  : 04/05/2025
* Description:
* This program prints the total number of 1 bits in an integer 
*/
#include <stdio.h>

unsigned bitcount(unsigned x);

int main()
{
    unsigned i = 0xF3;
    
    printf("The number of 1 bits in %d is " "%d\n", i, bitcount(i));
    return 0;
}

unsigned bitcount(unsigned x)
{
    unsigned i = 0;
    for (; x != 0; x &= (x - 1))
    {
        i++;
    }

    return i;
}


