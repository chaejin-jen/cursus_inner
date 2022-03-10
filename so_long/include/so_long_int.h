#ifndef SO_LONG_INT_H
# define SO_LONG_INT_H

/* map */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1028 //4096
# endif

# define TILE_SIZE 8

//typedef enum e_game_object
//{
//	EMPTY = '0',
//	WALL = '1',
//	COLLECTION = 'C',
//	PLAYER = 'P',
//	EXIT = 'E'
//}	t_game_object;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_bool_obj
{
	t_bool	player;
	t_bool	exit;
	t_bool	collect;
}				t_bool_obj;

/* key codes */
# define X_EVENT_KEY_EXIT	17 //Exit program key code
# define KEY_ESC			53

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

#endif