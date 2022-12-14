/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:27:02 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/01 15:44:07 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_ghost_index(t_vars *vars)
{
	vars->x_g = get_x_index(vars->matrix, 'G');
	vars->y_g = get_y_index(vars->matrix, 'G');
}

void	movement(t_vars *vars, int mok, int i)
{
	int	x;
	int	y;
	int	l;

	l = how_much_g(vars);
	x = vars->ghost->x[mok % l];
	y = vars->ghost->y[mok % l];
	if (vars->matrix[x][y + i] != 'C' && vars->matrix[x][y + i] != 'E'
			&& vars->matrix[x][y + i] != '1' && vars->matrix[x][y + i] != 'G')
	{
		if (vars->matrix[x][y + i] == 'P')
			put_game_lost();
		vars->matrix[x][y + i] = 'G';
		vars->matrix[x][y] = '0';
		vars->ghost->y[mok % l] = x;
		vars->ghost->x[mok % l] = y + i;
	}
}

int	move_enemy(t_vars *vars, int x, int y)
{
	static int	tr = 0;
	static int	i = 1;
	static int	mok = 0;
	int			l;

	l = how_much_g(vars);
	sprite_animation(vars);
	get_position(vars);
	if (tr == 10)
	{
		x = vars->ghost->x[mok % l];
		y = vars->ghost->y[mok % l];
		if (vars->matrix[x][y + i] == '1' || vars->matrix[x][y - i] == '1'
			|| vars->matrix[x][y + i] == 'C' || vars->matrix[x][y - i] == 'C'
			|| vars->matrix[x][y + i] == 'E' || vars->matrix[x][y - i] == 'E'
			|| vars->matrix[x][y + i] == 'G' || vars->matrix[x][y - i] == 'G')
		i *= -1;
		movement(vars, mok, i);
		tr = 0;
		mok++;
	}
	tr++;
	fill_map(vars);
	return (free(vars->ghost->x), free(vars->ghost->y), 0);
}
