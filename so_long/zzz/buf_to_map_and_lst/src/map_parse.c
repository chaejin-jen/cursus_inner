#include <fcntl.h>
#include <errno.h>
#include "so_long.h"
#include "so_long_int.h"

static int open_file(char *file_name)
{
	int	fd;
	int	s_len;

	s_len = ft_strlen(file_name);
	if (!ft_strncmp(file_name + s_len - 5, ".ber", 4))
		read_error("valid file extention \".ber\"\n");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		read_error("cat not open file\n");
		//if (errno == ENOENT)
		//{
		//	/* file doesn’t exist */
		//}
		//exit(0);
	return (fd);
}

static int read_file(int fd, char *read_buf)
{
	int read_len;

	read_len = read(fd, read_buf, BUFFER_SIZE);
	if (read_len == -1)
		read_error("read error\n");
	read_buf[read_len] = '\0';
	return (read_len);
}

static void	buf_to_map_and_lst(t_map *map, t_list *lst, char *buf, int buf_len)
{
	int		cols;
	char	*content;
	t_list	*cur_lst;

	if (map->cols == 0)
		map->cols = index_nl(buf);
	cur_lst = lst;
	while (cur_lst->next)
		cur_lst = cur_lst->next;
	while (*buf)
	{
		map->rows++;
		cols = index_nl(buf);
		map_valid(map, lst, buf, cols, buf_len);
		if (!cur_lst->content && !cur_lst->next)
			cur_lst->content = (void *)buf;
		else
		{
			cur_lst->next = ft_lstnew((void *)buf);
			if (cur_lst->next == NULL)
				map_error(map, lst, "malloc error\n");
			cur_lst = cur_lst->next;
		}
		if (cols == -1 || buf[cols] == '\0')
		{
			if (buf_len != BUFFER_SIZE)
				valid_object_num(map, lst);
			return ;
		}
		buf += (map->cols + 1);
	}
}

static void	lst_to_map(t_map *map, t_list *lst)
{
	int		row;
	char	*content;
	t_list	*pre_lst;

	row = 0;

	map->data = (char **)malloc(sizeof(char *) * (map->rows + 1));
	if (map->data == NULL)
	{
		free_pptr(map->data);
		read_error("malloc failed (t_map *map.map)\n");
	}
	map->data[map->rows] = 0;
	//print_lst(map, lst);
	while (lst)
	{
		//print_lst(map, lst);
		content = (char *)(lst->content);
		map->data[row] = ft_strndup(content, map->cols);
		printf("map->data[%d] : %s|\n", row, map->data[row]);
		//map->data[row] = (char *)lst->content;
		if (map->data[row] == NULL)
		{
			free_pptr(map->data);
			read_error("malloc failed (t_map *map.map[row])\n");
		}
		map->data[row][map->cols] = 0;
		row++;
		pre_lst = lst;
		lst = lst->next;
		ft_lstdelone(pre_lst, free);
	}
}

void	map_parse(t_game *game, char *file_name)
{
	char	read_buf[BUFFER_SIZE + 1];
	int		read_len;
	int		fd;
	t_list	*lst;

	fd = open_file(file_name);
	read_len = BUFFER_SIZE;
	game->map = map_init();
	lst = lst_init();
	//lst = 0;
	while (read_len == BUFFER_SIZE)
	{
		read_len = read_file(fd, read_buf);
		buf_to_map_and_lst(game->map, lst, read_buf, read_len);
	}
	//print_lst(game->map, lst);
	lst_to_map(game->map, lst);
	print_lst(game->map, lst);
	//ft_lstclear(&lst, free);
	free(lst);
	game->win_size.x = game->map->cols * TILE_SIZE;
	game->win_size.y = (game->map->rows + 1) * TILE_SIZE;
	printf("row : %d\tmap->data[1] : %s\n", game->map->rows, game->map->data[1]);
}