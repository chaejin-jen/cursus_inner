/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:19 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/24 13:45:05 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"

static void	send_signal(pid_t pid, int cnt)
{
	while (--cnt != -1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{	
			/* Handle error */;
		}
		
		// usleep(1);
	}
	if (kill(pid, SIGUSR2) == -1)
	{
		/* Handle error */;
	}
	
	// if (kill(pid, SIGUSR2) == -1)
	// 	kill_error();
	// if (kill(pid, SIGUSR1) == -1)
	// 	kill_error();
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		s_i;
	char	*s;
	int		sig_cnt;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	pid = ft_atoi(*(argv + 1));
	write(1, "Client started... Sent pid : ", 30);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	s = *(argv + 2);
	s_i = 0;
	while (*s)
	{
		sig_cnt = (int)*s;
		send_signal(pid, sig_cnt);
		s++;
	}
	while (1)
		pause();
	return (0);
}
