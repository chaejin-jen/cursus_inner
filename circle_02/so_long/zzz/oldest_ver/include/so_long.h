#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
//# include <mlx.h>
//# include <mlx_int.h>
# include "so_long_int.h"
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "keycodes.h"



/*
typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;
*/

/* game object img */

/*
typedef struct s_sprites
{

}			t_sprites;
*/

typedef struct s_player_img
{
	void	*front[3];
	void	*back[3];
	void	*left[3];
	void	*right[3];
}			t_player_img;

typedef struct s_tile_img
{
	void	*grass;
	void	*water;
}				t_tile_img;

typedef struct s_obj_img
{
	void	*coin;
	void	*gem;
	void	*door;
}				t_obj_img;

typedef struct	s_map
{
	int			rows;
	int			cols;
	int			obj_c;
	int			obj_e;
	int			obj_p;
	t_vector	player_pos;
	char		**data;
}			t_map;

typedef struct	s_game
{
	void			*mlx;
	void			*win;
	t_vector		win_size;
	t_vector		img_size;
	t_tile_img		tile_img;
	t_obj_img		obj_img;
	t_player_img	player_img;
	t_map			*map;
}				t_game;

//void	draw_rectangles(t_game *game);

int		keypress(int keycode, t_game *game);

/* utils.c */
t_list	*lst_init();
void	free_pptr(char **pptr);

/* ========= map ========= */
/* map_set.c */
//void	map_init(t_map *map);
t_map	*map_init();
void	map_obj_set(t_map *map, char c);

/* map_valid.c is used by map_parse.c */
void	valid_object_num(t_map *map, t_list *lst);
void	map_valid(t_map *map, t_list *lst, char *buf, int cols, int buf_len);


/* map_parse.c */
void	map_parse(t_game *game, char *file_name);

/* mmap_imgs.c */
void	mmap_imgs(t_game *game);

/* put_imgs.c */
void	render_map_init(t_game *game);

void	game_init(t_game *game);
//void	window_init(t_game *game);
//void	img_init(t_game *game);

void	null_error(t_game game, char *message);
void	read_error(char *message);
void	map_error(t_map *map, t_list *lst, char *message);

int		close_window(t_game *game);
void	event_exit(t_game *game);

/* test */
void	print_lst(t_map *map);


#endif
