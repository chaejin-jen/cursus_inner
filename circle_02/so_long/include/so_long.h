/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:49:33 by chaejkim          #+#    #+#             */
/*   Updated: 2022/05/02 00:58:03 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
/* # include <mlx.h> */
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "so_long_int.h"

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

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
	int			obj_p;
	int			obj_c;
	int			obj_e;
	t_list		*exit_lst;
	t_player	player;
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
	int				move_count;
}				t_game;

/* ========== common uses ========== */
/* utile.c */
t_vector	vector_init(int x, int y);
t_vector	calc_vector(t_vector dst_pos, t_vector cur_pos);
void		del_new_line(t_list **buf_lst, int *line_num);

/* ============== map ============== */
/* map_valid.c (used in map_parse) */
int			valid_map(t_map *map, char *buf, int cols, int lines_num);
int			valid_obj_num(t_map *map);

/* map_parse.c ((used in game_init) */
void		map_parse(t_game *game, char *file_name);

/* ========== game init =========== */
/* mmap_imgs.c (used in game_init) */
void		mmap_imgs(t_game *game);

/* game_init.c */
void		game_init(t_game *game);

/* keypress.c */
int			keypress(int key, t_game *game);

/* =========== game event =========== */
/* move_event.c */
void		move_event(t_game *game, t_map *map, t_vector pos);

/* update.c */
int			update(t_game *game);

/* ============= error ============== */
/* error.c */
int			error_message(char *message);
void		error_exit(char *message);
void		read_error_exit(t_list **buf_lst, char *line, char *message);
void		map_error_exit(t_map *map, t_list *buf_lst);

/* ============= exit =============== */
/* event_exit.c */
int			close_window(t_game *game);
void		game_exit(t_game *game);

#endif
