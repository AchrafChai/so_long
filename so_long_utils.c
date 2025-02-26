/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:31:28 by acchairo          #+#    #+#             */
/*   Updated: 2025/02/25 22:57:09 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fd_get(char *map)
{
	int		fd;
	size_t	width;

	fd = -1;
	width = ft_strlen(map);
	if (map[width - 4] == '.' && map[width - 3] == 'b'
		&& map[width - 2] == 'e' && map[width - 1] == 'r')
		fd = open(map, O_RDONLY);
	return (fd);
}

size_t	ft_valid_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != '\n')
		{
			i++;
			if (i >= 20)
				return (0);
		}
	}
	return (i);
}
