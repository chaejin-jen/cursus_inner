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
		map_set.c
	init.c
		//map, game, window, img
	image_put.c
		//mlx_put_image_to_window
			(tiles(grass, wall), game_obj(player, collection, exit))
		image_mmap.c
		image_update.c
	play_game.c
		//
			obj_postion, map 이랑 비교
		game_event.c

mv tile_grass_0.png grass_0.png 
mv tile_grass_1.xpm grass_1.xpm 
mv tile_grass_3.png grass_3.png 
mv tile_water_0.xpm water_0.xpm 
mv tile_grass_0.xpm grass_0.xpm 
mv tile_grass_2.png grass_2.png 
mv tile_grass_3.xpm grass_3.xpm 
mv tile_grass_1.png grass_1.png 
mv tile_grass_2.xpm grass_2.xpm 
mv tile_water_0.png water_0.png 