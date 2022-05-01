#include "so_long.h"

static void put_img(t_game *game, char c, t_vector pos)
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
								game->obj_img.gem, pos.x, pos.y);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
								game->tile_img.grass, pos.x, pos.y);
		mlx_put_image_to_window(game->mlx, game->win,
								game->obj_img.door, pos.x, pos.y);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
								game->tile_img.grass, pos.x, pos.y);
		mlx_put_image_to_window(game->mlx, game->win,
								game->player_img.front[1], pos.x, pos.y);
	}
}

void render_map_init(t_game *game)
{
	t_vector pos;
	char *content;
	t_list *lst;

	pos.x = 0;
	lst = game->map->lst;
	while (pos.x < (game->map->rows) + 1)
	{
		pos.y = 0;
		content = (char *)(lst->content);
		printf("x : %d, y : %d\tcontent : %s\n", pos.x, pos.y, content);
		while (pos.y < game->map->cols)
		{
			// printf(content[pos.y]);
			put_img(game, content[pos.y], pos);
			pos.y++;
		}
		pos.x++;
		lst = lst->next;
	}
}
