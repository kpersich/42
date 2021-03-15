#include <mlx.h>

/*int	main(void)
{
	void	*mlx;
	void	*img;

	mlx = mlx_init();
	img = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}*/
typedef struct	s_data 
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct  s_vars {
    void        *mlx;
    void        *mlx_win;
}               t_vars;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int				main(void)
{
	t_data	img;
	t_vars  var;
	int x = 0;
	int y = 0;

	var.mlx = mlx_init();
    var.mlx_win = mlx_new_window(var.mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(var.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	while (y < 100)
	{
		x = 0;
		while(x < 100)
		{
    		my_mlx_pixel_put(&img, 500 + x, 500 + y, 0x00FF0000);
			x++;
		}
		y++;
	}
    mlx_put_image_to_window(var.mlx, var.mlx_win, img.img, 0, 0);
    mlx_loop(var.mlx);
}