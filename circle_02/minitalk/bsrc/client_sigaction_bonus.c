/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_sigaction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:29:37 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/01 14:33:25 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
