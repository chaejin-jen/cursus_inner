#include "so_long.h"

static void	set_step(int key, t_player *player)
{
	player->direction = key;
	player->walk = FALSE;
}

static void	set_walk(t_player *player, int x, int y, int key)
{
	player->direction = key;
	player->walk = TRUE;
	player->pos_left.x = x - 1;
	player->pos_left.y = y;
	player->pos_right.x = x + 1;
	player->pos_right.y = y;
	player->pos_up.x = x;
	player->pos_up.y = y - 1;
	player->pos_down.x = x;
	player->pos_down.y = y + 1;
}

static void	set_player(int key, t_map *map, int x, int y)
{
	if (key == KEY_W || key == KEY_UP)
	{
		if (y == 0 || map->data[y - 1][x] == '1')
			return (set_step(key, &map->player));
		map->player.pos.y--;
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		if (y == map->rows - 1 || map->data[y + 1][x] == '1')
			return (set_step(key, &map->player));
		map->player.pos.y++;
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		if (x == 0 || map->data[y][x - 1] == '1')
			return (set_step(key, &map->player));
		map->player.pos.x--;
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		if (x == map->cols - 1 || map->data[y][x + 1] == '1')
			return (set_step(key, &map->player));
		map->player.pos.x++;
	}
	set_walk(&map->player, x, y, key);
}

void	move_player(t_game *game, int key)
{
	char		*str;

	printf("%p\n", game->mlx);
	printf("%s\n", str);
}

int keypress(int key, t_game *game)
{
	t_vector	p_pos;

	p_pos = game->map->player.pos;
	if (key == KEY_ESC)
	{
		printf("%p\n", game->mlx);
		exit(0);
	}
	set_player(key, game->map, p_pos.x, p_pos.y);
	return (key);
}
