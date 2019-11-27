/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:46:11 by jsilance          #+#    #+#             */
/*   Updated: 2019/11/26 19:48:24 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		*tmp;
	static char	tmp_fd[OPEN_MAX][BUFFER_SIZE + 1];
	int			*ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd >= OPEN_MAX)
		return (-1);
	ret = (int[4]){0, !tmp_fd[fd], 0, 0};
	if (!(*line = ft_strdup("")) ||
		!(tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	(!tmp_fd[fd]) ? (int)(tmp_fd[fd][0] = '\0') :
	(ret[1] = str_liner(tmp_fd[fd], tmp_fd, line, fd));
	if (ret[1] && tmp_fd[fd] && !tmp_fd[fd][0])
		while ((ret[0] = read(fd, tmp, BUFFER_SIZE)) > 0 &&
			(ret[2] = 1))
			if ((tmp[ret[0]] = 0) ||
				(ret[3] = str_liner(tmp, tmp_fd, line, fd) != 1))
				break ;
	free(tmp);
	return ((ret[1] == -1 || ret[3] == -1) ? -1 : !(ret[0] == 0 && ret[1]) &&
		(ret[2] || !ret[1] || **line));
}
