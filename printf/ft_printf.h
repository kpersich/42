/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <kpersich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:12:20 by kpersich          #+#    #+#             */
/*   Updated: 2021/02/11 19:33:46 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define MIN(x, y) x > y ? y : x
# define MAX(x, y) x > y ? x : y
# define ABS(x) x < 0 ? -x : x

typedef struct	s_option
{
	int		zero;
	int		minus;
	int		width;
	int		precision;
	char	type;
}				t_option;

int				ft_strlen(const char *s);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
void			ft_putstr_fd(char *s, int fd);
char			*ft_litoa(long int n);
char			*ft_uitoa(unsigned int n);
void			filling(char fill, int size, int *len);
int				parse_flag(const char *format, t_option *option);
int				parse_width(const char *format, va_list arg, t_option *option);
int				parse_precision(const char *format, va_list arg,
				t_option *option);
int				parse_type(const char *format, t_option *option);
void			process_option(int *len, va_list arg, t_option *option);
void			process_char(int *len, va_list arg, t_option *option);
void			process_string(int *len, va_list arg, t_option *option);
void			process_decimal(int *len, va_list arg, t_option *option);
void			process_un_decimal(int *len, va_list arg, t_option *option);
int				ft_printf(const char *format, ...);

#endif