/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:52:19 by waraissi          #+#    #+#             */
/*   Updated: 2022/12/25 23:15:30 by waraissi         ###   ########.fr       */
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

char **surrounded_map(char **matrix)
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    len = ft_strlen(matrix[i]) - 1;
    if (same_lenght(matrix) != 0)
    {
        printf("Not the same lenght\n");
        exit(1);
    }
    while (i <  map_height(matrix))
    {
        j = 0;
        while (matrix[i][j])
        {
            if (matrix[i][0] == '0' || matrix[i][len] == '0')
                return(write(2, "Error found 0 in borders", 25), NULL);
            j++;
        }
        i++;
    }
    return (matrix);
}

void    look_in_sides(t_vars *vars, char **matrix)
{
    if(ft_strchr(matrix[0],'0') || ft_strchr(matrix[vars->height - 1],'0'))
    {
        write(1, "Error (found 0)\n", 17);
        exit(1);
    }
}

void    map_elements(t_vars *vars,char *lines)
{
    int i;

    i = 0;
    vars->data.C = 0;
    vars->data.E = 0;
    vars->data.P = 0;
    while (lines[i++])
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
    }
    if (vars->data.P != 1 || vars->data.E != 1 || vars->data.C < 1)
    {
        write(2, "Error ok\n",10);
        exit(1);
    }
}

void    check_map_len(int first_line_len, char *get_lines)
{
    if (get_lines[ft_strlen(get_lines) - 1] != '\n')
    {
        if (ft_strlen(get_lines) != (size_t)first_line_len - 1)
        {
            write(2,"not the same len 1!\n",20);
            exit(1);
        }
    }
    else
    {
        if (ft_strlen(get_lines) != (size_t)first_line_len)
        {
            write(2,"not the same len !\n",20);
            exit(1);
        }
    }
}
char    *map_len(int fd, char **lines)
{
    int n_l;
    int first_line_len;
    char *get_lines;

    n_l = -1;
    *lines = NULL;
    while (1)
    {
        get_lines = get_next_line(fd);
        if (get_lines == NULL)
            break;
        if (++n_l == 0)
            first_line_len = ft_strlen(get_lines);
        else
            n_l++;
        check_map_len(first_line_len, get_lines);
        *lines = ft_strjoin(*lines,get_lines);
    }
    return (*lines);
}

char **read_map(int fd, t_vars *vars)
{
    char *lines;
    char **matrix;

    lines = map_len(fd, &lines);
    if (!lines)
    {
        printf("empty map\n");
        exit(1);
    }
    map_elements(vars,lines);
    matrix = ft_split(lines,'\n');
    vars->height = map_height(matrix);
    surrounded_map(matrix);
    look_in_sides(vars, matrix);
    return (matrix);
}

void    copy_map(t_vars *vars)
{
    int i;

    i = 0;
    vars->matrix_backup = malloc((vars->height + 1) * sizeof(char *));
    while (i < vars->height)
    {
        vars->matrix_backup[i] = ft_strdup(vars->matrix[i]);
        i++;
    }
    vars->matrix_backup[i] = NULL;
}

void check_main(char *av)
{
    int fd;
    t_vars  vars;
    
    fd = open(av,O_RDONLY);
    if (fd < 0)
    {
        write(2, "file not found\n", 16);
        exit(1);
    }
    vars.matrix = read_map(fd, &vars);
    copy_map(&vars);
    vars.x = get_x_index(vars.matrix, 'P');
    vars.y = get_y_index(vars.matrix, 'P');
    find_path(&vars, vars.x, vars.y);
    if (check_condition(&vars) == 1)
    {
        printf("error path not valid");
        exit(1);
    }
    game_start(&vars);
    close(fd);
}

int main(int ac, char **av)
{
    int i;
    
    i = ft_strlen(av[1]) - 1;
    if (ac == 2)
    {
        if (av[1][i] != 'r' || av[1][i - 1] != 'e' || av[1][i - 2] != 'b' || av[1][i - 3] != '.')
        {
            write(2, "invalid file name\n",19);
            exit(1);
        }
    }
    check_main(av[1]);
    return 0;
}
