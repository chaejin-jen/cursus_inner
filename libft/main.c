/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:37:52 by chaejkim          #+#    #+#             */
/*   Updated: 2021/11/17 17:37:53 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libc.h"

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "abcdef";
	s2 = "abdsfcdef";
	printf("%d\n", ft_strlen(s1));
	printf("%d\n", ft_strlen(s2));

	// ft_strncmp(s1, s2, 5);
}
