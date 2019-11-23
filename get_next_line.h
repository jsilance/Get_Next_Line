/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:47:55 by jsilance          #+#    #+#             */
/*   Updated: 2019/11/22 15:19:08 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 8

# endif

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		str_liner(char *tmp, char **temp, char **line, int i);
char	*ft_strdup(const char *s);
char	*ft_strstock(char *ptr, char str);

#endif
