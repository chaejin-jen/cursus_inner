#include "so_long.h"

static void put_img(t_game *game, t_player *p, char c, t_vector pos)
{
	pos.x *= TILE_SIZE;
	pos.y *= TILE_SIZE;
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win,
								game->tile_img.grass, pos.x, pos.y);
	else if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
								game->tile_img.water, pos.x, pos.y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
								game->tile_img.grass, pos.x, pos.y);
		mlx_put_image_to_window(game->mlx, game->win,
								game->obj_img.gem, pos.x + TILE_SIZE / 8, pos.y + TILE_SIZE / 8);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
								game->tile_img.grass, pos.x, pos.y);
		mlx_put_image_to_window(game->mlx, game->win,
								game->obj_img.door_c, pos.x - TILE_SIZE / 8, pos.y - TILE_SIZE / 8);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
								game->tile_img.grass, pos.x, pos.y);
		mlx_put_image_to_window(game->mlx, game->win,
								p->img_ptr[p->img_i], pos.x + TILE_SIZE / 8, pos.y + TILE_SIZE / 8);
	}
}

void render_map(t_game *game)
{
	t_vector pos;
	char	**map_data;

	pos.y = 0;
	game->map->player.img_ptr = game->player_img.front;
	map_data = game->map->data;
	mlx_clear_window(game->mlx, game->win);
	while (pos.y < game->map->rows)
	{
		pos.x = 0;
		while (pos.x < game->map->cols)
		{
			put_img(game, &game->map->player, map_data[pos.y][pos.x], pos);
			pos.x++;
		}
		pos.y++;
	}
}
