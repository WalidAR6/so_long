/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:17:31 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/30 23:01:27 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ghost	*ft_lstnew(int *x, int *y)
{
	t_ghost	*p;

	p = malloc(sizeof(t_ghost));
	if (!p)
		return (NULL);
	p->x = x;
	p->y = y;
	p->next = NULL;
	return (p);
}
