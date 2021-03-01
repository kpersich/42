#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int get_next_line(int fd, char **line)
{
	int i;
	int k;
	int red;
	char buffer[1024*1024];

	if (!line)
		return (-1);
	i = 0;
	k = 0;
	while (i < (1024*1024))
	{
		buffer[i] = 0;
		i++;
	}
	while ((red = read(fd, &buffer[k], 1)) >= 0)
	{
		if (buffer[k] == '\n' || buffer[k] == '\0')
		{
			buffer[k] = 0;
			*line = malloc(ft_strlen(buffer) + 1);
			if (!(*line))
				return (-1);
			i = 0;
			while (i < k)
			{
				(*line)[i] = buffer[i];
				i++;
			}
			(*line)[i] = 0;
			return (red == 0 ? 0 : 1);
		}
		else
			k++;
	}
	return (-1);
}
