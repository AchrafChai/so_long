/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:31:28 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/01 20:48:49 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

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

size_t	ft_valid_strlen(const char *s, t_gg *gg)
{
	size_t	i;

	i = 0;
	if (!(*gg).mlx.mlx)
	{
		(*gg).mlx.mlx = mlx_init();
		if (!(*gg).mlx.mlx)
		{
			(*gg).mlx.x = 20;
			(*gg).mlx.y = 20;
		}
		else
			(mlx_get_screen_size((*gg).mlx.mlx, &(*gg).mlx.x, &(*gg).mlx.y));
	}
	if (s)
	{
		while (s[i] && s[i] != '\n')
		{
			i++;
			if (i >= ((*gg).mlx.x / 32))
				return (0);
		}
	}
	return (i);
}
