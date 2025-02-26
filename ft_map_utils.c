/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:41:06 by acchairo          #+#    #+#             */
/*   Updated: 2025/02/26 21:15:44 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_init(t_gg *gg)
{
	(*gg).height = 0;
	(*gg).width = 0;
	(*gg).coin = 0;
	(*gg).player.player = 0;
	(*gg).player.x = 0;
	(*gg).player.y = 0;
	(*gg).door = 0;
	(*gg).i = 0;
	(*gg).map = NULL;
}

void	ft_map_height_width(char *map, t_gg *gg)
{
	int		fd;
	char	*str;
	int		len;

	fd = ft_fd_get(map);
	str = get_next_line(fd);
	(*gg).width = ft_valid_strlen(str);
	while (str)
	{
		len = ft_valid_strlen(str);
		free(str);
		if ((*gg).width != len || len < 3)
		{
			get_next_line(-1);
			close(fd);
			(write(2, "Error\n", 6), exit(1));
		}
		str = get_next_line(fd);
		(*gg).height++;
	}
	get_next_line(-1);
	if (fd != -1)
		close(fd);
}

void	ft_map_check_done(char *str, t_gg *gg)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == 'P')
			(*gg).player.player++;
		else if (str[j] == 'E')
			(*gg).door++;
		else if (str[j] == 'C')
			(*gg).coin++;
		j++;
	}
}

int	ft_map_valid(char *str, t_gg gg, int i)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (i == 0 || i == (gg.height - 1) || j == 0 || j == gg.width - 1)
		{
			if (str[j] != '1')
				return (0);
		}
		else
		{
			if (str[j] != '0' && str[j] != '1' && str[j] != 'C'
				&& str[j] != 'E' && str[j] != 'P')
				return (0);
		}
		j++;
	}
	if (j != gg.width)
		return (0);
	return (1);
}

void	ft_map_free(t_gg *gg, int i)
{
	if ((*gg).map)
	{
		while (i != -1)
		{
			free((*gg).map[i]);
			i--;
		}
		free((*gg).map);
	}
}
