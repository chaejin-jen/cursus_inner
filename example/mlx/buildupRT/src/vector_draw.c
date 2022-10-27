#include <mlx.h>
#include "libft/libft.h"
#include "vector/vec3.h"
#include "vector/ray.h"

typedef struct 	s_data
{
	void	*mlx;
	void	*mlx_win;
	int		width, height;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}						t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, t_vec3 *color)
{
	char	*dst;

	// color->x = (int)(255.999 * ((double)x / (data->width - 1)));
	// color->y = (int)(255.999 * ((double)y / (data->height - 1)));
	// color->z = (int)(255.999 * 0.25);
	dst = data->addr
		+ (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = ((int)color->x << 16) | ((int)color->y << 8) | (int)color->z;
}

int ft_draw(t_data *data)
{
	int			i;
	int			j;
	t_color3	color;

	j = data->height - 1;
	while (j >= 0)
	{
		i = 0;
		ft_putstr_fd("\rScanlines remaining: ", 1);
		ft_putnbr_fd(j, 1);
		ft_putchar_fd(' ', 1);
		while (i < data->width)
		{
			ft_vec3_set_xyz(&color, (float)i / (data->width - 1), (float)j / (data->height - 1), 0.25);
			ft_vec3_multi_scalar(&color, 255.999, &color);
			my_mlx_pixel_put(data, i, data->height - 1 - j, &color);
			i++;
		}
		j--;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int main_loop(t_data *data)
{
	ft_draw(data);
	return (0);
}

int main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.width = 600;
	data.height = 400;
	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
	data.img = mlx_new_image(data.mlx, 600, 400);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}

