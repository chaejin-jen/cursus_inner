#ifndef SO_LONG_INT_H
# define SO_LONG_INT_H

/* map */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1028 //4096
# endif

# define TILE_SIZE 32

/* key codes */
# define X_EVENT_KEY_EXIT	17
# define X_EVENT_KEY_PRESS	2
# define KEY_ESC			53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_R 15

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

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

#endif
