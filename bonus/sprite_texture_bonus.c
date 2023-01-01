/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_texture_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:17:56 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/01 16:02:40 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_texture(t_vars *vars)
{
	vars->animate = malloc(sizeof(void *) * 3);
	if (!vars->animate)
		return ;
	vars->animate[0] = mlx_xpm_file_to_image(vars->ptr,
			"./textures/food/food_2.xpm", &vars->width, &vars->height);
	vars->animate[1] = vars->food;
	vars->animate[2] = mlx_xpm_file_to_image(vars->ptr,
			"./textures/food/food_3.xpm", &vars->width, &vars->height);
	if (!vars->animate[0] || !vars->animate[1] || !vars->animate[2])
	{
		free(vars->animate);
		ft_putstr_fd("Error textures\n", 2);
	}
}
