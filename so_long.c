/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:52:19 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/23 16:29:26 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_height(char **matrix)
{
    int i;

    i = 0;
    while (matrix[i])
        i++;
    return (i);
}

char **surrounded_map(char **matrix)
{
    int i = 0;
    int j = 0;
    int len = ft_strlen(matrix[i]) - 1;
    while (i <  map_height(matrix))
    {
        j = 0;
        while (matrix[i][j])
        {
            if (matrix[i][0] == '0' || matrix[i][len] == '0')
            {
                printf("Error found 0 in borders");
                exit(1);
            }          
            j++;
        }
        i++;
    }
    return (matrix);
}

int same_lenght(char **matrix)
{
    size_t len;
    int i;
    int j;

    len = ft_strlen(matrix[0]);
    i = 1;
    j = 0;
    while (matrix[i])
    {
        if (ft_strlen(matrix[i]) != len)
            j++;
        i++;
    }
    return (j);
}

char **read_map(int fd, t_vars *vars)
{
    char *get_lines;
    char *lines;
    char **matrix;
    int i;
    int n_l;
    int first_line_len;

    i = 0;
    n_l = 0;
    lines = NULL;
    vars->data.C = 0;
    vars->data.E = 0;
    vars->data.P = 0;
    while (1)
    {
        get_lines = get_next_line(fd);
        if (get_lines == NULL)
            break;
        if (n_l == 0)
        {
            first_line_len = ft_strlen(get_lines);
            n_l++;
        }
        else
            n_l++;
        if (get_lines[ft_strlen(get_lines) - 1] != '\n')
        {
            if (ft_strlen(get_lines) != (size_t)first_line_len - 1)
            {
                printf("not same len\n");
                exit(1);
            }
        }
        else
        {
            if (ft_strlen(get_lines) != (size_t)first_line_len)
            {
                printf("not same len\n");
                exit(1);
            }
        }
        lines = ft_strjoin(lines,get_lines);
    }
    while (lines[i])
    {
        if (lines[i] == 'C')
            vars->data.C = vars->data.C + 1;
        else if (lines[i] == 'P')
            vars->data.P = vars->data.P + 1;
        else if (lines[i] == 'E')
            vars->data.E = vars->data.E + 1;
        else if (!ft_strchr("10ECP\n", lines[i]))
        {
            printf("Error found other char");
            exit(1);
        }
        i++;
    }
    if (vars->data.P != 1 || vars->data.E != 1 || vars->data.C < 1)
    {
        write(2, "Error ok\n",10);
        exit(1);
    }
    matrix = ft_split(lines,'\n');
    if (same_lenght(matrix) != 0)
    {
        printf("Not the same lenght\n");
        exit(1);
    }
    surrounded_map(matrix);
    vars->data.height = map_height(matrix);
    if(ft_strchr(matrix[0],'0') || ft_strchr(matrix[vars->data.height - 1],'0'))
        return (write(1, "Error (found 0)\n", 17), NULL);
    return (matrix);
}

int main()
{
    int fd;
    t_vars  vars;
    
    fd = open("./maps/map.ber",O_RDONLY);
    vars.matrix = read_map(fd, &vars);
    vars.x = get_x_index(vars.matrix, 'P');
    vars.y = get_y_index(vars.matrix, 'P');
    game_start(&vars);
    close(fd);
}