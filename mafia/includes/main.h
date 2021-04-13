/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaderi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:38:11 by gfratini          #+#    #+#             */
/*   Updated: 2021/03/20 19:40:04 by rpaderi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include "parse.h"

int		get_next_line(int fd, char **line);
int		parse_main(int fd, t_parse	*config);
void	window_main(t_parse *config);

#endif
