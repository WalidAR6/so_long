/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:47:03 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/21 16:31:04 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_x_index(char **matrix, char c)
{
    size_t i;
    size_t j;

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

int get_y_index(char **matrix, char c)
{
    size_t i;
    size_t j;

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