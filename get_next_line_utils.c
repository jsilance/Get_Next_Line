/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 22:48:38 by jsilance          #+#    #+#             */
/*   Updated: 2019/11/23 21:01:53 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char **temp)
{
	free(*temp);
	*temp = ft_strdup("");
}

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

int			str_liner(char *tmp, char **temp, char **line, int i)
{
	char		*tmp2;

	if (!tmp || !temp)
		return (-1);
	while (tmp[i])
		if (tmp[i] == '\n')
		{
			if (tmp[i += (tmp[i] == '\n')])
			{
				tmp2 = *temp;
				*temp = ft_strdup("");
				while (tmp[i])
					*temp = ft_strstock(*temp, tmp[i++]);
				free(tmp2);
			}
			else
				ft_free(temp);
			return (0);
		}
		else
			*line = ft_strstock(*line, tmp[i++]);
	ft_free(temp);
	return (1);
}
