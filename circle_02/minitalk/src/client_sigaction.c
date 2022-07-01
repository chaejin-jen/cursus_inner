/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_sigaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:29:37 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/01 08:39:24 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		write(1, "Send String to Server [SUCCESS]\n", 33);
}
