/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:18:03 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/25 16:18:05 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_new_strlen(const char *str)
{
	size_t len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

int		controllo_buffer2(char *buffer, char **line)
{
	int len;

	len = ft_strlen(&buffer[ft_new_strlen(buffer)]);
	*line = ft_strjoin(*line, ft_substr(buffer, 0, ft_new_strlen(buffer)));
	if (!line)
		return (-1);
	if (ft_new_strlen(buffer) < ft_strlen(buffer))
	{
		ft_strlcpy(buffer, &buffer[ft_new_strlen(buffer) + 1], len);
		return (1);
	}
	else
		ft_bzero(buffer, ft_strlen(buffer));
	return (0);
}

int		lettura(int *esito_o_fd, char *temp, char **line,
				char buffer[MAX_OPEN][BUFFER_SIZE + 1])
{
	int esito_interno;

	esito_interno = 0;
	while ((esito_o_fd[0] = read(esito_o_fd[1],
			buffer[esito_o_fd[1]], BUFFER_SIZE)) >= 0)
	{
		esito_interno = controllo_buffer2(buffer[esito_o_fd[1]], &temp);
		if (esito_interno != 0)
		{
			if (esito_interno == 1)
				*line = temp;
			return (esito_interno);
		}
		if (esito_o_fd[0] == 0)
		{
			esito_interno = controllo_buffer2(buffer[esito_o_fd[1]], &temp);
			*line = temp;
			return (esito_interno);
		}
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char buffer[MAX_OPEN][BUFFER_SIZE + 1];
	int			esito_o_fd[2];
	char		*temp;

	temp = 0;
	esito_o_fd[0] = 0;
	esito_o_fd[1] = fd;
	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	buffer[fd][BUFFER_SIZE] = 0;
	if (ft_strlen(buffer[fd]))
		esito_o_fd[0] = controllo_buffer2(buffer[fd], &temp);
	if (esito_o_fd[0] != 0)
	{
		if (esito_o_fd[0] == 1)
			*line = temp;
		return (esito_o_fd[0]);
	}
	return (lettura(esito_o_fd, temp, line, buffer));
}
