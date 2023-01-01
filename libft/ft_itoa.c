/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:29:09 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/01 00:45:19 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	location_num(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		if (n == 0)
			return (i);
		i++;
		n = n / 10;
	}
	return (i);
}

static void	reverse(char *str)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	if (str[i] == '-')
		i++;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*p;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	p = malloc((location_num(n) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	if (n < 0)
	{
		p[i] = '-';
		n = -n;
		i++;
	}
	while (n)
	{
		p[i++] = n % 10 + 48;
		n = n / 10;
	}
	p[i] = 0;
	reverse(p);
	return (p);
}
