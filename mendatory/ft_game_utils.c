/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:15:31 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/03 23:32:05 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	move_up(t_gg *gg)
{
	int	x;
	int	y;

	x = (*gg).px;
	y = (*gg).py;
	if ((*gg).map[y - 1][x] == 'E' && (*gg).coin != 0)
		return ;
	if ((*gg).map[y - 1][x] == 'E' && (*gg).coin == 0)
		ft_close("game over!\n", gg, NULL);
	if ((*gg).map[y - 1][x] == 'C')
	{
		(*gg).map[y - 1][x] = '0';
		(*gg).coin -= 1;
	}
	(*gg).py -= 1;
	(*gg).move += 1;
	MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_0, x * 32, y * 32);
	MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_p, x * 32, (y - 1) * 32);
	ft_putnbr((*gg).move);
	write(1, "\n", 1);
}

void	move_down(t_gg *gg)
{
	int	x;
	int	y;

	x = (*gg).px;
	y = (*gg).py;
	if ((*gg).map[y + 1][x] == 'E' && (*gg).coin != 0)
		return ;
	if ((*gg).map[y + 1][x] == 'E' && (*gg).coin == 0)
		ft_close("game over!\n", gg, NULL);
	if ((*gg).map[y + 1][x] == 'C')
	{
		(*gg).map[y + 1][x] = '0';
		(*gg).coin -= 1;
	}
	(*gg).py += 1;
	(*gg).move += 1;
	MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_0, x * 32, y * 32);
	MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_p, x * 32, (y + 1) * 32);
	ft_putnbr((*gg).move);
	write(1, "\n", 1);
}

void	move_left(t_gg *gg)
{
	int	x;
	int	y;

	x = (*gg).px;
	y = (*gg).py;
	if ((*gg).map[y][x - 1] == 'E' && (*gg).coin != 0)
		return ;
	if ((*gg).map[y][x - 1] == 'E' && (*gg).coin == 0)
		ft_close("game over!\n", gg, NULL);
	if ((*gg).map[y][x - 1] == 'C')
	{
		(*gg).map[y][x - 1] = '0';
		(*gg).coin -= 1;
	}
	(*gg).px -= 1;
	(*gg).move += 1;
	MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_0, x * 32, y * 32);
	MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_p, (x - 1) * 32, y * 32);
	ft_putnbr((*gg).move);
	write(1, "\n", 1);
}

void	move_right(t_gg *gg)
{
	int	x;
	int	y;

	x = (*gg).px;
	y = (*gg).py;
	if ((*gg).map[y][x + 1] == 'E' && (*gg).coin != 0)
		return ;
	if ((*gg).map[y][x + 1] == 'E' && (*gg).coin == 0)
		ft_close("game over!\n", gg, NULL);
	if ((*gg).map[y][x + 1] == 'C')
	{
		(*gg).map[y][x + 1] = '0';
		(*gg).coin -= 1;
	}
	(*gg).px += 1;
	(*gg).move += 1;
	MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_0, x * 32, y * 32);
	MLX_PUT((*gg).mlx, (*gg).win, (*gg).img_p, (x + 1) * 32, y * 32);
	ft_putnbr((*gg).move);
	write(1, "\n", 1);
}
