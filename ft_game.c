/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:59:28 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/03 17:41:07 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"



#include <stdio.h>

int	ft_game_load(t_gg *gg, int *a)
{
	(*gg).img_1 = mlx_xpm_file_to_image((*gg).mlx.mlx, "textures/wall.xpm", a, a);
	(*gg).img_0 = mlx_xpm_file_to_image((*gg).mlx.mlx, "textures/floor.xpm", a, a);
	(*gg).img_e = mlx_xpm_file_to_image((*gg).mlx.mlx, "textures/door.xpm", a, a);
	(*gg).img_p = mlx_xpm_file_to_image((*gg).mlx.mlx, "textures/player.xpm", a, a);
	(*gg).img_c = mlx_xpm_file_to_image((*gg).mlx.mlx, "textures/coin.xpm", a, a);
	if (!(*gg).img_1 || !(*gg).img_0 || !(*gg).img_e || !(*gg).img_p || !(*gg).img_c)
		return (0);
	return (1);
}

void	ft_game_build(t_gg *gg, int a)
{
	int	y;
	int x;

	y = 0;
	while (y < (*gg).height)
	{
		x = 0;
		while (x < (*gg).width)
		{
			if ((*gg).map[y][x] == '1')
				mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_1, a * x, a * y);
			if ((*gg).map[y][x] == '0')
				mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_0, a * x, a * y);
			if ((*gg).map[y][x] == 'E')
				mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_e, a * x, a * y);
			if ((*gg).map[y][x] == 'P')
				mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_p, a * x, a * y);
			if ((*gg).map[y][x] == 'C')
				mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_c, a * x, a * y);	
			x++;
		}
		y++;
	}
}

int	ft_game_move(int keycode, t_gg *gg)
{
	int x;
	int y;

	x = (*gg).player.x;
	y = (*gg).player.y;
	if (keycode == 119 && (*gg).map[y - 1][x] != '1')
		move_up(gg);
	else if(keycode == 115 && (*gg).map[y + 1][x] != '1')
		move_down(gg);
	else if(keycode == 100 && (*gg).map[y][x + 1] != '1')
		move_right(gg);
	else if(keycode == 97 && (*gg).map[y][x - 1] != '1')
		move_left(gg);
	else if (keycode == 65307)
		ft_close("Error\ngame closed!\n", gg, NULL);
	return (0);  
}

void	ft_game(t_gg *gg)
{	
	int	a;

	if (!ft_game_load(gg, &a))
		ft_close("Error\ncan't load game files!\n", gg, NULL);
	(*gg).mlx.win = mlx_new_window((*gg).mlx.mlx, (*gg).width * 32, (*gg).height * 32, "game");
	if (!(*gg).mlx.win)
		ft_close("Error\ncan't open game!\n", gg, NULL);
	ft_game_build(gg, a);
	mlx_hook((*gg).mlx.win, 17, 0, ft_over, gg);
	mlx_hook((*gg).mlx.win, 2, 1L, ft_game_move, gg);
	mlx_loop((*gg).mlx.mlx);
}
