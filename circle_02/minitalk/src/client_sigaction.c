/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_sigaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:29:37 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/29 21:31:05 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_string(pid_t server_pid, char *s)
{
	int	bit_mask;
	int	signo;

	while (*s)
	{
		bit_mask = 1;
		while (bit_mask < UCHAR_MAX)
		{
			usleep(100);
			signo = SIGUSR1;
			if (*s & bit_mask)
				signo = SIGUSR2;
			if (kill(server_pid, signo) == -1)
				exception("INVALID PID");
			bit_mask = bit_mask << 1;
		}
		pause();
		s++;
	}
}

void	client_sigaction(int signo, siginfo_t *info, void *context)
{
	static pid_t	server_pid = 0;

	(void)context;
	if (signo == SIGUSR2 && info->si_pid != 0)
	{
		if (server_pid == 0)
		{
			server_pid = info->si_pid;
			write(1, "Connect to Server [SUCCESS]\n", 29);
			return ;
		}
	}
	if (signo == SIGUSR1 && server_pid != 0 && server_pid == info->si_pid)
	{
		write(1, "Send String to Server [SUCCESS]\n", 33);
		exit(0);
	}
}