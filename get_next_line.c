/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:46:11 by jsilance          #+#    #+#             */
/*   Updated: 2019/11/23 22:13:52 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		*tmp;
	static char	*tmp_fd[OPEN_MAX];
	int			*ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	ret = (int[3]){0, !tmp_fd[fd], 0};
	if (!(*line = ft_strdup("")) ||
		!(tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	(!tmp_fd[fd]) ? (int)(tmp_fd[fd] = ft_strdup("")) :
	(ret[1] = str_liner(tmp_fd[fd], &tmp_fd[fd], line, 0));
	if (ret[1] && tmp_fd[fd] && !*tmp_fd[fd])
		while ((ret[0] = read(fd, tmp, BUFFER_SIZE)) > 0 &&
			(ret[2] = 1))
			if ((tmp[ret[0]] = 0) || str_liner(tmp, &tmp_fd[fd], line, 0) != 1)
				break ;
	free(tmp);
	return (ret[2] || !ret[1] || **line);
}
