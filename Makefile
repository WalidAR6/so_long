CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = solong

NAMEBNS = solong_bonus

SRC = Mandatory/so_long.c\
		Mandatory/game.c\
		Mandatory/utils.c\
		Mandatory/key_hooks.c\
		Mandatory/valide_path.c\
		Mandatory/so_long_utils.c\
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


BSRC = bonus/so_long.c\
		bonus/game.c\
		bonus/utils.c\
		bonus/key_hooks.c\
		bonus/valide_path.c\
		bonus/so_long_utils.c\
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

BOBJ = ${BSRC:.c=.o}

all: ${NAME}

bonus: ${NAMEBNS}

%.o: %.c
	${CC} ${FLAGS} -Imlx -c $< -o $@ -g

${NAME}: ${BOBJ} so_long.h
	${CC} ${BOBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME} -g

${NAMEBNS}: ${OBJ} so_long.h
	${CC} ${OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAMEBNS} -g

clean:
	rm -f ${OBJ} ${BOBJ}

fclean:
	rm -f ${OBJ} ${BOBJ} ${NAME} ${NAMEBNS}

re: fclean all bonus