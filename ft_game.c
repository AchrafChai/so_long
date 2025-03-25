/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:59:28 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/25 08:40:42 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_load(t_gg *gg, int *a)
{
	(*gg).img_1 = mlx_xpm_file_to_image((*gg).mlx, "textures/wall.xpm", a, a);
	(*gg).img_0 = mlx_xpm_file_to_image((*gg).mlx, "textures/floor.xpm", a, a);
	(*gg).img_e = mlx_xpm_file_to_image((*gg).mlx, "textures/door.xpm", a, a);
	(*gg).img_p = mlx_xpm_file_to_image((*gg).mlx, "textures/p1.xpm", a, a);
	(*gg).img_c = mlx_xpm_file_to_image((*gg).mlx, "textures/coin.xpm", a, a);
	if (!(*gg).img_1 || !(*gg).img_0 || !(*gg).img_e
		|| !(*gg).img_p || !(*gg).img_c)
		return (0);
	return (1);
}

void	ft_game_build(t_gg *gg, int a, int y)
{
	int	x;

	while (++y < (*gg).height)
	{
		x = -1;
		while (++x < (*gg).width)
		{
			if ((*gg).map[y][x] == '1')
				mlx_put_image_to_window((*gg).mlx, (*gg).win,
					(*gg).img_1, a * x, a * y);
			if ((*gg).map[y][x] == '0')
				mlx_put_image_to_window((*gg).mlx, (*gg).win,
					(*gg).img_0, a * x, a * y);
			if ((*gg).map[y][x] == 'E')
				mlx_put_image_to_window((*gg).mlx, (*gg).win,
					(*gg).img_e, a * x, a * y);
			if ((*gg).map[y][x] == 'P')
				mlx_put_image_to_window((*gg).mlx, (*gg).win,
					(*gg).img_p, a * x, a * y);
			if ((*gg).map[y][x] == 'C')
				mlx_put_image_to_window((*gg).mlx, (*gg).win,
					(*gg).img_c, a * x, a * y);
		}
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
		ft_close("game closed!\n", gg, NULL);
	return (0);
}

void	ft_game(t_gg *gg)
{
	int	a;

	if (!ft_game_load(gg, &a))
		ft_close("Error\ncan't load the game\n", gg, NULL);
	(*gg).win = mlx_new_window((*gg).mlx, (*gg).width * 32,
			(*gg).height * 32, "so_long");
	if (!(*gg).win)
		ft_close("Error\ncan't start the game\n", gg, NULL);
	ft_game_build(gg, a, -1);
	mlx_hook((*gg).win, 17, 0, ft_over, gg);
	mlx_hook((*gg).win, 2, 1L, ft_game_move, gg);
	mlx_loop((*gg).mlx);
}
