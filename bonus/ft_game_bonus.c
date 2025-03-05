/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:59:28 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/05 17:36:03 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>

ft_anim_do(t_gg *gg, int x, int y, int count)
{
	if ((*gg).map[y][x] == 'P')
			ft_close("game over!\n", gg, NULL);
	(*gg).map[y][x + count] = '0';
	(*gg).map[y][x] = 'M';
	MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_m1, (*gg).x - (count * 32), (*gg).y);
	MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_0, (*gg).x, (*gg).y);
}

void ft_anim_check(t_gg *gg)
{
	int	x;
	int	y;

	x = (*gg).x / 32;
	y = (*gg).y / 32;
	if (((*gg).map[y][x - 1] == '0'
		|| (*gg).map[y][x - 1] != 'P') && (*gg).player == 1)
	{
		ft_anim_do(gg, x - 1, y, 1);
		(*gg).x -= 32;
	}
	if (((*gg).map[y][x + 1] == '0'
		|| (*gg).map[y][x + 1] == 'P') && (*gg).player == -1)
	{
		ft_anim_do(gg, x + 1, y, -1);
		(*gg).x += 32;
	}
}

int	ft_anim(t_gg *gg)
{
	(*gg).door += 1;

	if ((*gg).door % 5000 == 0)
		MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_m2, (*gg).x, (*gg).y);
	if ((*gg).door % 10000 == 0)
		MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_m3, (*gg).x, (*gg).y);
	if ((*gg).door % 15000 == 0)
		MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_m4, (*gg).x, (*gg).y);
	if ((*gg).door % 20000 == 0)
		MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_m5, (*gg).x, (*gg).y);	
	if ((*gg).door % 25000 == 0)
	{
		ft_anim_check(gg);
		(*gg).door = 1;
	}
	return (1);
}

int	ft_game_load(t_gg *gg, int *a)
{
	(*gg).img_1 = MLX_XMP((*gg).mlx, "textures/wall.xpm", a, a);
	(*gg).img_0 = MLX_XMP((*gg).mlx, "textures/floor.xpm", a, a);
	(*gg).img_e = MLX_XMP((*gg).mlx, "textures/door.xpm", a, a);
	(*gg).img_p = MLX_XMP((*gg).mlx, "textures/player.xpm", a, a);
	(*gg).img_c = MLX_XMP((*gg).mlx, "textures/coin.xpm", a, a);
	(*gg).img_m1 = MLX_XMP((*gg).mlx, "textures/donkey1.xpm", a, a);
	(*gg).img_m2 = MLX_XMP((*gg).mlx, "textures/donkey2.xpm", a, a);
	(*gg).img_m3 = MLX_XMP((*gg).mlx, "textures/donkey3.xpm", a, a);
	(*gg).img_m4 = MLX_XMP((*gg).mlx, "textures/donkey4.xpm", a, a);
	(*gg).img_m5 = MLX_XMP((*gg).mlx, "textures/donkey5.xpm", a, a);
	if (!(*gg).img_1 || !(*gg).img_0 || !(*gg).img_e || !(*gg).img_p
		|| !(*gg).img_c || !(*gg).img_m1 || !(*gg).img_m2 || !(*gg).img_m3
		|| !(*gg).img_m4 || !(*gg).img_m5)
		return (0);
	return (1);
}

void	ft_game_build(t_gg *gg, int a, int x, int y)
{
	while (y < (*gg).height)
	{
		x = 0;
		while (x < (*gg).width)
		{
			if ((*gg).map[y][x] == '1')
				MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_1, a * x, a * y);
			if ((*gg).map[y][x] == '0')
				MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_0, a * x, a * y);
			if ((*gg).map[y][x] == 'E')
				MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_e, a * x, a * y);
			if ((*gg).map[y][x] == 'P')
				MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_p, a * x, a * y);
			if ((*gg).map[y][x] == 'C')
				MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_c, a * x, a * y);
			if ((*gg).map[y][x] == 'M')
			{
				MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_m1, a * x, a * y);
				(*gg).x = x * a;
				(*gg).y = y * a;
				printf("%s\n", (*gg).map[4]);
				printf("%s\n", (*gg).map[5]);
				printf("%s\n", (*gg).map[6]);
				printf("********************\n");
				mlx_loop_hook((*gg).mlx, ft_anim, gg);
			}
			x++;
		}
		y++;
	}
}

int	ft_game_move(int keycode, t_gg *gg)
{
	int	x;
	int	y;

	x = (*gg).px;
	y = (*gg).py;
	if (keycode == 119 && (*gg).map[y - 1][x] != '1')
		move_up(gg);
	else if (keycode == 115 && (*gg).map[y + 1][x] != '1')
		move_down(gg);
	else if (keycode == 100 && (*gg).map[y][x + 1] != '1')
		move_right(gg);
	else if (keycode == 97 && (*gg).map[y][x - 1] != '1')
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
	(*gg).win = mlx_new_window((*gg).mlx, (*gg).width * 32,
			(*gg).height * 32, "game");
	if (!(*gg).win)
		ft_close("Error\ncan't open game!\n", gg, NULL);
	ft_game_build(gg, a, 0, 0);
	mlx_hook((*gg).win, 17, 0, ft_over, gg);
	mlx_hook((*gg).win, 2, 1L, ft_game_move, gg);
	mlx_loop((*gg).mlx);
}
