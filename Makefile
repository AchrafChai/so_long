SRC = src/so_long.c src/so_long_utils.c src/ft_map.c src/ft_map_utils.c src/ft_path.c src/ft_game.c src/ft_game_utils.c src/get_next_line.c src/get_next_line_utils.c
SRC_B = bonus/so_long_bonus.c bonus/so_long_utils_bonus.c bonus/ft_map_bonus.c bonus/ft_map_utils_bonus.c bonus/ft_path_bonus.c bonus/ft_game_bonus.c \
bonus/ft_game_utils_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/ft_enemy_bonus.c bonus/ft_player_bonus.c

OBJ = $(SRC:%.c=%.o)
OBJ_B = $(SRC_B:%.c=%.o)

NAME = so_long
NAME_B = so_long_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} $^ -L../mlx -lmlx -lXext -lX11 -lm -o $@

$(OBJ): src/%.o: src/%.c src/so_long.h
	$(CC) $(FLAGS) -c $< -o $@

bonus: ${OBJ_B}
	${CC} ${FLAGS} $^ -L../mlx -lmlx -lXext -lX11 -lm -o ${NAME_B}

$(OBJ_B): bonus/%.o: bonus/%.c bonus/so_long_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f ${OBJ} ${OBJ_B}

fclean: clean
	rm -f ${NAME} ${NAME_B}

re: fclean all

.PHONY: clean