/**
This converts degrees celcius to fahrenheit.
Author: John Banda
*/

#include <stdio.h>

int main()
{
	float fahr = 0.0, celcius = 0.0;
	const int upper_limit_c = 300, step = 20;

	// First print the header
	printf("%7s\t%10s\n", "Celcius", "Fahrenheit");
	
	while (celcius <= upper_limit_c)
	{
		fahr = (9.0 / 5.0) * (celcius + 32.0);
		
		// Print the table
		printf("%7.0f\t%10.1f\n", celcius, fahr);
		
		// Update the value of celcius
		celcius += step;
	}
	
	return 0;
}


