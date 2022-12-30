/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:28:56 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/30 23:02:03 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ghost
{
	int				*x;
	int				*y;
	struct s_ghost	*next;
}				t_ghost;

char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	**ft_split(char *s, char c);
size_t	ft_strlcpy(char *dst, char *src, size_t n);
char	*ft_strdup(char *str);
char	*ft_strrchr(char *str, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);

t_ghost	*ft_lstnew(int *x, int *y);
t_ghost	*ft_lstlast(t_ghost *lst);
void	ft_lstadd_front(t_ghost **lst, t_ghost *new);
void	ft_lstadd_back(t_ghost **lst, t_ghost *new);

#endif