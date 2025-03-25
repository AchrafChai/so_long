/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:03:13 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/25 08:50:29 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(t_gg *gg)
{
	if (gg)
	{
		if ((*gg).img_p1)
			mlx_destroy_image((*gg).mlx, (*gg).img_p1);
		if ((*gg).img_p2)
			mlx_destroy_image((*gg).mlx, (*gg).img_p2);
		if ((*gg).img_p3)
			mlx_destroy_image((*gg).mlx, (*gg).img_p3);
		if ((*gg).img_p4)
			mlx_destroy_image((*gg).mlx, (*gg).img_p4);
		if ((*gg).eg)
			free((*gg).eg);
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
		if ((*gg).img_m)
			mlx_destroy_image((*gg).mlx, (*gg).img_m);
		if ((*gg).img_c)
			mlx_destroy_image((*gg).mlx, (*gg).img_c);
		if ((*gg).win)
			mlx_destroy_window((*gg).mlx, (*gg).win);
		if ((*gg).mlx)
			(mlx_destroy_display((*gg).mlx), free((*gg).mlx));
	}
	exit(1);
}

int	ft_over(t_gg *gg)
{
	ft_close("game closed\n", gg, NULL);
	return (1);
}

int	main(int argc, char **argv)
{
	t_gg	gg;

	if (argc < 2)
		ft_close("Error\ninvalid map\n", NULL, NULL);
	gg = ft_map_get(argv[1]);
	ft_path_check(&gg);
	ft_game(&gg);
}
