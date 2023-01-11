#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

# define WIN_WIDTH 256
# define WIN_HEIGHT 256

# define IMG_WIDTH 256
# define IMG_HEIGHT 256

typedef struct	s_img
{
	void	*img_ptr;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

void	my_mlx_pixel_put(t_img *img, int x, int y)
{
	int		r;
	int		g;
	int		b;
	int		rgb_color;
	char	*dst;

	r = (int)(255.999 * ((double)x / (IMG_WIDTH - 1)));
	g = (int)(255.999 * ((double)y / (IMG_HEIGHT - 1)));
	b = (int)(255.999 * 0.25);
	rgb_color = (r << 16) | (g << 8) | b;
	dst = img->data + (x * (img->bpp / 8)) + ((IMG_HEIGHT - y - 1) * img->size_l);
	*(unsigned int *)dst = rgb_color;
}

int main(void)
{
	t_mlx	*mlx;
	t_img	img;
	int		count_w;
	int		count_h;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Gadation");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	count_h = IMG_HEIGHT;
	while (--count_h >= 0)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
			my_mlx_pixel_put(&img, count_w, count_h);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	free(mlx);
	return (0);
}