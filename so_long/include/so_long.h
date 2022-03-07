#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
//# include <mlx.h>
//# include <mlx_int.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "keycodes.h"

# define BUFFER_SIZE 10000

# define TILE_SIZE 32
# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;


	int		width;
	int		height;
	char	**map;
	//int		map[ROWS][COLS];
}				t_game;

void	draw_rectangles(t_game *game);

int		keypress(int keycode, t_game *game);

void	map_init(t_game *game, char *file_name);

void	game_init(t_game *game);
void	window_init(t_game *game);
void	img_init(t_game *game);


#endif