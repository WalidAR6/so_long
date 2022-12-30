/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 23:28:15 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/30 19:29:38 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**surrounded_map(char **matrix)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(matrix[i]) - 1;
	if (same_lenght(matrix) != 0)
	{
		ft_putstr_fd("Error Not the same lenght\n", 2);
		exit(1);
	}
	while (i < map_height(matrix))
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][0] == '0' || matrix[i][len] == '0')
				return (ft_putstr_fd("Error Not the same lenght\n", 2), NULL);
			j++;
		}
		i++;
	}
	return (matrix);
}

void	look_in_sides(t_vars *vars, char **matrix)
{
	if (ft_strchr(matrix[0], '0') || ft_strchr(matrix[vars->height - 1], '0'))
	{
		ft_putstr_fd("Error (found 0) in sides\n", 2);
		exit(1);
	}
}

void	map_elements(t_vars *vars, char *lines)
{
	int	i;

	i = 0;
	vars->data.c = 0;
	vars->data.p = 0;
	vars->data.e = 0;
	while (lines[i++])
	{
		if (lines[i] == 'C')
			vars->data.c = vars->data.c + 1;
		else if (lines[i] == 'P')
			vars->data.p = vars->data.p + 1;
		else if (lines[i] == 'E')
			vars->data.e = vars->data.e + 1;
		else if (!ft_strchr("10ECP\n", lines[i]))
		{
			ft_putstr_fd("Error found other char\n", 2);
			exit(1);
		}
	}
	if (vars->data.p != 1 || vars->data.e != 1 || vars->data.c < 1)
	{
		ft_putstr_fd("Error map element not valid\n", 2);
		exit(1);
	}
}

void	*copy_map(t_vars *vars)
{
	int	i;

	i = 0;
	vars->matrix_backup = malloc((vars->height + 1) * sizeof(char *));
	if (!vars->matrix_backup)
		return (NULL);
	while (i < vars->height)
	{
		vars->matrix_backup[i] = ft_strdup(vars->matrix[i]);
		i++;
	}
	vars->matrix_backup[i] = NULL;
	return (vars->matrix_backup);
}
