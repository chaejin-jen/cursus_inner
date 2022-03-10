so_long.h
so_long_int.h
	map 관련 정의 (game_object...)
	key codes 정의

공통
	error.c
	event_exit.c

main.c
	map_parse.c
		map_valify.c
		map_utils.c
	init.c
		//map, game, window, img
	put_image.c
		//mlx_put_image_to_window
			(tiles(grass, wall), game_obj(player, collection, exit))
		update_image.c
	play_game.c
		//
			obj_postion, map 이랑 비교
		game_event.c

