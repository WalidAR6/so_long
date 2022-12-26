/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:24:53 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/26 22:36:14 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (par->matrix[par->y][par->x + 1] == 'C')
			par->data.c = par->data.c - 1;
		par->matrix[par->y][par->x] = '0';
		par->matrix[par->y][par->x + 1] = 'P';
		par->x++;
	}
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
		if (par->matrix[par->y][par->x - 1] == 'C')
			par->data.c = par->data.c - 1;
		par->matrix[par->y][par->x] = '0';
		par->matrix[par->y][par->x - 1] = 'P';
		par->x--;
	}
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
		if (par->matrix[par->y - 1][par->x] == 'C')
			par->data.c = par->data.c - 1;
		par->matrix[par->y][par->x] = '0';
		par->matrix[par->y - 1][par->x] = 'P';
		par->y--;
	}
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
		if (par->matrix[par->y + 1][par->x] == 'C')
			par->data.c = par->data.c - 1;
		par->matrix[par->y][par->x] = '0';
		par->matrix[par->y + 1][par->x] = 'P';
		par->y++;
	}
}

void	window_exit(t_vars *par)
{
	printf("Exit\n");
	mlx_destroy_window(par->ptr, par->win);
	exit(1);
}
