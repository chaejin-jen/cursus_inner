/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:56:39 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/29 17:36:30 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include "libft.h"

# define PID_MIN 100;
# define PID_MAX 99999;

typedef struct s_sa_data
{
	pid_t			pid;
	int				bit_mask;
	unsigned char	c;
}				t_sa_data;

void	exception(char *msg);

#endif
