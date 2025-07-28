/*
* Author: John Banda
* Date  : 04/05/2025
* Description:
* This program verifies that getchar() != EOF is 0 or 1
*/
#include <stdio.h>

int main()
{
    int result = getchar() != EOF;
    
    if ( result > 1 || result < 0)
    {
        printf("FAIL\n");
    } else
    {
        printf("PASS\n");
    }
	
    return 0;
}


