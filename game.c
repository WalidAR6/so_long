/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:14:29 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/20 20:40:49 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int fill_map(char **matrix, t_vars *infos)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (matrix[i])
    {
        j = 0;
        while (matrix[i][j])
        {
            if (matrix[i][j] == '1')
                mlx_put_image_to_window(infos->ptr, infos->win, infos->wall, j * infos->width, i * infos->width);
            else
                mlx_put_image_to_window(infos->ptr, infos->win, infos->floor, j * infos->width, i * infos->width);
            j++;
        }
        i++;
    }
    return (0);
}

void game_start(char **matrix)
{
    t_vars params;
    
    params.ptr = mlx_init();
    params.wall = mlx_xpm_file_to_image(params.ptr, "./textures/wall.xpm", &params.width, &params.height);
    params.floor = mlx_xpm_file_to_image(params.ptr, "./textures/gazon.xpm", &params.width, &params.height);
    params.win = mlx_new_window(params.ptr, ft_strlen(matrix[0]) * params.width, map_height(matrix) * params.height, "so_long");
    mlx_put_image_to_window(params.ptr, params.win, params.wall, 0, 0);
    fill_map(matrix, &params);
    mlx_loop(params.ptr);
}