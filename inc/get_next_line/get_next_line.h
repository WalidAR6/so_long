/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:11:41 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/26 18:32:51 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

char	*ft_strjoin_and_free(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		is_newline(char *str);
int		get_index(char	*str);
char	*before_newline(char *str);
char	*after_newline(char *str);
char	*get_next_line(int fd);

#endif