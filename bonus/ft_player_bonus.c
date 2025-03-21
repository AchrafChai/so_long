/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:19:21 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/21 20:08:30 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_player(t_gg *gg)
{
	(*gg).j += 1;
	if ((*gg).j == 1)
		mlx_put_image_to_window((*gg).mlx, (*gg).win,
			(*gg).img_p1, 32 * (*gg).px, 32 * (*gg).py);
	else if ((*gg).j == 5000)
		mlx_put_image_to_window((*gg).mlx, (*gg).win,
			(*gg).img_p2, 32 * (*gg).px, 32 * (*gg).py);
	else if ((*gg).j == 10000)
		mlx_put_image_to_window((*gg).mlx, (*gg).win,
			(*gg).img_p3, 32 * (*gg).px, 32 * (*gg).py);
	else if ((*gg).j == 15000)
	{
		mlx_put_image_to_window((*gg).mlx, (*gg).win,
			(*gg).img_p4, 32 * (*gg).px, 32 * (*gg).py);
		(*gg).j = 0;
	}
	if ((*gg).enemy)
		ft_anim(gg);
	return (0);
}
