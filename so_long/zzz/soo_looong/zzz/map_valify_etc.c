#include "so_long.h"


void	valid_file(char *file_name)
{
	int	s_len;

	s_len = ft_strlen(file_name);
	if (ft_strncmp(file_name + s_len - 5, ".ber", 4))
	{
		// valid file extention ".ber" 
		exit(0);
	}
}

void	valid_wall_bottom(t_map *map)
{
	t_list	*last_lst;
	char	*last_content;

	last_lst = ft_lstlast(map->lst);
	last_content = (char *)last_lst->content;
	while (*last_content)
	{
		if (*last_content != '1')
			map_error(map, "The map must be a rectangle surrounded by walls '1'\n");
		last_content++;
	}
}