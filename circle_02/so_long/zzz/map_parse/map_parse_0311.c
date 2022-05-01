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

static int read_map(int fd, char *read_buf)
{
	int read_len;

	read_len = read(fd, read_buf, BUFFER_SIZE);
	if (read_len == -1)
		read_error("read error\n");
	read_buf[read_len] = '\0';
	return (read_len);
}

static void	copy_buf_to_lst(t_map *map, char *buf)
{
	//char	content[map->cols + 1];
	void	*content;
	t_list	*new_lst;

	//ft_memcpy(content, (const void *)buf, map->cols);
	content = (void *)buf;
	new_lst = ft_lstnew(content);
	if (new_lst == NULL)
		map_error(map, "malloc error\n");
	ft_lstadd_back(&map->lst, new_lst);
	printf("row : %d\tlast_lst_content : %s\n", map->rows, (char *)(ft_lstlast(map->lst)->content));
	//printf("row : %d \t content[11] : %c\n", map->rows, ((char *)(ft_lstlast(map->lst)->content))[11]);
}

static void	put_buf_on_map(t_map *map, char *buf, int buf_len)
{
	int	cols;

	if (map->cols == 0)
		map->cols = index_nl(buf);
	while (*buf)
	{
		//printf("map->rows : %d, map->cols : %d\n", map->rows, map->cols);
		cols = index_nl(buf);
		//printf("cols : %d, map->cols : %d\n", cols, map->cols);
		valid_rectangle_map(map, buf, cols);
		valid_object(map, buf, map->cols);
		valid_wall(map, buf, cols, buf_len);
		copy_buf_to_lst(map, buf);
		if (cols == -1 || buf[cols] == '\0')
		{
			if (buf_len != BUFFER_SIZE)
				valid_object_num(map);
			return ;
		}
		buf += (map->cols + 1);
		map->rows++;
	}
}

void	map_parse(t_game *game, char *file_name)
{
	char	read_buf[BUFFER_SIZE + 1];
	int		read_len;
	int		fd;

	fd = open_file(file_name);
	read_len = BUFFER_SIZE;
	map_init(&game->map);
	while (read_len == BUFFER_SIZE)
	{
		read_len = read_map(fd, read_buf);
		put_buf_on_map(&game->map, read_buf, read_len);
	}

	game->win_size.x = game->map.cols * TILE_SIZE;
	game->win_size.y = (game->map.rows + 1) * TILE_SIZE;
	//game = parse_map(map_buf, read_len);
	printf("row : %d\tlast_lst_content : %s\n", game->map.rows, (char *)(ft_lstlast(game->map.lst)->content));
}
