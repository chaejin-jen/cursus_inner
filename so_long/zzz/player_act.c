static void	player_act(t_game *game, t_map *t_map, t_player *player)
{
	t_vector	pos;

	//player_act(game, game->map, game->map->player);

	pos = calc_position(player->pos_next, player->pos);
	if (pos.x || pos.y)
		walk();
	else
		step();


}

if (player->pos_next.x - player->pos.x
			|| player->pos_next.y, player->pos.y)
