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

static t_list	*buf_to_map_and_lst(t_map *map, t_list **lst, char *buf, int buf_len)
{
	int	cols;
	t_list	*new_lst;

	if (map->cols == 0)
		map->cols = index_nl(buf);
	while (*buf)
	{
		printf("map->rows : %d, map->cols : %d\n", map->rows, map->cols);
		printf("map->obj_c : %d, map->obj_e : %d, map->obj_p : %d\n", map->obj_c, map->obj_e, map->obj_p);
		//printf("map->rows : %d, map->cols : %d\n", map->rows, map->cols);
		map->rows++;
		cols = index_nl(buf);
		//printf("cols : %d, map->cols : %d\n", cols, map->cols);
		map_valid(map, *lst, buf, cols, buf_len);
		new_lst = ft_lstnew((void *)buf);
		if (new_lst == NULL)
			map_error(map, *lst, "malloc error\n");
		ft_lstadd_back(lst, new_lst);
		printf("row : %d \t content[11] : %c\n", map->rows, ((char *)(ft_lstlast(*lst)->content))[11]);
		if (cols == -1 || buf[cols] == '\0')
		{
			//if (buf_len != BUFFER_SIZE)
			//	valid_object_num(map, lst);
			return (*lst);
		}
		buf += (map->cols + 1);
	}
	return (*lst);
}

static void	lst_to_map(t_map *map, t_list *lst)
{
	int	row;

	row = 0;

	map->data = (char **)malloc(sizeof(char *) * (map->rows + 1));
	if (map->data == NULL)
	{
		free_pptr(map->data);
		read_error("malloc failed (t_map *map.map)\n");
	}
	map->data[map->rows] = 0;
	while (row <= map->rows)
	{
		map->data[row] = ft_strndup((char *)lst->content, map->cols);
		if (map->data[row] == NULL)
		{
			free_pptr(map->data);
			read_error("malloc failed (t_map *map.map[row])\n");
		}
		map->data[row][map->cols] = 0;
		row++;
		printf("row : %d \t content[11] : %c\n", row, ((char *)lst->content)[11]);
		lst = lst->next;
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
	while (read_len == BUFFER_SIZE)
	{
		read_len = read_file(fd, read_buf);
		buf_to_map_and_lst(game->map, &lst, read_buf, read_len);
	}
	lst_to_map(game->map, lst);
	ft_lstclear(&lst, free);
	game->win_size.x = game->map->cols * TILE_SIZE;
	game->win_size.y = (game->map->rows + 1) * TILE_SIZE;
	//game = parse_map(map_buf, read_len);
	printf("row : %d\tlast_lst_content : %s\n", game->map->rows, game->map->data[1]);
}
