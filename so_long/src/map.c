#include "so_long.h"

int check_extention(char *file_name)
{
	int s_len;

	s_len = ft_strlen(file_name);
	if (ft_strncmp(file_name + s_len - 5, ".ber", 4))
		return (0);
	return (0);
}

int read_map(char *file_name, char *map_buf)
{
	int fd;
	int read_len;

	fd = open(file_name, O_RDONLY, 0644);
	if (fd < 0)
	{
		//printf("파일 열기에 실패했습니다.\n");
		exit(0);
	}
	read_len = read(fd, map_buf, BUFFER_SIZE);
	if (read_len == -1)
		exit(0);
	map_buf[read_len] = '\0';
	printf("map_buf 체크 %s", map_buf);
	return (read_len);
}

void	valid_map()
{
	// is_rectanglez_wall
	// valid_charcters
	//     (0은 빈 공간, 1은 벽, C는 수집품, E는 맵의 출구, P는 주인공의 시작지점)
	//     (E, C, P 적어도 한개 이상)

}

char	**parse_map(t_game *game, char *map_buf)
{
	int	width;
	int	height;

	//while (read_len)

	return (0);
}

void	map_init(t_game *game, char *file_name)
{
	char	map_buf[BUFFER_SIZE + 1];
	int		read_len;

	if (check_extention(file_name))
		exit(0);
	read_len = read_map(file_name, map_buf);
	valid_map();
	//game = parse_map(map_buf, read_len);
}