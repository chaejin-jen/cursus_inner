#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "vector.h"
#include "ray.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define IMG_WIDTH 800
# define IMG_HEIGHT 600

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

void	my_mlx_pixel_put(t_img *img, t_cam cam, int x, int y)
{
	char	*dst;
	double	u;
	double	v;
	double	t;
	int		rgb_color;
	t_ray	ray;
	t_vec	color;

	u = (double)x / (double)(IMG_WIDTH - 1);
	v = (double)y / (double)(IMG_HEIGHT - 1);
	ray = make_ray(cam.origin, sub_vec(add_vec(add_vec(cam.left_bottom_corner, \
										mul_vec_(cam.horizontal, u)), \
										mul_vec_(cam.vertical, v)), \
										cam.origin));
	t = 0.5 * (unit_vec(ray.direction).y + 1.0);
	color = mul_vec_(add_vec(mul_vec_(make_vec(1.0, 1.0, 1.0), (1.0 - t)), \
				mul_vec_(make_vec(0.5, 0.7, 1.0), t)), 255.999);
	rgb_color = ((int)color.x << 16) | ((int)color.y << 8) | (int)color.z;
	dst = img->data + (x * img->bpp / 8) + ((IMG_HEIGHT - y - 1) * img->size_l);
	*(unsigned int *)dst = rgb_color;
}

int main(void)
{
	t_mlx	*mlx;
	t_img	img;
	t_cam	cam;
	int		count_w;
	int		count_h;
	double	aspect_ratio;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Sky");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	aspect_ratio = 4.0 / 3.0;
	cam = make_cam(make_vec(0, 0, 0), 2.0 * aspect_ratio, 2.0, 1.0);
	count_h = IMG_HEIGHT;
	while (--count_h >= 0)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
			my_mlx_pixel_put(&img, cam, count_w, count_h);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	free(mlx);
	return (0);
}