/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 23:28:15 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/26 22:44:50 by waraissi         ###   ########.fr       */
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
		printf("Not the same lenght\n");
		exit(1);
	}
	while (i < map_height(matrix))
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][0] == '0' || matrix[i][len] == '0')
				return (write(2, "Error found 0 in borders", 25), NULL);
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
		write(1, "Error (found 0)\n", 17);
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
			printf("Error found other char");
			exit(1);
		}
	}
	if (vars->data.p != 1 || vars->data.e != 1 || vars->data.c < 1)
	{
		write(2, "Error ok\n", 10);
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
