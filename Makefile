CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = solong

SRC = so_long.c\
		game.c\
		utils.c\
		key_hooks.c\
		valide_path.c\
		inc/get_next_line/get_next_line.c\
		inc/get_next_line/get_next_line_utils.c\
		inc/libft/ft_strchr.c\
		inc/libft/ft_strlen.c\
		inc/libft/ft_strjoin.c\
		inc/libft/ft_split.c\
		inc/libft/ft_strlcpy.c\
		inc/libft/ft_strdup.c\
		inc/libft/ft_strrchr.c


OBJ = ${SRC:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${FLAGS} -Imlx -c $< -o $@ -g

${NAME}: ${OBJ} so_long.h
	${CC} ${OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	rm -f ${OBJ}

fclean:
	rm -f ${OBJ} ${NAME}

re: fclean all