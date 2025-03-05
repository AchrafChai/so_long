/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:03:13 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/05 15:41:59 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(t_gg *gg)
{
	if (gg)
	{
		if ((*gg).img_m1)
			mlx_destroy_image((*gg).mlx, (*gg).img_m1);
		if ((*gg).img_m2)
			mlx_destroy_image((*gg).mlx, (*gg).img_m2);
		if ((*gg).img_m3)
			mlx_destroy_image((*gg).mlx, (*gg).img_m3);
		if ((*gg).img_m4)
			mlx_destroy_image((*gg).mlx, (*gg).img_m4);
		if ((*gg).img_m5)
			mlx_destroy_image((*gg).mlx, (*gg).img_m5);
	}
}

void	ft_close(char *msg, t_gg *gg, t_gg *cgg)
{
	ft_putstr(msg);
	if (gg)
	{
		ft_map_free(gg, (*gg).i);
		if (cgg)
			ft_map_free(cgg, (*cgg).i);
		ft_free(gg);
		if ((*gg).img_0)
			mlx_destroy_image((*gg).mlx, (*gg).img_0);
		if ((*gg).img_1)
			mlx_destroy_image((*gg).mlx, (*gg).img_1);
		if ((*gg).img_e)
			mlx_destroy_image((*gg).mlx, (*gg).img_e);
		if ((*gg).img_p)
			mlx_destroy_image((*gg).mlx, (*gg).img_p);
		if ((*gg).img_c)
			mlx_destroy_image((*gg).mlx, (*gg).img_c);
		if ((*gg).win)
			mlx_destroy_window((*gg).mlx, (*gg).win);
		if ((*gg).mlx)
			mlx_destroy_display((*gg).mlx), free((*gg).mlx);
	}
	exit(1);
}

int	ft_over(t_gg *gg)
{
	ft_close("Error\ngame closed\n", gg, NULL);
	return (1);
}

int	main(int argc, char **argv)
{
	t_gg	gg;

	if (argc < 2)
		ft_close("Error\nYou need to enter the map file!\n", NULL, NULL);
	gg = ft_map_get(argv[1]);
	ft_path_check(&gg);
	ft_game(&gg);
}
