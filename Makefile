CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = solong

SRC = so_long.c\
		inc/get_next_line/get_next_line.c\
		inc/get_next_line/get_next_line_utils.c
		

OBJ = ${SRC:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${FLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	rm -f ${OBJ}

fclean:
	rm -f ${OBJ} ${NAME}