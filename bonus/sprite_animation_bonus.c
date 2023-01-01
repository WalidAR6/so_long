/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:51:54 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/31 21:38:43 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_animation(t_vars *vars)
{
	static int	i = 0;
	static int	pr = 0;
	int			j;

	j = 0;
	mlx_clear_window(vars->ptr, vars->win);
	if (pr == 20)
	{
		vars->food = vars->animate[i % 3];
		i++;
		pr = 0;
	}
	pr++;
}
