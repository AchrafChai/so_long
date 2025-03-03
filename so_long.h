/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acchairo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:38:33 by acchairo          #+#    #+#             */
/*   Updated: 2025/03/02 18:19:39 by acchairo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_player
{
	int		x;
	int		y;
	int		player;
	int		move;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}	t_mlx;

typedef struct s_gg
{
	int			width;
	int			height;
	t_player	player;
	int			door;
	int			coin;
	int			i;
	char		**map;
	t_mlx		mlx;
	void		*img_1;
	void		*img_0;
	void		*img_p;
	void		*img_e;
	void		*img_c;

}	t_gg;

int		ft_fd_get(char *map);

t_gg	ft_map_get(char *map);
void	ft_map_init(t_gg *gg);
void	ft_map_height_width(char *map, t_gg *gg);
void	ft_map_check(char *map, t_gg *gg);
int		ft_map_valid(char *str, t_gg gg, int i);
void	ft_map_check_done(char *str, t_gg *gg);
void	ft_map_fill(char *map, t_gg *gg);
void	ft_map_free(t_gg *gg, int i);

void	ft_path_check(t_gg *gg);
void	ft_path_player(t_gg *gg);

void	ft_game(t_gg *gg);
int		ft_game_load(t_gg *gg, int *a);
void	ft_game_build(t_gg *gg, int a);
int		ft_game_move(int keycode, t_gg *gg);
void	move_up(t_gg *gg);
void	move_right(t_gg *gg);
void	move_down(t_gg *gg);
void	move_left(t_gg *gg);


size_t	ft_valid_strlen(const char *s, t_gg *gg);

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

#endif