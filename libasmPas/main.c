/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:46:50 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 20:21:32 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	pd(char *empty, char *str1, char *str2, char *ok)
{	
	char	empty1[50];
	char	empty2[50];

	printf("\n\n-------------------TEST FT_STRLEN--------------------------\n\n");
	printf("  real: %lu\nlibasm: %lu\n", strlen(str1), ft_strlen(str1));
	printf("  real: %lu\nlibasm: %lu\n", strlen(ok), ft_strlen(ok));
	printf("\n\n-------------------TEST FT_STRCPY--------------------------\n\n");
	printf("  real: %s\nlibasm: %s\n", \
		strcpy(empty1, str1), ft_strcpy(empty2, str1));
	printf("\n\n-------------------TEST FT_WRITE--------------------------\n\n");
	printf("real return: %zi\n", write(1, str2, ft_strlen(str2)));
	printf("libasm return: %zi\n", ft_write(1, str2, ft_strlen(str2)));
	printf("\n");
	printf("Real Error:%zi, %s\n", write(-7, str2, 7), strerror(errno));
	printf("Libasm Error:%zi, %s\n", ft_write(-7, str2, 7), strerror(errno));
	printf("\n\n-------------------TEST FT_STRDUP--------------------------\n\n");
	printf("  real: %s\nlibasm: %s\n", strdup(str1), ft_strdup(str1));
	printf("  real: %s\nlibasm: %s\n", strdup(empty), ft_strdup(empty));
	printf("  real: %s\nlibasm: %s\n", strdup(ok), ft_strdup(ok));
}

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*empty;
	char	*ok;
	char	*buffer1;
	char	*buffer2;
	int		fd;

	str1 = "stringaaaaaa...\n";
	str2 = "PANINOALSALMONE\n";
	empty = "";
	ok = "aifguhapdfghiuapinvapidfvadfpvbnnapdfhuvpaibv\n";
	printf("\n\n-------------------TEST FT_STRCMP--------------------------\n\n");
	printf("real: %i\nlibasm: %d\n", strcmp(str1, str2), ft_strcmp(str1, str2));
	printf("real: %i\nlibasm: %d\n", strcmp(empty, str1), ft_strcmp(empty, str1));
	printf("\n\n-------------------TEST FT_READ--------------------------\n\n");
	buffer1 = calloc (500, sizeof(char));
	buffer2 = calloc (500, sizeof(char));
	fd = open("test.c", O_RDONLY);
	printf("real return: %zi, %s\n", read(fd, buffer1, 5), buffer1);
	fd = open("test.c", O_RDONLY);
	printf("libasm return: %zi, %s\n\n", ft_read(fd, buffer2, 5), buffer2);
	pd(empty, str1, str2, ok);
	return (0);
}
