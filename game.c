/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:14:29 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/19 23:14:49 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void game_start()
{
    t_infos *params;

    params = malloc(sizeof(t_infos));
    if(!params)
        return ;
    params->ptr = mlx_init();
    params->win = mlx_new_window(params->ptr,500,500,"so_long");
    mlx_loop(params->ptr);
}