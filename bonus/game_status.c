/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:34:23 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/27 22:04:13 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_game_won(void)
{
	ft_putstr_fd(" _   _    __        __   ___    _   _ \n", 1);
	ft_putstr_fd("| | | |   \\ \\      / /  / _ \\  | \\ | |\n", 1);
	ft_putstr_fd("| | | |    \\ \\ /\\ / /  | | | | |  \\| |\n", 1);
	ft_putstr_fd("| |_| |     \\ V  V /   | |_| | | |\\  |\n", 1);
	ft_putstr_fd(" \\___/       \\_/\\_/     \\___/  |_| \\_|\n", 1);
}

void    put_game_lost(void)
{
    ft_putstr_fd("oooo  oooo oooooo        ooooooo    oooooooo8  ooooooooooo \n", 1);
    ft_putstr_fd(" 888    88  888        o888   888o 888         88  888  88 \n", 1);
    ft_putstr_fd(" 888    88  888        888     888  888oooooo      888     \n", 1);
    ft_putstr_fd(" 888    88  888      o 888o   o888         888     888     \n", 1);
    ft_putstr_fd("  888oo88  o888ooooo88   88ooo88   o88oooo888     o888o    \n", 1);
    exit(1);
}