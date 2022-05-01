/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:52:29 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/23 22:59:14 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096 // 4096
# endif

int		index_nl(char *s);
//size_t	ft_strlen(const char *s);
//void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strndup(const char *s1, size_t n);
//char	*ft_strjoin(const char *s1, const char *s2);
char	*get_next_line(int fd);

#endif