/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:12:23 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/29 08:20:42 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



pid_t	start_to_catch(pid_t si_pid)
{
	if (kill(si_pid, SIGUSR2) == -1)
		exception("INVALID PID");
	return (si_pid);
}

pid_t	end_to_catch(pid_t si_pid)
{
	if (kill(si_pid, SIGUSR1) == -1)
		exception("INVALID PID");
	return (si_pid);
}

void	signal_catcher(int signo, siginfo_t *info, void *context)
{
	static pid_t			client_pid = 0;
	static int				bit_mask = 1;
	static unsigned char	res = 0;

	context = (void *)context;
	if (info->si_pid != 0 && (signo == SIGUSR1 || signo == SIGUSR2))
	{
		if (client_pid == 0)
			client_pid = conect_to_(info->si_pid);
		if (client_pid == info->si_pid)
		{
			if (signo == SIGUSR2)
				res += bit_mask;
			bit_mask = bit_mask << 1;
		}
	}
	if (bit_mask > UCHAR_MAX)
	{
		if (res == 0)
			client_pid = end_to_catch(info->si_pid);
		else if (res > 31 || res == '\n' || res == '\t')
			write(1, &res, 1);
		bit_mask = 1;
		res = 0;
	}
}
