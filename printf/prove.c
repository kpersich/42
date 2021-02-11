#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	int i;
	int mio;
	int suo;

	i = -12345;
	mio = ft_printf("mio: |%9.8d|\n", i);
	suo = printf("suo: |%9.8d|\n", i);
	printf("mia:%d\nsua:%d\n", mio, suo);
	
}
