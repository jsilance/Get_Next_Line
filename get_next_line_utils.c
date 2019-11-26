/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 22:48:38 by jsilance          #+#    #+#             */
/*   Updated: 2019/11/26 03:59:05 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strstock(char *ptr, char str)
{
	char	*new_ptr;
	int		*i;

	i = (int[2]){0, 0};
	while (ptr && ptr[i[0]])
		i[0]++;
	i[0]++;
	if (!(new_ptr = malloc(sizeof(char) * (i[0] + 1))))
		return (NULL);
	i[0] = 0;
	while (ptr && ptr[i[0]])
		new_ptr[i[1]++] = ptr[i[0]++];
	new_ptr[i[1]++] = str;
	new_ptr[i[1]] = '\0';
	free(ptr);
	return (new_ptr);
}

char		*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (!(ptr = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s[++i])
		ptr[i] = s[i];
	ptr[i] = '\0';
	return (ptr);
}

int			str_liner(char *tmp, char temp[OPEN_MAX][BUFFER_SIZE + 1],
				char **line, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!tmp || !temp)
		return (-1);
	while (tmp[i])
		if (tmp[i] == '\n')
		{
			if (tmp[i += (tmp[i] == '\n')])
				while (tmp[i])
					temp[fd][j++] = tmp[i++];
			temp[fd][j] = 0;
			return (0);
		}
		else
			*line = ft_strstock(*line, tmp[i++]);
	temp[fd][0] = 0;
	return (1);
}
