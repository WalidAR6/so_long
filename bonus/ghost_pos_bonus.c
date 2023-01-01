/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_pos_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:11:40 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/01 02:11:04 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	how_much_g(t_vars *vars)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (vars->matrix[i])
	{
		j = 1;
		while (vars->matrix[i][j])
		{
			if (vars->matrix[i][j] == 'G')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	store(t_vars *vars)
{
	int		mok;
	int		i;
	int		j;

	mok = 0;
	i = 1;
	while (vars->matrix[i])
	{
		j = 1;
		while (vars->matrix[i][j])
		{
			if (vars->matrix[i][j] == 'G')
			{
				vars->ghost->x[mok] = i;
				vars->ghost->y[mok] = j;
				mok++;
			}
			j++;
		}
		i++;
	}
}

void	get_position(t_vars *vars)
{
	int		l;

	l = how_much_g(vars);
	vars->ghost->x = malloc(sizeof(int) * l);
	vars->ghost->y = malloc(sizeof(int) * l);
	store(vars);
}
