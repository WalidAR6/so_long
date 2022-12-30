/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:11:40 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/30 19:45:53 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
    int mok;
    int i;
    int j;
    int l;
    t_ghost *head;

    mok = 0;
    l = how_much_g(vars);
    head = vars->ghost;
    head->x = malloc(sizeof(int)* l);
    head->y = malloc(sizeof(int)* l);
    if(!head->x || !head->y)
        exit(1);
    i = 1;
    while (vars->matrix[i])
    {
        j = 1;
        while (vars->matrix[i][j])
        {
            if (vars->matrix[i][j] == 'G')
            {
                head->x[mok] = i;
                head->y[mok] = j;
                mok++;
            }
            j++;
        }
        i++;
    }
}