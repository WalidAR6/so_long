/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:32:42 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/27 14:29:25 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_path(t_vars *vars, int x, int y)
{
	if (vars->matrix_backup[y][x] == '1' ||
		vars->matrix_backup[y][x] == 'a' || vars->matrix_backup[y][x] == 'E')
		return ;
	vars->matrix_backup[y][x] = 'a';
	find_path(vars, x, y + 1);
	find_path(vars, x, y - 1);
	find_path(vars, x + 1, y);
	find_path(vars, x - 1, y);
}

int	check_condition(t_vars *vars)
{
	int	i;
	int	j;

	i = 1;
	while (vars->matrix_backup[i])
	{
		j = 1;
		while (vars->matrix_backup[i][j])
		{
			if (vars->matrix_backup[i][j] == 'C')
				return (1);
			if (vars->matrix_backup[i][j] == 'E')
			{
				if (vars->matrix_backup[i + 1][j] != 'a' &&
					vars->matrix_backup[i - 1][j] != 'a' &&
					vars->matrix_backup[i][j + 1] != 'a' &&
					vars->matrix_backup[i][j - 1] != 'a')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
