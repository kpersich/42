#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_next_line(char **line)
{
	char buffer[1048576];

	int red;
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < 1048576)
	{
		buffer[i] = 0;
		i++;
	}
	if (!line)
		return (-1);
	while ((red = read(0, &buffer[j], 1)) > 0)
	{
		if (buffer[j] == '\n')
		{
			buffer[j] = '\0';
			*line = malloc(1 + ft_strlen(buffer));
			i = 0;
			while (i < j)
			{
				(*line)[i] = buffer[i];
				i++;
			}
			(*line)[i] = 0;
			return (1);
		}
		else
			j++;
	}
	if (*buffer == '\0')
	{
		*line = malloc(1);
		(*line)[0] = 0;
	}
	else
	{
		*line = malloc(1 + ft_strlen(buffer));
		i = 0;
		while (buffer[i] != '\0')
		{
			(*line)[i] = buffer[i];
			i++;
		}
		(*line)[i] = 0;
	}
	return (0);
}
