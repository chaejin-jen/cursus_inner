/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_sigaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:25:36 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/29 22:11:50 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static pid_t	set_client(t_list **pid_lst, pid_t new_pid)
{
	pid_t	*client_pid;
	t_list	*new_lst;

	if (**pid_lst == 0 || (pid_t)(**pid_lst) != new_pid)
	{
		client_pid = malloc(sizeof(pid_t));
		if (client_pid == NULL)
			exception("malloc error (client_pid)");
		*client_pid = new_pid;
		new_lst = ft_lstnew(client_pid);
		if (new_lst == NULL)
			exception("malloc error (pid_lst)");
		ft_lstadd_back(pid_lst, new_lst)	
	}	
	if (signo == SIGUSR2)
	{
		write(1, "\nClient PID : ", 14);
		ft_putnbr_fd (si_pid, 1);
		write(1, "\n", 1);	
	}
	if (kill(si_pid, signo) == -1)
		exception("INVALID PID");
	return (si_pid);
}

static void	respond(pid_t *client_pid, int *bit_mask, unsigned char *res)
{
	if (*res > 31 || *res == '\n' || *res == '\t')
		write(1, res, 1);
	*bit_mask = 1;
	if (*res == 0)
	{
		if (kill(*client_pid, SIGUSR1) == -1)
			exception("INVALID PID");
		*client_pid = 0;
		return ;
	}
	*res = 0;
	if (kill(*client_pid, SIGUSR2) == -1)
		exception("INVALID PID");
}

void	server_sigaction(int signo, siginfo_t *info, void *context)
{
	static t_list			*pid_lst = 0;
	// pid_t					*client_pid = 0;
	static int				bit_mask = 1;
	static unsigned char	res = 0;

	context = (void *)context;
	if (info->si_pid != 0 && (signo == SIGUSR1 || signo == SIGUSR2))
	{
		set_client(&pid_lst, info->si_pid);
		if (client_pid == info->si_pid)
		{
			if (signo == SIGUSR2)
				res += bit_mask;
			bit_mask = bit_mask << 1;
		}
		else
			set_client(info->si_pid, SIGUSR1);
	}
	if (bit_mask > UCHAR_MAX)
		respond(&client_pid, &bit_mask, &res);
}
