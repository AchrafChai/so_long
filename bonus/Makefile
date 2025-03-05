SRC = so_long_bonus.c so_long_utils_bonus.c ft_map_bonus.c ft_map_utils_bonus.c ft_path_bonus.c ft_game_bonus.c ft_game_utils_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

NAME = so_long
CC = cc
# FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} $^ -Lmlx -lmlx -lXext -lX11 -lm -g -o $@

$(OBJ): %.o:%.c so_long_bonus.h
	$(CC) $(FLAGS) -c $<  -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean