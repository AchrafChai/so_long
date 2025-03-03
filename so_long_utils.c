/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:31:28 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/03 17:15:53 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	ft_fd_get(char *map)
{
	int		fd;
	size_t	width;

	fd = -1;
	width = ft_strlen(map);
	if (map[width - 4] == '.' && map[width - 3] == 'b'
		&& map[width - 2] == 'e' && map[width - 1] == 'r')
		fd = open(map, O_RDONLY);
	return (fd);
}

size_t	ft_valid_strlen(const char *s, t_gg *gg)
{
	size_t	i;

	i = 0;
	if (!(*gg).mlx.mlx)
	{
		(*gg).mlx.mlx = mlx_init();
		if (!(*gg).mlx.mlx)
			(write(2, "Error\n", 6), exit(1));
		else
			(mlx_get_screen_size((*gg).mlx.mlx, &(*gg).mlx.x, &(*gg).mlx.y));
	}
	if (s)
	{
		while (s[i] && s[i] != '\n')
		{
			i++;
			if (i >= ((*gg).mlx.x / 32))
				return (0);
		}
	}
	return (i);
}

void	ft_putchr(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(2, &s[i], 1);
			i++;
		}
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchr(n + 48);
}
