#include <stdio.h>

int main()
{
	float fahr = 0.0, celcius = 0.0;
	const int upper_limit_c = 300, step = 20;

	// First print the header
	printf("%10s\t%7s\n", "Fahrenheit", "Celcius");
	
	while (fahr <= upper_limit_c)
	{
		celcius = (5.0 / 9.0) * (fahr - 32.0);
		
		// Print the table
		printf("%10.0f\t%7.1f\n", fahr, celcius);
		
		// Update the value of fahr
		fahr += step;
	}
	
	return 0;
}


