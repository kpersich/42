#include <stdio.h>

int ft_atoi(char *str);
int main()
{
	char str[] = "	 ----+---+ab567";

	ft_atoi(str);
	printf("%d", ft_atoi(str));
}
