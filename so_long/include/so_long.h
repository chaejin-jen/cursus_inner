#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
//# include <mlx.h>
//# include <mlx_int.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "keycodes.h"


/* game object img */

//typedef struct s_sprites
//{

//}			t_sprites;

typedef struct s_player_img
{
	void	*front;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
}			t_player_img;

typedef struct	s_map
{
	int		rows;
	int		cols;
	int		obj_c;
	int		obj_e;
	int		obj_p;
	t_list	*lst;
}				t_map;

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_img	img;
	t_map	map;
}				t_game;

//void	draw_rectangles(t_game *game);

int		keypress(int keycode, t_game *game);

/* ========= map ========= */
/* map_set.c */
void	map_init(t_map *map);
void	map_obj_set(t_map *map, char c);

/* map_valigy.c is used by map_parse.c */
void	valid_rectangle_map(t_map *map, char *buf, int cols);
void	valid_object(t_map *map, char *buf, int cols);
void	valid_wall(t_map *map, char *buf, int row, int cols);
void	valid_object_num(t_map *map);

/* map_parse.c */
void	map_parse(t_game *game, char *file_name);

void	game_init(t_game *game);
//void	window_init(t_game *game);
//void	img_init(t_game *game);

void	null_error(t_game game, char *message);
void	read_error(char *message);
void	map_error(t_map *map, char *message);

int		close_window(t_game *game);
void	event_exit(t_game *game);

#endif