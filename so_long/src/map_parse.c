#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/libft/libft.h"
// #include "so_long.h"
// #include "so_long.h"

/*
width, height \n 이후로 고정 (다음 \n 일때 비교)
*/

// int	count_nb_word(char *str, int len)
// {
// 	// int		len;
// 	int		nb_word;
// 	int		cur;
	
// 	// len = strlen(str);
// 	nb_word = 0;
// 	cur = 0;
// 	while (cur < len)
// 	{
// 		while (*(str + cur) == '\n')
// 			cur++;
// 		if (*(str + cur))
// 			nb_word++;
// 		while (*(str + cur) && *(str + cur) != '\n')
// 			cur++;
// 	}
// 	return	(nb_word);
// }

static int	count_nb_word(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			cnt++;
		s++;
	}
	return (cnt);
}

char **str_to_map_lines(char *str)
{
	char	**map_lines;
	int		cur;
	int		nb_word;
	int		len;

	len = strlen(str);
	nb_word = count_nb_word(str, len);
	map_lines = (char **)calloc(nb_word + 1, sizeof(*map_lines));
	if (!map_lines)
		return ((char **)0);
	nb_word = 0;
	cur = 0;
	while (cur < len)
	{
		while (*(str + cur) == '\n')
		{
			*(str + cur) = 0;
			cur++;
		}
		if (*(str + cur))
		{

			map_lines[nb_word] = str + cur;
			nb_word++;
		}
		while (*(str + cur) && *(str + cur) != '\n')
			cur++;
	}
	map_lines[nb_word] = 0;
	int	line;
	line = 0;
	while (map_lines[line])
	{
		printf("%d: %s", line, map_lines[line]);
		line++;
	}
	free(map_lines);
	return (0);
}

char **str_to_map_lines_split(char *str)
{
	return (ft_split(str, '\n'));
}

int	main(void)
{
	char	**result;
	int		line;
	char	*str;
	
	str= "123\n abc\n 456\n 54";
	line = 0;
	result = str_to_map_lines(str);
	// // result = str_to_map_lines_split(str);
	// while (result[line])
	// {
	// 	printf("%d: %s", line, result[line]);
	// 	// printf("%s", result[line]);
	// 	line++;
	// }
	free(result);
	return (0);
}

// char	**


// int parse_map(t_game *game, char *str)
// {

// 	return (0);
// }