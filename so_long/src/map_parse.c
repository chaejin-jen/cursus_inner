/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:15 by chaejkim          #+#    #+#             */
/*   Updated: 2022/03/15 16:57:26 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include "so_long.h"
#include "so_long_int.h"

static int	open_file(char *file_name)
{
	int	fd;
	int	s_len;

	s_len = ft_strlen(file_name);
	if (!ft_strncmp(file_name + s_len - 5, ".ber", 4))
		read_error("valid file extention \".ber\"\n");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		read_error("cat not open file\n");
	return (fd);
}

static int	read_file(int fd, char *read_buf)
{
	int	read_len;

	read_len = read(fd, read_buf, BUFFER_SIZE);
	if (read_len == -1)
		read_error("read error\n");
	read_buf[read_len] = '\0';
	return (read_len);
}

static void	buf_to_map(t_map *map, char *buf, int buf_len)
{
	int		cols;
	t_list	*new_lst;

	if (map->cols == 0)
	{
		while (!index_nl(buf))
			buf++;
		map->cols = index_nl(buf);
		if (!*buf && map->cols == -1)
			map_error(map, "no map data\n");
	}
	while (*buf)
	{
		cols = index_nl(buf);
		map->rows++;
		map_valid(map, buf, cols, buf_len);
		map_lst_add(map, buf);
		if (cols == -1 || buf[cols] == '\0')
		{
			if (buf_len != BUFFER_SIZE)
				valid_obj_num(map);
			return ;
		}
		buf += (map->cols + 1);
	}
}

static void	lst_to_map(t_map *map)
{
	int		row;
	t_list	*lst;

	row = map->rows - 1;
	lst = map->tmp_lst;
	map->data = (char **)malloc(sizeof(char *) * (map->rows + 1));
	if (map->data == NULL)
	{
		free_pptr(map->data);
		read_error("malloc failed (t_map *map.map)\n");
	}
	map->data[map->rows] = 0;
	while (lst)
	{
		map->data[row] = ft_strndup((char *)(lst->content), map->cols);
		if (map->data[row] == NULL)
		{
			free_pptr(map->data);
			read_error("malloc failed (t_map *map.map[row])\n");
		}
		map->data[row][map->cols] = 0;
		row--;
		lst = lst->next;
	}
}

void	map_parse(t_game *game, char *file_name)
{
	char	read_buf[BUFFER_SIZE + 1];
	int		read_len;
	int		fd;

	fd = open_file(file_name);
	read_len = BUFFER_SIZE;
	game->map = map_init();
	while (read_len == BUFFER_SIZE)
	{
		read_len = read_file(fd, read_buf);
		buf_to_map(game->map, read_buf, read_len);
	}
	game->map->obj_c_init = game->map->obj_c;
	lst_to_map(game->map);
	ft_lstclear(&game->map->tmp_lst, del_ptr);
	game->win_size.x = game->map->cols * TILE_SIZE;
	game->win_size.y = game->map->rows * TILE_SIZE;
}
