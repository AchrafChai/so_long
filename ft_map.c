/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:30:23 by acchairo          #+#    #+#             */
/*   Updated: 2025/02/25 23:35:34 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check(char *map, t_gg *gg)
{
	int	i;

	i = 0;
	while ((*gg).map[i])
	{
		if (!ft_map_valid((*gg).map[i], *gg, i))
		{
			(*gg).player.player = 0;
			break ;
		}
		ft_map_check_done((*gg).map[i], gg);
		i++;
	}
}

void	ft_map_fill(char *map, t_gg *gg)
{
	int		fd;
	char	*str;

	fd = ft_fd_get(map);
	str = get_next_line(fd);
	(*gg).i = 0;
	while (str)
	{
		if (str[(*gg).width] == '\n')
			str[(*gg).width] = '\0';
		(*gg).map[(*gg).i] = str;
		str = get_next_line(fd);
		(*gg).i++;
	}
	(*gg).map[(*gg).i] = NULL;
	get_next_line(-1);
	close(fd);
}

t_gg	ft_map_get(char *map)
{
	t_gg	gg;

	ft_map_init(&gg);
	ft_map_height_width(map, &gg);
	if ((gg.height * gg.width) < 15 || gg.width < 3 || gg.height < 3)
		(write(2, "Error\n", 6), exit(1));
	gg.map = malloc(sizeof(char *) * (gg.height + 1));
	if (!gg.map)
		(write(2, "Error\n", 6), exit(1));
	ft_map_fill(map, &gg);
	ft_map_check(map, &gg);
	if (gg.player.player != 1 || gg.coin < 1 || gg.door != 1)
		(write(2, "Error\n", 6), ft_map_free(&gg, gg.i), exit(1));
	return (gg);
}
