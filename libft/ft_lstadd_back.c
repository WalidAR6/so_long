/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:01:43 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/30 23:01:20 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_ghost **lst, t_ghost *new)
{
	t_ghost	*p;

	if (!lst || !new)
		return ;
	p = ft_lstlast(*lst);
	if (!p)
		ft_lstadd_front(lst, new);
	else
		p->next = new;
}
