/*
* This program determines the ranges of 
* the following types: char, short, int, and long -
* for both their signed and unsigned variants.
* The ranges are determined by direct computation
* and also by using the values from standard headers.
* This program also determines the ranges for the 
* floating types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

#define UINT unsigned int
#define ULONG unsigned long
#define USHRT unsigned short
#define UCHAR unsigned char

#define HEADER() printf("\n"); \
        printf("%6s\t%20s\t%20s\t%20s\n", "Type", "Signed Min", "Signed Max", "Unsigned Max"); \
        printf("-----------------------------------------------------------------------------\n");

void print_dc_char_limits();
void print_dc_short_limits(); 
void print_dc_int_limits();
void print_dc_long_limits();

int main()
{
	
    // Using values defined in the headers
    printf("1.Using Limits.h\n");
    HEADER(); 
    // Char
    printf("%6s\t%20d\t%20d\t%20u\n", "char", SCHAR_MIN, SCHAR_MAX, UCHAR_MAX);
    // short
    printf("%6s\t%20d\t%20d\t%20u\n", "short", SHRT_MIN, SHRT_MAX, USHRT_MAX);
    // int
    printf("%6s\t%20d\t%20d\t%20u\n", "int", INT_MIN, INT_MAX, UINT_MAX);
    // long
    printf("%6s\t%20ld\t%20ld\t%20lu\n", "long", LONG_MIN, LONG_MAX, ULONG_MAX);
    
    printf("\n"); 
    printf("2.Using Direct Computation\n");
    HEADER(); 
    print_dc_char_limits();
    print_dc_short_limits(); 
    print_dc_int_limits();
    print_dc_long_limits();
	
    printf("\n"); 
    printf("3.Floats\n");
    printf("-----------------------------------------------------------------------------\n");

    printf("%6s\t%15e\n", "FLT_MIN", FLT_MIN);
    printf("%6s\t%15e\n", "FLT_MAX", FLT_MAX);
    printf("%6s\t%15e\n", "FLT_EPS", FLT_EPSILON);

    return 0;

}

void print_dc_char_limits()
{
    char schar_min = ~(((UCHAR) ~0) >> 1);
    char schar_max = (((UCHAR) ~0) >> 1);
    UCHAR uchar_max = ~0;

    printf("%6s\t%20d\t%20d\t%20u\n", "char", schar_min, schar_max, uchar_max);
}

void print_dc_short_limits()
{
    short shrt_min = ~(((USHRT) ~0) >> 1); 
    short shrt_max = (((USHRT) ~0) >> 1);
    UCHAR ushrt_max = ~0;

    printf("%6s\t%20d\t%20d\t%20u\n", "short", shrt_min, shrt_max, ushrt_max);
}

void print_dc_int_limits()
{
    int int_min = ~(((UINT) ~0) >> 1);
    int int_max = (((UINT) ~0) >> 1);
    UINT uint_max = ~0;

    printf("%6s\t%20d\t%20d\t%20u\n", "int", int_min, int_max, uint_max);
}

void print_dc_long_limits()
{
    long long_min = ~(((ULONG) ~0) >> 1);
    long long_max = (((ULONG) ~0) >> 1);
    ULONG ulong_max = ~0;

    printf("%6s\t%20ld\t%20ld\t%20lu\n", "long", long_min, long_max, ulong_max);
}
