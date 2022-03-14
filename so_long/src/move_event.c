#include "so_long.h"
#include "so_long_int.h"

static void	success(t_game *game, t_map *map, t_player *player)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->tile_img.grass, player->pos.x * TILE_SIZE, player->pos.y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win,
			player->img_ptr[player->img_i], player->pos_next.x * TILE_SIZE + TILE_SIZE / 8, player->pos_next.y * TILE_SIZE + TILE_SIZE / 8);
	mlx_put_image_to_window(game->mlx, game->win, game->tile_img.success, 0, 0);
	game->play = 0;
	player->direction = 0;
}

void	move_event(t_game *game, t_map *map, t_vector pos)
{
	char	obj;

	obj = map->data[pos.y][pos.x];
	if (obj == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_img.grass, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
		map->obj_c--;
		//if (map->obj_c == 0)
		//	door_open();
	}
	else if (obj == 'E')
		success(game, map, &map->player);
}
