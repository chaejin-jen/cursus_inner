#include <fcntl.h>
#include <errno.h>
#include "so_long.h"
#include "so_long_int.h"

static int	read_file(int fd, char *read_buf)
{
	int	read_len;

	read_len = read(fd, read_buf, BUFFER_SIZE);
	if (read_len == -1)
		read_error("read error\n");
	read_buf[read_len] = '\0';
	return (read_len);
}

static void	buf_to_lst(t_list *lst, char *buf)
{
	t_list	*new_lst;

	if (lst->content == NULL)
		lst->content = (void *)buf;
	else
	{
		new_lst = ft_lstnew((void *)buf);
		if (!new_lst)
			read_error("malloc error (ft_newlst)");
		lst->next = new_lst;
		lst = lst->next;
	}
}

static void	buf_to_map(t_map *map, char *buf, int buf_len)
{
	int		cols;
	char	*content;
	// t_list	*head;
	t_list	*new_lst;

	if (map->cols == 0)
		map->cols = index_nl(buf);
	// head = lst;
	while (*buf)
	{
		// lst = ft_lstlast(lst);
		cols = index_nl(buf);
		map->rows++;
		map_valid(map, map->tmp_lst, buf, cols, buf_len);
		new_lst = ft_lstnew((void *)buf);
		if (!map->tmp_lst)
			map->tmp_lst = new_lst;
		else
			ft_lstadd_front(&map->tmp_lst, new_lst);
		if (cols == -1 || buf[cols] == '\0')
		{
			if (buf_len != BUFFER_SIZE)
				valid_object_num(map, map->tmp_lst);
			return ;
		}
		buf += (map->cols + 1);
	}
}

static void	lst_to_map(t_map *map, t_list *lst)
{
	int		row;
	char	*content;

	row = 0;
	map->data = (char **)malloc(sizeof(char *) * (map->rows + 1));
	if (map->data == NULL)
	{
		free_pptr(map->data);
		read_error("malloc failed (t_map *map.map)\n");
	}
	map->data[map->rows] = 0;
	while (lst)
	{
		content = (char *)(lst->content);
		map->data[row] = ft_strndup(content, map->cols);
		if (map->data[row] == NULL)
		{
			free_pptr(map->data);
			read_error("malloc failed (t_map *map.map[row])\n");
		}
		map->data[row][map->cols] = 0;
		row++;
		lst = lst->next;
	}
}

void	map_parse(t_game *game, char *file_name)
{
	char	read_buf[BUFFER_SIZE + 1];
	int		read_len;
	int		fd;
	t_list	*lst;

	if (!ft_strncmp(file_name + ft_strlen(file_name) - 5, ".ber", 4))
		read_error("valid file extention \".ber\"\n");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		read_error("cat not open file\n");
	read_len = BUFFER_SIZE;
	game->map = map_init();
	// lst = lst_init();
	while (read_len == BUFFER_SIZE)
	{
		read_len = read_file(fd, read_buf);
		buf_to_map(game->map, read_buf, read_len);
	}
	lst_to_map(game->map, lst);
	ft_lstclear(&lst, del_ptr);
	printf("=======map_parse=========");
	print_exit_lst(game->map->obj_e, game->map->exit_lst);
	free(lst);
	game->win_size.x = game->map->cols * TILE_SIZE;
	game->win_size.y = game->map->rows * TILE_SIZE;
}
