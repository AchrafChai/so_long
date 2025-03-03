/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:37:30 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/01 19:57:10 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_path_player(t_gg *gg)
{
	int	i;
	int	j;

	i = 1;
	while ((*gg).map[i])
	{
		j = 0;
		while ((*gg).map[i][j])
		{
			if ((*gg).map[i][j] == 'P')
			{
				(*gg).player.x = j;
				(*gg).player.y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

t_gg	ft_path_copy(t_gg *gg)
{
	t_gg	cgg;
	int		i;

	cgg.map = malloc(sizeof(char *) * ((*gg).height + 1));
	if (!cgg.map)
		(write(2, "Error\n", 6), ft_map_free(gg, (*gg).i), exit(1));
	i = 0;
	while ((*gg).map[i])
	{
		cgg.map[i] = ft_strdup((*gg).map[i]);
		if (!cgg.map[i])
			(write(2, "Error\n", 6), ft_map_free(&cgg, i)
				, ft_map_free(gg, (*gg).i), exit(1));
		i++;
	}
	cgg.map[i] = NULL;
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
	if ((*cgg).map[y - 1][x] != '1'
		&& (*cgg).map[y - 1][x] != 'A')
		ft_path_fill(gg, cgg, x, y - 1);
	if ((*cgg).map[y + 1][x] != '1'
		&& (*cgg).map[y + 1][x] != 'A')
		ft_path_fill(gg, cgg, x, y + 1);
	if ((*cgg).map[y][x - 1] != '1'
		&& (*cgg).map[y][x - 1] != 'A')
		ft_path_fill(gg, cgg, x - 1, y);
	if ((*cgg).map[y][x + 1] != '1'
		&& (*cgg).map[y][x + 1] != 'A')
		ft_path_fill(gg, cgg, x + 1, y);
}

void	ft_path_valid(t_gg *gg, t_gg *cgg)
{
	int	i;
	int	j;

	i = 1;
	while (i < (*gg).height)
	{
		j = 1;
		while (j < (*gg).width)
		{
			if ((*cgg).map[i][j] == 'C')
			{
				ft_map_free(cgg, (*gg).i);
				ft_map_free(gg, (*gg).i);
				(write(2, "Error\n", 6), exit(1));
			}
			if ((*cgg).map[i][j] == 'E')
			{
				ft_map_free(cgg, (*gg).i);
				ft_map_free(gg, (*gg).i);
				(write(2, "Error\n", 6), exit(1));
			}
			j++;
		}
		i++;
	}
}

void	ft_path_check(t_gg *gg)
{
	t_gg	cgg;

	ft_path_player(gg);
	cgg = ft_path_copy(gg);
	ft_path_fill(*gg, &cgg, (*gg).player.x, (*gg).player.y);
	ft_path_valid(gg, &cgg);
	ft_map_free(&cgg, (*gg).i);
}
