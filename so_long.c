/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:03:13 by acchairo          #+#    #+#             */
/*   Updated: 2025/02/22 18:32:04 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_fd(char *map)
{
	int		fd;
	size_t	size;

	fd = -1;
	size = ft_strlen(map);
	if (map[size - 4] == '.' && map[size - 3] == 'b'
		&& map[size - 2] == 'e' && map[size - 1] == 'r')
		fd = open(map, O_RDONLY);
	return (fd);
}

int	ft_len_map(char *map)
{
	int		i;
	int		fd;
	char	*str;
	int		size;
	
	i = 0;
	fd = ft_get_fd(map);
	str = get_next_line(fd);
	size = ft_strlen(str);
	if (size < 4)
		return (-1);
	while (str)
	{
		str = get_next_line(fd);
		if (str[ft_strlen(str)])
		if (size - 1 != ft_strlen(str))
		i++;
	}
	get_next_line(-1);
	close(fd);
	return (i);
}

char	**ft_get_map(char *map)
{
	int		fd;
	int		size;
	char	*str;

	size = ft_len_map(map);
	printf("%ld\n", size);
	return NULL;	
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc < 2)
		(write(2, "Error\n", 6),exit(1));
	map = ft_get_map(argv[1]);
}
