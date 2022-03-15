/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:37:52 by chaejkim          #+#    #+#             */
/*   Updated: 2022/01/07 09:04:12 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <unistd.h>
#include "libft.h"

int	main(void)
{
	// char	*s
	// char	*s2;

	// s1 = "abcdef";
	// s2 = "abdsfcdef";
	// printf("%d\n", ft_strlen(s1));
	// printf("%d\n", ft_strlen(s2));

	// ft_strncmp(s1, s2, 5);
	/*
	void	*vp = "abcdefghijklnmopqrstuvwxyz";
	char	*cp = "abcdefghijklnmopqrstuvwxyz";
	int		i = -1;
	
	while (++i < 28)
	{
		write(1, vp + i, 1);
		write(1, " ", 1);
		write(1, cp + i, 1);
		write(1, " ", 1);
	}
	*/

	char	*str = STRING_1;
	char	buff1[0xF00] = STRING_2;
	char	buff2[0xF00] = STRING_2;
	size_t	max = strlen(STRING_1) + strlen(STRING_2);

	strlcat(buff1, str, max);
	ft_strlcat(buff2, str, max);
}
