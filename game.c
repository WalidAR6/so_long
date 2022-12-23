/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:14:29 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/23 18:32:23 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int fill_map(t_vars *infos)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (infos->matrix[i])
    {
        j = 0;
        while (infos->matrix[i][j])
        {
            if (infos->matrix[i][j] == '1')
                mlx_put_image_to_window(infos->ptr, infos->win, infos->wall, j * infos->width, i * infos->width);
            else if (infos->matrix[i][j] == 'P')
                mlx_put_image_to_window(infos->ptr, infos->win, infos->default_player, j * infos->width, i * infos->width);
            else if (infos->matrix[i][j] == 'C')
                mlx_put_image_to_window(infos->ptr, infos->win, infos->food, j * infos->width, i * infos->width);
            else if (infos->matrix[i][j] == 'E')
            {
                if (infos->data.C != 0)
                    mlx_put_image_to_window(infos->ptr, infos->win, infos->door_closed, j * infos->width, i * infos->width);
                else
                    mlx_put_image_to_window(infos->ptr, infos->win, infos->door_open, j * infos->width, i * infos->width);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int key_hook(int keycode, t_vars *var)
{
    mlx_clear_window(var->ptr,var->win);
	if (keycode == KEY_RIGHT)
        move_right(var);
    else if (keycode == KEY_LEFT)
        move_left(var);
    else if (keycode == KEY_UP)
        move_up(var);
    else if (keycode == KEY_DOWN)
        move_down(var);
    else if (keycode == KEY_ESC)
        window_exit(var);
    fill_map(var);
	return (0);
}

void game_start(t_vars *params)
{
    params->ptr = mlx_init();
    params->wall = mlx_xpm_file_to_image(params->ptr, "./textures/wall.xpm", &params->width, &params->height);
    params->default_player = mlx_xpm_file_to_image(params->ptr, "./textures/player/default_player.xpm", &params->width, &params->height);
    params->player_right = mlx_xpm_file_to_image(params->ptr, "./textures/player/default_player.xpm", &params->width, &params->height);
    params->player_up = mlx_xpm_file_to_image(params->ptr, "./textures/player/player_up.xpm", &params->width, &params->height);
    params->player_down = mlx_xpm_file_to_image(params->ptr, "./textures/player/player_down.xpm", &params->width, &params->height);
    params->player_left = mlx_xpm_file_to_image(params->ptr, "./textures/player/player_left.xpm", &params->width, &params->height);
    params->food = mlx_xpm_file_to_image(params->ptr, "./textures/food.xpm", &params->width, &params->height);
    params->door_closed = mlx_xpm_file_to_image(params->ptr, "./textures/doors/door_closed.xpm", &params->width, &params->height);
    params->door_open = mlx_xpm_file_to_image(params->ptr, "./textures/doors/door_open.xpm", &params->width, &params->height);
    params->win = mlx_new_window(params->ptr, ft_strlen(params->matrix[0]) * params->width, map_height(params->matrix) * params->height, "so_long");
    fill_map(params);
    mlx_hook(params->win, 2, 0, key_hook, params);
    mlx_loop(params->ptr);
}