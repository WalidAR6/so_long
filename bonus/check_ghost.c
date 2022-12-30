/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ghost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:07:59 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/30 19:45:44 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_ghost(t_vars *vars, char *lines)
{
	int	i;

	i = 0;
	vars->data.g = 0;
	while (lines[i])
	{
		if (lines[i] == 'G')
			vars->data.g++;
		i++;
	}
	if (vars->data.g < 1)
	{
		ft_putstr_fd("Error map element not valid\n", 2);
		exit(1);
	}
}
