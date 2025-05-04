#include <stdio.h>

int main()
{
	// First print the header
	printf("%7s\t%10s\n", "Celcius", "Fahrenheit");
	
   // Loop through the celcius values 
    for (int celcius = 300; celcius >= 0; celcius -= 20)
    {
        printf("%7d\t%10.1f\n", celcius, (9.0 / 5.0) * celcius + 32.0 );
    }	
	return 0;
}


