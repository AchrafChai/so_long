/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:59:28 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/02 18:27:32 by acchairo         ###   ########.fr       */
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
	int	i;
	int j;

	i = 0;
	while (i < (*gg).height)
	{
		j = 0;
		while (j < (*gg).width)
		{
			if ((*gg).map[i][j] == '1')
				mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_1, a * j, a * i);
			if ((*gg).map[i][j] == '0')
				mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_0, a * j, a * i);
			if ((*gg).map[i][j] == 'E')
				mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_e, a * j, a * i);
			if ((*gg).map[i][j] == 'P')
				mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_p, a * j, a * i);
			if ((*gg).map[i][j] == 'C')
				mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_c, a * j, a * i);	
			j++;
		}
		i++;
	}
}

int	ft_game_move(int keycode, t_gg *gg)
{
	int x;
	int y;

	x = (*gg).player.x;
	y = (*gg).player.y;
	if (keycode == 119 && (*gg).map[x - 1][y] != '1')
		move_up(gg);
	else if(keycode == 115 && (*gg).map[x + 1][y] != '1')
		move_down(gg);
	else if(keycode == 100 && (*gg).map[x][y + 1] != '1')
		move_right(gg);
	else if(keycode == 97 && (*gg).map[x][y - 1] != '1')
		move_left(gg);
	printf ("%d\n", keycode);
	return (0);  
}

void	ft_game(t_gg *gg)
{	
	int	a;

	if (!ft_game_load(gg, &a))
		return ;
	(*gg).mlx.win = mlx_new_window((*gg).mlx.mlx, (*gg).width * 32, (*gg).height * 32, "game");
	if (!(*gg).mlx.win)
		return ;
	ft_game_build(gg, a);
	mlx_key_hook((*gg).mlx.win, ft_game_move, gg);
	mlx_loop((*gg).mlx.mlx);
}
