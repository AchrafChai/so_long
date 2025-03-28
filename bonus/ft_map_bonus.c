/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:30:23 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/25 08:51:03 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_map_check(t_gg *gg)
{
	int	i;

	i = 0;
	while ((*gg).map[i])
	{
		if (!ft_map_valid((*gg).map[i], *gg, i))
		{
			(*gg).player = 0;
			break ;
		}
		ft_map_check_done((*gg).map[i], gg);
		i++;
	}
}

void	ft_map_fill(char *map, t_gg *gg)
{
	int		fd;
	char	*str;

	fd = ft_fd_get(map);
	str = get_next_line(fd);
	(*gg).i = 0;
	while (str)
	{
		if (str[(*gg).width] == '\n')
			str[(*gg).width] = '\0';
		(*gg).map[(*gg).i] = str;
		str = get_next_line(fd);
		(*gg).i++;
	}
	(*gg).map[(*gg).i] = NULL;
	get_next_line(-1);
	if (fd != -1)
		close(fd);
}

t_gg	ft_map_get(char *map)
{
	t_gg	gg;

	ft_map_init(&gg);
	ft_map_height_width(map, &gg);
	if ((gg.height * gg.width) < 15 || gg.width < 3 || gg.height < 3)
		ft_close("Error\ninvalid map\n", &gg, NULL);
	gg.map = malloc(sizeof(char *) * (gg.height + 1));
	if (!gg.map)
		ft_close("Error\ncan't load the map\n", &gg, NULL);
	ft_map_fill(map, &gg);
	ft_map_check(&gg);
	if (gg.player != 1 || gg.coin < 1 || gg.door != 1)
		ft_close("Error\ninvalid map\n", &gg, NULL);
	return (gg);
}

int	ft_cont(int c)
{
	size_t	i;

	i = 0;
	if (c < 0)
	{
		c = -c;
		i++;
	}
	while (c > 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	i = ft_cont(n);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	str[i] = '\0';
	while (n > 0)
	{
		i--;
		str[i] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
