CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = solong

NAMEBNS = solong_bonus

SRC = Mandatory/so_long.c\
		Mandatory/game.c\
		Mandatory/game_status.c\
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

BSRC = bonus/so_long_bonus.c\
		bonus/game_bonus.c\
		bonus/utils_bonus.c\
		bonus/key_hooks_bonus.c\
		bonus/valide_path_bonus.c\
		bonus/so_long_utils_bonus.c\
		bonus/check_ghost_bonus.c\
		bonus/game_status_bonus.c\
		bonus/moving_enemy_bonus.c\
		bonus/sprite_animation_bonus.c\
		bonus/sprite_texture_bonus.c\
		bonus/ghost_pos_bonus.c\
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
		libft/ft_strrchr.c\
		libft/ft_itoa.c\
		libft/ft_lstnew.c\
		libft/ft_lstlast.c\
		libft/ft_lstadd_back.c\
		libft/ft_lstadd_front.c

OBJ = ${SRC:.c=.o}

BOBJ = ${BSRC:.c=.o}

all: ${NAME}

bonus: ${NAMEBNS}

%.o: %.c
	${CC} ${FLAGS} -Imlx -c $< -o $@ -g

${NAME}: ${OBJ} Mandatory/so_long.h
	${CC} ${OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME} -g

${NAMEBNS}: ${BOBJ} bonus/so_long.h
	${CC} ${BOBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAMEBNS} -g

clean:
	rm -f ${OBJ} ${BOBJ}

fclean:
	rm -f ${OBJ} ${BOBJ} ${NAME} ${NAMEBNS}

re: fclean all bonus