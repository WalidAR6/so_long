/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:51:54 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/30 19:46:08 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    sprite_animation(t_vars *vars)
{
    static int i = 0;
    static int pr = 0;
    int j;

    j = 0;
    mlx_clear_window(vars->ptr, vars->win);
    if(pr == 20)
    {
        vars->food = vars->animate[i % 3];
        i++;
        pr = 0;
    }
    pr++;
    return (0);
}