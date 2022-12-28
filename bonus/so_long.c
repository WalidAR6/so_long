/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:52:19 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/28 18:07:48 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_len(int first_line_len, char *get_lines)
{
	if (get_lines[ft_strlen(get_lines) - 1] != '\n')
	{
		if (ft_strlen(get_lines) != (size_t)first_line_len - 1)
		{
			ft_putstr_fd("Error not the same len !\n", 2);
			exit(1);
		}
	}
	else
	{
		if (ft_strlen(get_lines) != (size_t)first_line_len)
		{
			ft_putstr_fd("Error not the same len !\n", 2);
			exit(1);
		}
	}
}

char	*map_len(int fd, char **lines)
{
	int		n_l;
	int		first_line_len;
	char	*get_lines;

	n_l = -1;
	*lines = NULL;
	while (1)
	{
		get_lines = get_next_line(fd);
		if (get_lines == NULL)
			break ;
		if (++n_l == 0)
			first_line_len = ft_strlen(get_lines);
		else
			n_l++;
		check_map_len(first_line_len, get_lines);
		*lines = ft_strjoin(*lines, get_lines);
	}
	return (*lines);
}

char	**read_map(int fd, t_vars *vars)
{
	char	*lines;
	char	**matrix;

	lines = map_len(fd, &lines);
	if (!lines)
	{
		ft_putstr_fd("empty map\n", 2);
		exit(1);
	}
	map_ghost(vars, lines);
	map_elements(vars, lines);
	matrix = ft_split(lines, '\n');
	vars->height = map_height(matrix);
	surrounded_map(matrix);
	look_in_sides(vars, matrix);
	return (free(lines), matrix);
}

void	check_main(char *av)
{
	int		fd;
	void	*copy;
	t_vars	vars;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Invalid file\n", 2);
		exit(1);
	}
	vars.matrix = read_map(fd, &vars);
	copy = copy_map(&vars);
	vars.x = get_x_index(vars.matrix, 'P');
	vars.y = get_y_index(vars.matrix, 'P');
	find_path(&vars, vars.x, vars.y);
	if (check_condition(&vars) == 1)
	{
		ft_putstr_fd("error path not valid\n", 2);
		exit(1);
	}
	vars.moves_counter = 0;
	game_start(&vars);
	free(copy);
	close(fd);
}

int	main(int ac, char **av)
{
	int	i;

	i = ft_strlen(av[1]) - 1;
	if (ac == 2)
	{
		if (av[1][i] != 'r' || av[1][i - 1] != 'e' ||
			av[1][i - 2] != 'b' || av[1][i - 3] != '.')
		{
			ft_putstr_fd("invalid file name\n", 2);
			exit(1);
		}
	}
	check_main(av[1]);
	return (0);
}
