/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <kpersich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:12:20 by kpersich          #+#    #+#             */
/*   Updated: 2021/02/12 19:05:34 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_option
{
	int		zero;
	int		minus;
	int		width;
	int		precision;
	char	type;
}				t_option;

int				max(int x, int y);
int				min(int x, int y);
int				ft_strlen(const char *s);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_litoa(long int n);
char			*ft_hitoa(unsigned long long int n, char *base);
void			filling(char fill, int size, int *len);
int				parse_flag(const char *format, t_option *option);
int				parse_width(const char *format, va_list arg, t_option *option);
int				parse_precision(const char *format, va_list arg,
				t_option *option);
int				parse_type(const char *format, t_option *option);
void			process_percent(int *len, t_option *option);
void			process_option(int *len, va_list arg, t_option *option);
void			process_char(int *len, va_list arg, t_option *option);
void			process_string(int *len, va_list arg, t_option *option);
void			process_decimal(int *len, va_list arg, t_option *option);
void			process_un_decimal(int *len, va_list arg, t_option *option);
void			process_hex(int *len, va_list arg, t_option *option,
				char *base);
void			process_hex_low(int *len, va_list arg, t_option *option);
void			process_hex_up(int *len, va_list arg, t_option *option);
void			process_pointer(int *len, va_list arg, t_option *option);
int				ft_printf(const char *format, ...);

#endif
