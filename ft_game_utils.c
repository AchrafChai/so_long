/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:15:31 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/02 18:22:13 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	move_up(t_gg *gg)
{
	int x;
	int y;

	x = (*gg).player.x;
	y = (*gg).player.y;
	(*gg).player.y -= 1;
	(*gg).player.move += 1;
	mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_0, x * 32, y * 32);
	mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_p, x * 32, (y - 1) * 32);
}

void	move_down(t_gg *gg)
{
	int x;
	int y;

	x = (*gg).player.x;
	y = (*gg).player.y;
	(*gg).player.y += 1;
	(*gg).player.move += 1;
	mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_0, x * 32, y * 32);
	mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_p, x * 32, (y + 1) * 32);
}

void	move_left(t_gg *gg)
{
	int x;
	int y;

	x = (*gg).player.x;
	y = (*gg).player.y;
	(*gg).player.x -= 1;
	(*gg).player.move += 1;
	mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_0, x * 32, y * 32);
	mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_p, (x - 1) * 32, y * 32);
}

void	move_right(t_gg *gg)
{
	int x;
	int y;

	x = (*gg).player.x;
	y = (*gg).player.y;
	(*gg).player.x += 1;
	(*gg).player.move += 1;
	mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_0, x * 32, y * 32);
	mlx_put_image_to_window((*gg).mlx.mlx, (*gg).mlx.win, (*gg).img_p, (x + 1) * 32, y * 32);
}
