/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:11:40 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/30 02:29:56 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int    how_much_g(t_vars *vars)
{
    int i;
    int j;
    int count;
    
    i = 1;
    count = 0;
    while (vars->matrix[i])
    {
        j = 1;
        while (vars->matrix[i][j])
        {
            if (vars->matrix[i][j] == 'G')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

void    get_position(t_vars *vars)
{
    int i;
    int j;
    t_ghost *new;
    
    i = 1;
    new = NULL;
    while (vars->matrix[i])
    {
        j = 1;
        while (vars->matrix[i][j])
        {
            if (vars->matrix[i][j] == 'G')
            {
                vars->ghost = ft_lstnew(j, i);
                ft_lstadd_back(&vars->ghost, new);
            }
            j++;
        }
        i++;
    }
}