SRC = so_long.c so_long_utils.c ft_map.c ft_map_utils.c ft_path.c ft_game.c ft_game_utils.c get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

NAME = so_long
CC = cc
# FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} $^ -Lmlx -lmlx -lXext -lX11 -lm -o $@

$(OBJ): %.o:%.c so_long.h
	$(CC) $(FLAGS) -c $<  -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean