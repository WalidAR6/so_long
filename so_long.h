/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:37:06 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/27 14:31:57 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

# define KEY_UP 13
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_DOWN 1
# define KEY_ESC 53

typedef struct s_data
{
	int	p;
	int	c;
	int	e;
	int	width;
	int	height;
}				t_data;

typedef struct s_vars
{
	void	*ptr;
	void	*win;
	void	*wall;
	void	*d_p;
	void	*p_r;
	void	*p_u;
	void	*p_d;
	void	*p_l;
	void	*food;
	void	*d_o;
	void	*d_c;
	int		width;
	int		height;
	int		x;
	int		y;
	char	**matrix;
	char	**matrix_backup;
	t_data	data;
	int		moves_counter;
}			t_vars;

char	**read_map(int fd, t_vars *vars);
int		same_lenght(char **matrix);
char	**surrounded_map(char **matrix);
int		map_height(char **matrix);
void	game_start(t_vars *params);
int		get_x_index(char **matrix, char c);
int		get_y_index(char **matrix, char c);
void	move_right(t_vars *par);
void	move_left(t_vars *par);
void	move_up(t_vars *par);
void	move_down(t_vars *par);
void	window_exit(t_vars *par);
void	find_path(t_vars *vars, int x, int y);
int		check_condition(t_vars *vars);
int		map_height(char **matrix);
int		same_lenght(char **matrix);
void	look_in_sides(t_vars *vars, char **matrix);
void	map_elements(t_vars *vars, char *lines);
void	check_map_len(int first_line_len, char *get_lines);
char	*map_len(int fd, char **lines);
char	**read_map(int fd, t_vars *vars);
void	*copy_map(t_vars *vars);
void	put_game_won(void);

#endif