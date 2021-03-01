#include <unistd.h>
#include <stdio.h>

int main (int argc, char **argv)
{
	int i;
	int k;
	char used[255];

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
		{
			used[i] = 0;
			i++;
		}
		i = 1;
		while (i < 3)
		{
			k = 0;
			while (argv[i][k])
			{
				if (!used[(unsigned char)argv[i][k]])
				{
					used[(unsigned char)argv[i][k]] = 1;
					write(1, &argv[i][k], 1);
				}
				k++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
