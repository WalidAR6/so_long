#include "so_long.h"

int main()
{
    void *mlx;
    void *mlx_win;
    int i;

    i = 0;
    mlx = mlx_init();
    if (mlx == NULL)
        return (1);
    mlx_win = mlx_new_window(mlx,500,500,"my first window");
    if (mlx_win == NULL)
    {
        free(mlx_win);
        return(1);
    }
    while (i <= 500)
    {
        mlx_pixel_put(mlx,mlx_win,i,100,0xFFFFFF);
        i++;
    }
    i = 0;
    while (i <= 500)
    {
        mlx_pixel_put(mlx,mlx_win,100,i,0xFFFFFF);
        i++;
    }
    mlx_loop(mlx);
}