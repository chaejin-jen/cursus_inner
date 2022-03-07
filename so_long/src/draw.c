#include "so_long.h"
#include <math.h>

void draw_rectangle(t_game *game, int x, int y)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y + i) * WIDTH + x + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void draw_rectangles(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (game->map[i][j] == 1)
				draw_rectangle(game, j, i);
			j++;
		}
		i++;
	}
}