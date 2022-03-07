#include <stdio.h>
// #include "../../so_long/lib/mlx/mlx.h"
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		*width;
	int		*height;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	// img.img = mlx_new_image(mlx, 500, 500);
	img.img = mlx_xpm_file_to_image(mlx, "simple00.ber", img.width, img.height);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								// &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FFFFFF);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
	printf("%p\n", img.img);
}