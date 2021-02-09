#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	//int i;
	//int k;
	char c[] = "ciao";
	//char j;
	int lon;
	int len;

	lon = ft_printf("mio: |%5.*s|\n", 2, c);
	len = printf("suo: |%5.*s|\n", 2, c);
	//j = 'j';
	//i = 12345;
	//k = 54321;
	//printf("|%.*s|\n", 2, c);
	//printf("suo: |%*s|\n", -5, c);
	//ft_printf("mio: |%*s|\n", -5, c);
	printf("%i\n%i\n", lon, len);
	
}