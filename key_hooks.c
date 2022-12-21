/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:24:53 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/21 18:44:01 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_right(t_vars *par)
{
    if (par->matrix[par->y][par->x + 1] != '1')
    {
        par->matrix[par->y][par->x] = '0';
        par->matrix[par->y][par->x + 1] = 'P';
        par->x++;
        printf("right\n");
    }
}

void    move_left(t_vars *par)
{
    if (par->matrix[par->y][par->x - 1] != '1')
    {
        par->matrix[par->y][par->x] = '0';
        par->matrix[par->y][par->x - 1] = 'P';
        par->x--;
        printf("left\n");
    }
}

void    move_up(t_vars  *par)
{
    if (par->matrix[par->y - 1][par->x] != '1')
    {
        par->matrix[par->y][par->x] = '0';
        par->matrix[par->y - 1][par->x] = 'P';
        par->y--;
        printf("up\n");
    }
}

void    move_down(t_vars *par)
{
    if (par->matrix[par->y + 1][par->x] != '1')
    {
        par->matrix[par->y][par->x] = '0';
        par->matrix[par->y + 1][par->x] = 'P';
        par->y++;
        printf("down\n");
    }
}

void    window_exit(t_vars *par)
{
    printf("Exit\n");
    mlx_destroy_window(par->ptr, par->win);
    exit(1);
}