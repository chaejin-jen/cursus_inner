#include <stdio.h>
#include <stdlib.h>
// #include "../../so_long/lib/mlx/mlx.h"
#include <mlx.h>
#import <OpenGL/gl3.h>
// #include "../../so_long/lib/mlx/mlx_int.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

# define KEY_ESC	53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3

typedef struct	mlx_img_list_s
{
  int			width;
  int			height;
  char			*buffer;
  GLfloat		vertexes[8];
  struct mlx_img_list_s	*next;
} mlx_img_list_t;

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
} t_mlx;

typedef struct s_img
{
	void *img_ptr;
	int *data;
	int width;
	int height;
	int bpp;
	int size_line;
	int endian;
} t_img;

int keypress(int keycode, t_mlx mlx)
{
	mlx_img_list_t	*img;
	int	i;

	img = mlx_xpm_file_to_image(mlx.mlx_ptr, "../../so_long/textures/gem.xpm", &img->width, &img->height);
	if (keycode == KEY_A)
		// printf("%p\n", img);
		printf("%d\n", img->width);
	else if (keycode == KEY_S)
	{
		printf("%d\n", img->width);
		printf("%d\n", img->height);
	}
	else if (keycode == KEY_D)
	{
		printf("%p\n", img->next);
		while (img->next)
		{
			printf("%s\n", img->buffer);
			img = img->next;
		}
	}
	else if (keycode == KEY_F)
	{
		i = 0;
		while (i < 8)
			printf("%f\n", img->vertexes[i++]);
	}
	else if (keycode == KEY_ESC)
		exit(0);
	return (keycode);
}

int main(void)
{
	t_mlx mlx;
	t_img img;
	// int count_w, count_h;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "modify img!");
	mlx_key_hook(mlx.win_ptr, keypress, &mlx);
	img.img_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, "../../so_long/textures/gem.xpm", &img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 50, 50);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}