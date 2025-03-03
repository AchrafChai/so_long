/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:03:13 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/01 20:13:29 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_gg	gg;

	if (argc < 2)
		(write(2, "Error\n", 6), exit(1));
	gg = ft_map_get(argv[1]);
	ft_path_check(&gg);
	ft_game(&gg);
	ft_map_free(&gg, gg.i);
}
