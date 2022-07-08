/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_sigaction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:25:36 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/01 15:09:22 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	add_wait_lst(t_list **wait_lst, long content)
{
	t_list	*new_lst;

	new_lst = ft_lstnew((void *)content);
	if (new_lst == NULL)
		exception("malloc error (wait_lst)");
	ft_lstadd_back(wait_lst, new_lst);
}

static pid_t	connect_client(pid_t client_pid, int signo)
{
	write(1, "\nClient PID : ", 14);
	ft_putnbr_fd (client_pid, 1);
	write(1, "\n", 1);
	if (kill(client_pid, signo) == -1)
		exception("INVALID PID (connect client)");
	return (client_pid);
}

static pid_t	pop_wait_lst(t_list **wait_lst)
{
	pid_t	client_pid;
	t_list	*pop_lst;

	pop_lst = *wait_lst;
	client_pid = (pid_t)(long)(pop_lst->content);
	*wait_lst = (*wait_lst)->next;
	ft_lstdelone(pop_lst, ft_del_ptr);
	return (client_pid);
}

static int	respond(pid_t client_pid, int signo)
{
	static int				bit_mask = 1;
	static unsigned char	res = 0;

	if (signo == SIGUSR2)
		res += bit_mask;
	bit_mask = bit_mask << 1;
	if (bit_mask > UCHAR_MAX)
	{
		bit_mask = 1;
		if (res == 0)
		{
			if (kill(client_pid, SIGUSR1) == -1)
				exception("INVALID PID (disconnect client)");
			return (0);
		}
		write(1, &res, 1);
		if (kill(client_pid, SIGUSR2) == -1)
			exception("INVALID PID (res)");
		res = 0;
	}
	return (1);
}

void	server_sigaction(int signo, siginfo_t *info, void *context)
{
	static pid_t	client_pid = 0;
	static t_list	*wait_lst = 0;

	context = (void *)context;
	if (info->si_pid != 0 && (signo == SIGUSR1 || signo == SIGUSR2))
	{
		if (client_pid == 0)
		{
			client_pid = connect_client(info->si_pid, signo);
			return ;
		}
		if (client_pid != info->si_pid)
		{
			add_wait_lst(&wait_lst, info->si_pid);
			return ;
		}
		if (respond(client_pid, signo) == 1)
			return ;
		if (wait_lst == 0)
			client_pid = 0;
		else
			client_pid = connect_client(pop_wait_lst(&wait_lst), signo);
	}
}
