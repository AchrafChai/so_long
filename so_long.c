/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:03:13 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/03 17:42:40 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_close(char *msg, t_gg *gg, t_gg *cgg)
{
	ft_putstr(msg);
	if ((*gg).map)
		ft_map_free(&gg, (*gg).i);
	exit(1);
}

void ft_over(t_gg *gg)
{
	ft_close("Error\ngame closed\n", gg, NULL);
}

int	main(int argc, char **argv)
{
	t_gg	gg;

	if (argc < 2)
		ft_close("Error\nYou need to enter the map file!\n", &gg, NULL);
	gg = ft_map_get(argv[1]);
	ft_path_check(&gg);
	ft_game(&gg);
}
