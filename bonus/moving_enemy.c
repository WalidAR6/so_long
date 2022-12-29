/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:27:02 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/29 17:17:56 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    get_ghost_index(t_vars *vars)
{
    vars->x_g = get_x_index(vars->matrix, 'G');
    vars->y_g = get_y_index(vars->matrix, 'G');
}

int    move_enemy(t_vars *vars, int x, int y)
{
    static int tr = 0;
    static int i = 1;
    mlx_clear_window(vars->ptr, vars->win);
    x = vars->y_g;
    y = vars->x_g;
    if (tr == 10)
    {
        if (vars->matrix[x][y + i] == '1' || vars->matrix[x][y - i] == '1'
            || vars->matrix[x][y + i] == 'C' || vars->matrix[x][y - i] == 'C'
            || vars->matrix[x][y + i] == 'E' || vars->matrix[x][y - i] == 'E')
            i *= -1;
        if (vars->matrix[x][y + i] != 'C' && vars->matrix[x][y + i] != 'E'
                && vars->matrix[x][y + i] != '1')
        {
            if (vars->matrix[x][y + i] == 'P')
                put_game_lost();
            vars->matrix[x][y + i] = 'G';
            vars->matrix[x][y] = '0';
            vars->y_g = x;
            vars->x_g = y + i;
        }
        tr = 0;
    }
    tr++;
    fill_map(vars);
    return (0);
}