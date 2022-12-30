/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:14:29 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/30 15:50:09 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	textures(t_vars *var, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(var->ptr, var->win,
			var->wall, j * var->width, i * var->width);
	else if (c == 'P')
		mlx_put_image_to_window(var->ptr, var->win,
			var->d_p, j * var->width, i * var->width);
	else if (c == 'C')
		mlx_put_image_to_window(var->ptr, var->win,
			var->food, j * var->width, i * var->width);
	else if (c == 'E')
	{
		if (var->data.c != 0)
			mlx_put_image_to_window(var->ptr, var->win,
				var->d_c, j * var->width, i * var->width);
		else
			mlx_put_image_to_window(var->ptr, var->win,
				var->d_o, j * var->width, i * var->width);
	}
	else if (c == 'G')
	{
		mlx_put_image_to_window(var->ptr, var->win,
			var->enm, j * var->width, i * var->width);
	}
}

int	fill_map(t_vars *infos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (infos->matrix[i])
	{
		j = 0;
		while (infos->matrix[i][j])
		{
			textures(infos, infos->matrix[i][j], i, j);
			j++;
		}
		i++;
	}
	printf_score(infos);
	return (0);
}

int	key_hook(int keycode, t_vars *var)
{
	mlx_clear_window(var->ptr, var->win);
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

void	start_helper(t_vars *params)
{
	if (!params->wall || !params->d_p || !params->p_r || !params->p_u
		|| !params->p_d || !params->p_l || !params->food || !params->d_c
		|| !params->d_o || !params->enm || !params->ptr)
	{
		printf("Error textures\n");
		exit(1);
	}
	params->win = mlx_new_window(params->ptr,
			ft_strlen(params->matrix[0]) * params->width,
			map_height(params->matrix) * params->height + 128, "so_long");
	fill_map(params);
	get_ghost_index(params);
	sprite_texture(params);
	mlx_hook(params->win, 2, 0, key_hook, params);
	mlx_loop_hook(params->ptr, move_enemy, params);
	mlx_loop(params->ptr);
}

void	game_start(t_vars *params)
{
	params->ptr = mlx_init();
	params->wall = mlx_xpm_file_to_image(params->ptr,
			"./textures/wall.xpm", &params->width, &params->height);
	params->d_p = mlx_xpm_file_to_image(params->ptr,
			"./textures/d_p.xpm", &params->width, &params->height);
	params->p_r = mlx_xpm_file_to_image(params->ptr,
			"./textures/d_p.xpm", &params->width, &params->height);
	params->p_u = mlx_xpm_file_to_image(params->ptr,
			"./textures/p_u.xpm", &params->width, &params->height);
	params->p_d = mlx_xpm_file_to_image(params->ptr,
			"./textures/p_d.xpm", &params->width, &params->height);
	params->p_l = mlx_xpm_file_to_image(params->ptr,
			"./textures/p_l.xpm", &params->width, &params->height);
	params->food = mlx_xpm_file_to_image(params->ptr,
			"./textures/food.xpm", &params->width, &params->height);
	params->d_c = mlx_xpm_file_to_image(params->ptr,
			"./textures/d_c.xpm", &params->width, &params->height);
	params->d_o = mlx_xpm_file_to_image(params->ptr,
			"./textures/d_o.xpm", &params->width, &params->height);
	params->enm = mlx_xpm_file_to_image(params->ptr,
			"./textures/enemy.xpm", &params->width, &params->height);
	start_helper(params);
}
