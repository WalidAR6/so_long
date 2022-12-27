/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:24:53 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/27 14:31:03 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_vars *par)
{
	par->d_p = par->p_r;
	if (par->matrix[par->y][par->x + 1] == 'E' && par->data.c == 0)
	{
		put_game_won();
		exit(1);
	}
	else if (par->matrix[par->y][par->x + 1] != '1' &&
		par->matrix[par->y][par->x + 1] != 'E')
	{
		par->moves_counter++;
		if (par->matrix[par->y][par->x + 1] == 'C')
			par->data.c = par->data.c - 1;
		par->matrix[par->y][par->x] = '0';
		par->matrix[par->y][par->x + 1] = 'P';
		par->x++;
	}
	ft_putnbr_fd(par->moves_counter, 1);
	write(1, "\n", 1);
}

void	move_left(t_vars *par)
{
	par->d_p = par->p_l;
	if (par->matrix[par->y][par->x - 1] == 'E' && par->data.c == 0)
	{
		put_game_won();
		exit(1);
	}
	else if (par->matrix[par->y][par->x - 1] != '1' &&
		par->matrix[par->y][par->x - 1] != 'E')
	{
		par->moves_counter++;
		if (par->matrix[par->y][par->x - 1] == 'C')
			par->data.c = par->data.c - 1;
		par->matrix[par->y][par->x] = '0';
		par->matrix[par->y][par->x - 1] = 'P';
		par->x--;
	}
	ft_putnbr_fd(par->moves_counter, 1);
	write(1, "\n", 1);
}

void	move_up(t_vars *par)
{
	par->d_p = par->p_u;
	if (par->matrix[par->y - 1][par->x] == 'E' && par->data.c == 0)
	{
		put_game_won();
		exit(1);
	}
	else if (par->matrix[par->y - 1][par->x] != '1' &&
		par->matrix[par->y - 1][par->x] != 'E')
	{
		par->moves_counter++;
		if (par->matrix[par->y - 1][par->x] == 'C')
			par->data.c = par->data.c - 1;
		par->matrix[par->y][par->x] = '0';
		par->matrix[par->y - 1][par->x] = 'P';
		par->y--;
	}
	ft_putnbr_fd(par->moves_counter, 1);
	write(1, "\n", 1);
}

void	move_down(t_vars *par)
{
	par->d_p = par->p_d;
	if (par->matrix[par->y + 1][par->x] == 'E' && par->data.c == 0)
	{
		put_game_won();
		exit(1);
	}
	else if (par->matrix[par->y + 1][par->x] != '1' &&
		par->matrix[par->y + 1][par->x] != 'E')
	{
		par->moves_counter++;
		if (par->matrix[par->y + 1][par->x] == 'C')
			par->data.c = par->data.c - 1;
		par->matrix[par->y][par->x] = '0';
		par->matrix[par->y + 1][par->x] = 'P';
		par->y++;
	}
	ft_putnbr_fd(par->moves_counter, 1);
	write(1, "\n", 1);
}

void	window_exit(t_vars *par)
{
	ft_putstr_fd("Exit\n", 1);
	mlx_destroy_window(par->ptr, par->win);
	exit(1);
}
