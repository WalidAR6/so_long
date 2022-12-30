/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:46:59 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/30 19:29:21 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_game_won(void)
{
	ft_putstr_fd(" _   _    __        __   ___    _   _ \n", 1);
	ft_putstr_fd("| | | |   \\ \\      / /  / _ \\  | \\ | |\n", 1);
	ft_putstr_fd("| | | |    \\ \\ /\\ / /  | | | | |  \\| |\n", 1);
	ft_putstr_fd("| |_| |     \\ V  V /   | |_| | | |\\  |\n", 1);
	ft_putstr_fd(" \\___/       \\_/\\_/     \\___/  |_| \\_|\n", 1);
}

int	miclose(t_vars	*param)
{
	mlx_destroy_window(param->ptr, param->win);
	exit(0);
	return (0);
}
