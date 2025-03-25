/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:56:42 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/25 09:00:50 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_anim_do(t_gg *gg, int x, int y, int count)
{
	if ((*gg).map[y][x] == 'P')
		ft_close("game over!\n", gg, NULL);
	(*gg).map[y][x + count] = '0';
	(*gg).map[y][x] = 'M';
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_m,
		(*gg).eg[(*gg).player].x - (count * 32), (*gg).eg[(*gg).player].y);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_0,
		(*gg).eg[(*gg).player].x, (*gg).eg[(*gg).player].y);
}

void	ft_anim_check(t_gg *gg)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	while (++i < (*gg).enemy)
	{
		(*gg).player = i;
		x = (*gg).eg[i].x / 32;
		y = (*gg).eg[i].y / 32;
		if (((*gg).map[y][x - 1] == '0'
			|| (*gg).map[y][x - 1] == 'P') && (*gg).eg[i].lr == 1)
		{
			ft_anim_do(gg, x - 1, y, 1);
			(*gg).eg[i].x -= 32;
		}
		else if (((*gg).map[y][x + 1] == '0'
			|| (*gg).map[y][x + 1] == 'P') && (*gg).eg[i].lr == -1)
		{
			ft_anim_do(gg, x + 1, y, -1);
			(*gg).eg[i].x += 32;
		}
		else
			(*gg).eg[i].lr *= -1;
	}
}

int	ft_anim(t_gg *gg)
{
	int	i;

	i = 0;
	if ((*gg).door == 1)
	{
		while (i < (*gg).enemy)
		{
			mlx_put_image_to_window((*gg).mlx, (*gg).win,
				(*gg).img_m, (*gg).eg[i].x, (*gg).eg[i].y);
			i++;
		}
	}
	(*gg).door += 1;
	if ((*gg).door == 10000)
	{
		ft_anim_check(gg);
		(*gg).door = 2;
	}
	return (0);
}

void	ft_get_enemy(t_gg *gg, int a, int x, int y)
{
	int	i;

	i = 0;
	if ((*gg).enemy > 0)
	{
		(*gg).eg = malloc(sizeof(t_eg) * (*gg).enemy);
		if (!(*gg).eg)
			ft_close("Error\ncan't start the game", gg, NULL);
		while (y < (*gg).height)
		{
			x = 0;
			while (x < (*gg).width)
			{
				if ((*gg).map[y][x] == 'M')
				{
					(*gg).eg[i].lr = 1;
					(*gg).eg[i].x = x * a;
					(*gg).eg[i].y = y * a;
					i++;
				}
				x++;
			}
			y++;
		}
	}
}
