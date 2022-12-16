/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:37:06 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/15 16:33:59 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <errno.h>
# include "inc/get_next_line/get_next_line.h"
# include "inc/libft/libft.h"

typedef struct	s_data   {
	int	P;
	int C;
	int E;
	int width;
	int height;
}				t_data;

# endif