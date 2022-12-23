/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:24:53 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/23 18:32:51 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_right(t_vars *par)
{
    par->default_player = par->player_right;
    if (par->matrix[par->y][par->x + 1] == 'E' && par->data.C == 0)
    {
        printf("game over\n");
        exit(1);
    }
    else if (par->matrix[par->y][par->x + 1] != '1' && par->matrix[par->y][par->x + 1] != 'E')
    {
        if (par->matrix[par->y][par->x + 1] == 'C')
            par->data.C = par->data.C - 1;
        par->matrix[par->y][par->x] = '0';
        par->matrix[par->y][par->x + 1] = 'P';
        par->x++;
    }
}

void    move_left(t_vars *par)
{
    par->default_player = par->player_left;
    if (par->matrix[par->y][par->x - 1] == 'E' && par->data.C == 0)
    {
        printf("game over\n");
        exit(1);
    }
    else if (par->matrix[par->y][par->x - 1] != '1' && par->matrix[par->y][par->x - 1] != 'E')
    {
        if (par->matrix[par->y][par->x - 1] == 'C')
            par->data.C = par->data.C - 1;
        par->matrix[par->y][par->x] = '0';
        par->matrix[par->y][par->x - 1] = 'P';
        par->x--;
    }
}

void    move_up(t_vars  *par)
{
    par->default_player = par->player_up;
    if (par->matrix[par->y - 1][par->x] == 'E' && par->data.C == 0)
    {
        printf("game over\n");
        exit(1);
    }
    else if (par->matrix[par->y - 1][par->x] != '1' && par->matrix[par->y - 1][par->x] != 'E')
    {
        if (par->matrix[par->y - 1][par->x] == 'C')
            par->data.C = par->data.C - 1;
        par->matrix[par->y][par->x] = '0';
        par->matrix[par->y - 1][par->x] = 'P';
        par->y--;
    }
}

void    move_down(t_vars *par)
{
    par->default_player = par->player_down;
    if (par->matrix[par->y + 1][par->x] == 'E' && par->data.C == 0)
    {
        printf("game over\n");
        exit(1);
    }
    else if (par->matrix[par->y + 1][par->x] != '1' && par->matrix[par->y + 1][par->x] != 'E')
    {
        if (par->matrix[par->y + 1][par->x] == 'C')
            par->data.C = par->data.C - 1;
        par->matrix[par->y][par->x] = '0';
        par->matrix[par->y + 1][par->x] = 'P';
        par->y++;
    }
}

void    window_exit(t_vars *par)
{
    printf("Exit\n");
    mlx_destroy_window(par->ptr, par->win);
    exit(1);
}
