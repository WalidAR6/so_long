/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:47:03 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/30 20:06:27 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_x_index(char **matrix, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (++j < ft_strlen(matrix[i]) - 1)
			if (matrix[i][j] == c)
				return (j);
		i++;
	}
	return (0);
}

int	get_y_index(char **matrix, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (++j < ft_strlen(matrix[i]) - 1)
			if (matrix[i][j] == c)
				return (i);
		i++;
	}
	return (0);
}

int	map_height(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	same_lenght(char **matrix)
{
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(matrix[0]);
	i = 1;
	j = 0;
	while (matrix[i])
	{
		if (ft_strlen(matrix[i]) != len)
			j++;
		i++;
	}
	return (j);
}

void	printf_score(t_vars *vars)
{
	char	*moves;

	moves = ft_itoa(vars->moves_counter);
	mlx_string_put(vars->ptr, vars->win,
		(ft_strlen(vars->matrix[0]) * vars->width) / 2 + 32,
		(map_height(vars->matrix) * vars->height) + 64, 0x0094FF, moves);
	mlx_string_put(vars->ptr, vars->win,
		(ft_strlen(vars->matrix[0]) * vars->width) / 2 + 16,
		(map_height(vars->matrix) * vars->height) + 32, 0x0094FF, "moves");
}
