#include "so_long.h"

char **read_map(int fd)
{
    char *get_lines;
    char *lines;
    t_data  *data;
    char **matrix;
    int i;

    i = 0;
    lines = NULL;
    data = malloc(sizeof(t_data));
    data->C = 0;
    data->E = 0;
    data->P = 0;
    while (1)
    {
        get_lines = get_next_line(fd);
        if (get_lines == NULL)
            break;
        lines = ft_strjoin(lines,get_lines);
    }
    while (lines[i])
    {
        if (lines[i] == 'C')
            data->C = data->C + 1;
        else if (lines[i] == 'P')
            data->P = data->P + 1;
        else if (lines[i] == 'E')
            data->E = data->E + 1;
        i++;
    }
    if (data->P != 1 || data->E != 1 || data->C < 1)
    {
        write(1, "Error ok",9);
        exit(1);
    }
    matrix = ft_split(lines,'\n');
    // func
    int j = 0;
    while (matrix && *matrix && matrix[j])
        j++;
    printf("%d",j);
    i = 0;
    while (matrix[0][i])
    {
        if(ft_strchr(matrix[0],'0'))
        {
            write(1, "Error (found 0 in the first line)\n", 36);
            exit(1);
        }
        i++;
    }
    
    return matrix;
}


int main()
{
    int fd;
    char **rm;
    int i = 0;

    fd = open("./maps/map.ber",O_RDONLY);
    rm = read_map(fd);
    while (i < 5)
    {
        printf("%s\n",rm[i]);
        i++;
    }
    
    close(fd);
}