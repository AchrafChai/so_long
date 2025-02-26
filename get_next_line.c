/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:52:30 by acchairo          #+#    #+#             */
/*   Updated: 2025/02/25 16:42:09 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*set_new_line(char **rest)
{
	char	*str;
	char	*new;
	int		i;
	int		j;

	if (!*rest || **rest == '\0')
		return (NULL);
	i = 0;
	while ((*rest)[i] && (*rest)[i] != '\n')
		i++;
	if ((*rest)[i] == '\n')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	j = -1;
	while (++j < i)
		str[j] = (*rest)[j];
	str[j] = '\0';
	new = ft_strdup(*rest + i);
	if (!new)
		return (free(str), str = NULL, NULL);
	free(*rest);
	*rest = new;
	return (str);
}

static char	*get_full_line(int fd, char **rest, char *buff)
{
	ssize_t	readed;
	char	*temp;

	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
			return (NULL);
		if (readed == 0)
			break ;
		buff[readed] = '\0';
		if (!*rest)
			*rest = ft_strdup("");
		if (!*rest)
			return (NULL);
		temp = ft_strjoin(*rest, buff);
		free(*rest);
		if (!temp)
			return (NULL);
		*rest = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (*rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647
		|| read(fd, 0, 0) == -1)
		return (free(rest), rest = NULL, NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (free(rest), rest = NULL, NULL);
	rest = get_full_line(fd, &rest, buff);
	free(buff);
	buff = NULL;
	if (!rest)
		return (free(rest), rest = NULL, NULL);
	line = set_new_line(&rest);
	if (!line)
		return (free(rest), rest = NULL, line);
	return (line);
}
