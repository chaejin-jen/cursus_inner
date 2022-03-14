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
typedef struct s_player
{
	t_vector	pos;
	t_vector	pos_next;
	int			direction;
	int			img_i;
	int			img_pre_i;
	void		**img_ptr;
}				t_player;


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
	void	*door_o;
	void	*door_c;
}				t_obj_img;

typedef struct	s_map
{
	int			rows;
	int			cols;
	int			obj_c;
	int			obj_e;
	t_list		*exit_lst;
	int			obj_p;
	t_player	player;
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

/* utils.c */
t_vector	vector_init(int x, int y);
t_vector	calc_vector(t_vector dst_pos, t_vector cur_pos);
t_list	*lst_init();
void	del_ptr(void *ptr);
void	free_pptr(char **pptr);

/* ========= map ========= */

/* map_set.c (used in map_parse) */
t_map	*map_init(void);
void	map_obj_set(t_map *map, char c, int col);

/* map_valid.c (used in map_parse) */
void	valid_object_num(t_map *map, t_list *lst);
void	map_valid(t_map *map, t_list *lst, char *buf, int cols, int buf_len);

/* map_parse.c ((used in game_init) */
void	map_parse(t_game *game, char *file_name);

/* mmap_imgs.c (used in game_init) */
void	mmap_imgs(t_game *game);

/* render_map.c (used in game_init) */
void	render_map(t_game *game);

/* game_init.c */
void	game_init(t_game *game);

/* set_player.c (used in keypress) */
void	set_player(int key, t_game *game, int x, int y);

/* keypress.c */
int		keypress(int key, t_game *game);

/* move_event.c */
void	move_event(t_game *game, t_map *map, t_vector pos);
//void	move_event(t_map *map, t_vector pos);

/* update.c */
int		update(t_game *game);

/* error.c */
void	null_error(t_game game, char *message);
void	read_error(char *message);
void	map_error(t_map *map, t_list *lst, char *message);

/* event_exit.c */
int		close_window(t_game *game);
void	event_exit(t_game *game);

/* test */
void	print_exit_lst(int obj_e, t_list *exit_lst);
void	print_lst(t_map *map,t_list *lst);


#endif
