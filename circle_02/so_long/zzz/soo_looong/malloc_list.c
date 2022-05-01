map_parse(); // map_init, lst_init 에서 game->map 이랑 lst
buf_to_map_and_lst(); // lst, lst->content, new_lst(ft_strndup)
lst_to_map(); // map->data    // free_pptr() 로 가능
