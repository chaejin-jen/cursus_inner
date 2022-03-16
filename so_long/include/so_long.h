/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:49:33 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/15 16:57:20 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
//# include <mlx.h>
# include "mlx.h"
# include "so_long_int.h"
# include "libft.h"
# include "get_next_line.h"
# include "keycodes.h"

typedef struct s_player
{
	t_vector	pos_init;
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
	void	*success;
}				t_tile_img;

typedef struct s_obj_img
{
	void	*coin;
	void	*gem;
	void	*door_o;
	void	*door_c;
}				t_obj_img;

typedef struct s_map
{
	int			rows;
	int			cols;
	int			obj_c_init;
	int			obj_c;
	int			obj_e;
	t_list		*exit_lst;
	t_list		*collect_lst;
	int			obj_p;
	t_player	player;
	t_list		*tmp_lst;
	char		**data;
}				t_map;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_vector		win_size;
	t_vector		img_size;
	t_tile_img		tile_img;
	t_obj_img		obj_img;
	t_player_img	player_img;
	t_map			*map;
	int				play;
}				t_game;

/* ========== common uses ========== */
/* utils.c */
void		map_lst_add(t_map *map, void *content);
t_vector	vector_init(int x, int y);
t_vector	calc_vector(t_vector dst_pos, t_vector cur_pos);
void		del_ptr(void *ptr);
void		free_pptr(char **pptr);

/* ============== map ============== */
/* map_init.c (used in map_init) */
t_map		*map_init(void);

/* map_set.c (used in map_parse) */
void		map_obj_set(t_map *map, char c, int col);

/* map_valid.c (used in map_parse) */
void		map_valid(t_map *map, char *buf, int cols, int buf_len);
void		valid_obj_num(t_map *map);

/* map_parse.c ((used in game_init) */
void		map_parse(t_game *game, char *file_name);

/* ========== game init =========== */
/* mmap_imgs.c (used in game_init) */
void		mmap_imgs(t_game *game);

/* render_map.c (used in game_init) */
void		render_map(t_game *game);

/* game_init.c */
void		game_init(t_game *game);

/* =========== key event =========== */
/* set_player.c (used in keypress) */
void		set_player(int key, t_game *game, int x, int y);

/* replay.c (used in keypress) */
void		replay(t_game *game, t_map *map, t_player *player);

/* keypress.c */
int			keypress(int key, t_game *game);

/* =========== game event =========== */
/* move_event.c */
void		move_event(t_game *game, t_map *map, t_vector pos);

/* update.c */
int			update(t_game *game);

/* ============= error ============== */
/* error.c */
void		read_error(char *message);
void		map_error(t_map *map, char *message);

/* ============= exit =============== */
/* event_exit.c */
int			close_window(t_game *game);
void		game_exit(t_game *game);

#endif
