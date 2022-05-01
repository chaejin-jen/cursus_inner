/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:50:15 by chaejkim          #+#    #+#             */
/*   Updated: 2022/05/02 00:14:04 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include "so_long.h"

static int	open_file(char *file_name)
{
	int	fd;
	int	s_len;

	s_len = ft_strlen(file_name);
	if (!ft_strncmp(file_name + s_len - 5, ".ber", 4))
		error_exit("valid file extention \".ber\"\n");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("cat not open file\n");
	return (fd);
}

static int	read_lines(int fd, t_list **buf_lst)
{
	char	*line;
	t_list	*new_lst;
	int		line_num;

	*buf_lst = NULL;
	line_num = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (*buf_lst == NULL && line[0] == '\n')
		{
			free(line);
			continue ;
		}
		new_lst = ft_lstnew(line);
		if (new_lst == NULL)
			read_error_exit(buf_lst, line, "malloc error (line_lst)\n");
		ft_lstadd_front(buf_lst, new_lst);
		line_num++;
	}
	del_new_line(buf_lst, &line_num);
	return (line_num);
}

static t_map	*map_init(int lines_num)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (map);
	map->data = (char **)malloc(sizeof(char *) * (lines_num + 1));
	if (map->data == NULL)
	{
		free(map);
		return (NULL);
	}
	map->rows = 0;
	map->cols = 0;
	map->obj_c = 0;
	map->obj_e = 0;
	map->obj_p = 0;
	map->player.pos.x = 0;
	map->player.pos.y = 0;
	map->exit_lst = 0;
	return (map);
}

static int	buf_to_map(t_map *map, t_list *buf_lst, int lines_num)
{
	t_list	*cur_lst;
	int		cols;
	char	*buf;

	cur_lst = buf_lst;
	map->data[lines_num] = 0;
	while (--lines_num != -1)
	{
		buf = (char *)cur_lst->content;
		cols = ft_strlen(buf);
		if (buf[cols - 1] == '\n')
			cols--;
		if (map->cols == 0)
			map->cols = cols;
		if (valid_map(map, buf, cols, lines_num) == 0)
			return (-1);
		map->data[lines_num] = buf;
		map->data[lines_num][map->cols] = '\0';
		map->rows++;
		cur_lst = cur_lst->next;
	}
	return (0);
}

void	map_parse(t_game *game, char *file_name)
{
	t_list	*buf_lst;
	int		fd;
	int		lines_num;

	fd = open_file(file_name);
	lines_num = read_lines(fd, &buf_lst);
	if (lines_num == 0)
		error_exit("no map data");
	game->map = map_init(lines_num);
	if (game->map == NULL)
	{
		ft_lstclear(&buf_lst, 0);
		error_exit("malloc_failed (map)");
	}
	if (buf_to_map(game->map, buf_lst, lines_num) == -1)
		map_error_exit(game->map, buf_lst);
	ft_lstclear(&buf_lst, ft_del_ptr);
	game->win_size.x = game->map->cols * TILE_SIZE;
	game->win_size.y = game->map->rows * TILE_SIZE;
}
