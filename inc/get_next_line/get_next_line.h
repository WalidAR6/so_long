/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:11:41 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/12 17:12:10 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>


size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t n);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		is_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		get_index(char	*str);
char	*before_newline(char *str);
char	*after_newline(char *str);
char	*get_next_line(int fd);

#endif