/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:37:30 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/05 14:58:32 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_path_player(t_gg *gg)
{
	int	x;
	int	y;

	y = 1;
	while ((*gg).map[y])
	{
		x = 0;
		while ((*gg).map[y][x])
		{
			if ((*gg).map[y][x] == 'P')
			{
				(*gg).px = x;
				(*gg).py = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

t_gg	ft_path_copy(t_gg *gg)
{
	t_gg	cgg;

	cgg.map = malloc(sizeof(char *) * ((*gg).height + 1));
	if (!cgg.map)
		ft_close("Error\ncan't cheack valid path!\n", gg, NULL);
	cgg.i = 0;
	while ((*gg).map[cgg.i])
	{
		cgg.map[cgg.i] = ft_strdup((*gg).map[cgg.i]);
		if (!cgg.map[cgg.i])
			ft_close("Error\ncan't cheack valid path!\n", gg, &cgg);
		cgg.i++;
	}
	cgg.map[cgg.i] = NULL;
	return (cgg);
}

void	ft_path_fill(t_gg gg, t_gg *cgg, int x, int y)
{
	if ((*cgg).map[y][x] == 'E')
	{
		(*cgg).map[y][x] = 'A';
		return ;
	}
	(*cgg).map[y][x] = 'A';
	if ((*cgg).map[y - 1][x] != '1' && (*cgg).map[y - 1][x] != 'A'
		&& (*cgg).map[y - 1][x] != 'M')
		ft_path_fill(gg, cgg, x, y - 1);
	if ((*cgg).map[y + 1][x] != '1' && (*cgg).map[y + 1][x] != 'A'
		&& (*cgg).map[y - 1][x] != 'M')
		ft_path_fill(gg, cgg, x, y + 1);
	if ((*cgg).map[y][x - 1] != '1' && (*cgg).map[y][x - 1] != 'A'
		&& (*cgg).map[y - 1][x] != 'M')
		ft_path_fill(gg, cgg, x - 1, y);
	if ((*cgg).map[y][x + 1] != '1' && (*cgg).map[y][x + 1] != 'A'
		&& (*cgg).map[y - 1][x] != 'M')
		ft_path_fill(gg, cgg, x + 1, y);
}

void	ft_path_valid(t_gg *gg, t_gg *cgg)
{
	int	y;
	int	x;

	y = 1;
	while (y < (*gg).height)
	{
		x = 1;
		while (x < (*gg).width)
		{
			if ((*cgg).map[y][x] == 'C' || (*cgg).map[y][x] == 'E')
				ft_close("Error\ninvalid map!\n", gg, cgg);
			x++;
		}
		y++;
	}
}

void	ft_path_check(t_gg *gg)
{
	t_gg	cgg;

	ft_path_player(gg);
	cgg = ft_path_copy(gg);
	ft_path_fill(*gg, &cgg, (*gg).px, (*gg).py);
	ft_path_valid(gg, &cgg);
	ft_map_free(&cgg, cgg.i);
}
