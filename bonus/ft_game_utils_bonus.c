/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:15:31 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/21 21:44:15 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(t_gg *gg)
{
	char	*str;

	if ((*gg).map[(*gg).py - 1][(*gg).px] == 'E' && (*gg).coin != 0)
		return ;
	if ((*gg).map[(*gg).py - 1][(*gg).px] == 'E' && (*gg).coin == 0)
		ft_close("game win!\n", gg, NULL);
	if ((*gg).map[(*gg).py - 1][(*gg).px] == 'M')
		ft_close("game over!\n", gg, NULL);
	if ((*gg).map[(*gg).py - 1][(*gg).px] == 'C')
	{
		(*gg).map[(*gg).py - 1][(*gg).px] = '0';
		(*gg).coin -= 1;
	}
	(*gg).map[(*gg).py][(*gg).px] = '0';
	(*gg).map[(*gg).py - 1][(*gg).px] = 'P';
	(mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_0, (*gg).px * 32,
			(*gg).py * 32), mlx_put_image_to_window((*gg).mlx, (*gg).win,
			(*gg).img_p1, (*gg).px * 32, ((*gg).py - 1) * 32));
	(*gg).py -= 1;
	(*gg).move += 1;
	str = ft_itoa((*gg).move);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_1, 0, 0);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_1, 32, 0);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_1, 64, 0);
	(mlx_string_put((*gg).mlx, (*gg).win, 16, 16, 0, str), free(str));
}

void	move_down(t_gg *gg)
{
	char	*str;

	if ((*gg).map[(*gg).py + 1][(*gg).px] == 'E' && (*gg).coin != 0)
		return ;
	if ((*gg).map[(*gg).py + 1][(*gg).px] == 'E' && (*gg).coin == 0)
		ft_close("game win!\n", gg, NULL);
	if ((*gg).map[(*gg).py + 1][(*gg).px] == 'M')
		ft_close("game over!\n", gg, NULL);
	if ((*gg).map[(*gg).py + 1][(*gg).px] == 'C')
	{
		(*gg).map[(*gg).py + 1][(*gg).px] = '0';
		(*gg).coin -= 1;
	}
	(*gg).map[(*gg).py][(*gg).px] = '0';
	(*gg).map[(*gg).py + 1][(*gg).px] = 'P';
	(mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_0, (*gg).px * 32,
			(*gg).py * 32), mlx_put_image_to_window((*gg).mlx, (*gg).win,
			(*gg).img_p1, (*gg).px * 32, ((*gg).py + 1) * 32));
	(*gg).py += 1;
	(*gg).move += 1;
	str = ft_itoa((*gg).move);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_1, 0, 0);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_1, 32, 0);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_1, 64, 0);
	(mlx_string_put((*gg).mlx, (*gg).win, 16, 16, 0, str), free(str));
}

void	move_left(t_gg *gg)
{
	char	*str;

	if ((*gg).map[(*gg).py][(*gg).px - 1] == 'E' && (*gg).coin != 0)
		return ;
	if ((*gg).map[(*gg).py][(*gg).px - 1] == 'E' && (*gg).coin == 0)
		ft_close("game win!\n", gg, NULL);
	if ((*gg).map[(*gg).py][(*gg).px - 1] == 'M')
		ft_close("game over!\n", gg, NULL);
	if ((*gg).map[(*gg).py][(*gg).px - 1] == 'C')
	{
		(*gg).map[(*gg).py][(*gg).px - 1] = '0';
		(*gg).coin -= 1;
	}
	(*gg).map[(*gg).py][(*gg).px] = '0';
	(*gg).map[(*gg).py][(*gg).px - 1] = 'P';
	(mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_0, (*gg).px * 32,
			(*gg).py * 32), mlx_put_image_to_window((*gg).mlx, (*gg).win,
			(*gg).img_p1, ((*gg).px - 1) * 32, (*gg).py * 32));
	(*gg).px -= 1;
	(*gg).move += 1;
	str = ft_itoa((*gg).move);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_1, 0, 0);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_1, 32, 0);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_1, 64, 0);
	(mlx_string_put((*gg).mlx, (*gg).win, 16, 16, 0, str), free(str));
}

void	move_right(t_gg *gg)
{
	char	*str;

	if ((*gg).map[(*gg).py][(*gg).px + 1] == 'E' && (*gg).coin != 0)
		return ;
	if ((*gg).map[(*gg).py][(*gg).px + 1] == 'E' && (*gg).coin == 0)
		ft_close("game win!\n", gg, NULL);
	if ((*gg).map[(*gg).py][(*gg).px + 1] == 'M')
		ft_close("game over!\n", gg, NULL);
	if ((*gg).map[(*gg).py][(*gg).px + 1] == 'C')
	{
		(*gg).map[(*gg).py][(*gg).px + 1] = '0';
		(*gg).coin -= 1;
	}
	(*gg).map[(*gg).py][(*gg).px] = '0';
	(*gg).map[(*gg).py][(*gg).px + 1] = 'P';
	(mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_0, (*gg).px * 32,
			(*gg).py * 32), mlx_put_image_to_window((*gg).mlx, (*gg).win,
			(*gg).img_p1, ((*gg).px + 1) * 32, (*gg).py * 32));
	(*gg).px += 1;
	(*gg).move += 1;
	str = ft_itoa((*gg).move);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_1, 0, 0);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_1, 32, 0);
	mlx_put_image_to_window((*gg).mlx, (*gg).win, (*gg).img_1, 64, 0);
	(mlx_string_put((*gg).mlx, (*gg).win, 16, 16, 0, str), free(str));
}
