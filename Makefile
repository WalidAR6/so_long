CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = solong

SRC = so_long.c\
		game.c\
		utils.c\
		key_hooks.c\
		valide_path.c\
		so_long_utils.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		libft/ft_strchr.c\
		libft/ft_strlen.c\
		libft/ft_strjoin.c\
		libft/ft_split.c\
		libft/ft_strlcpy.c\
		libft/ft_strdup.c\
		libft/ft_putchar_fd.c\
		libft/ft_putstr_fd.c\
		libft/ft_putnbr_fd.c\
		libft/ft_strrchr.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${FLAGS} -Imlx -c $< -o $@ -g

${NAME}: ${OBJ} so_long.h
	${CC} ${OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME} -g

clean:
	rm -f ${OBJ}

fclean:
	rm -f ${OBJ} ${NAME}

re: fclean all