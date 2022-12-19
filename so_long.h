/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:37:06 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/19 23:14:23 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <errno.h>
# include "inc/get_next_line/get_next_line.h"
# include "inc/libft/libft.h"

// # define KEY_UP 13
// # define KEY_LEFT 0
// # define KEY_RIGHT 2
// # define KEY_UP 1
// # define KEY_ESC 53

typedef struct	s_data   {
	int	P;
	int C;
	int E;
	int width;
	int height;
}				t_data;

typedef struct s_vars	{
	void *ptr;
	void *win;
}				t_infos;

char **read_map(int fd);
int same_lenght(char **matrix);
char **surrounded_map(char **matrix);
int map_height(char **matrix);
void game_start();

# endif