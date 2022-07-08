/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_set_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/29 20:19:50 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		start_server(int argc, int pid);
static pid_t	set_client(pid_t si_pid, int signo);
// static void		respond(pid_t *client_pid, int *bit_mask, unsigned char *res);
static void		signal_server(int signo, siginfo_t *info, void *context);

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa_req;

	argv = (char **)argv;
	server_pid = getpid();
	start_server(argc, server_pid);
	set_sigaction(&sa_req, signal_server);
	while (1)
		pause();
	return (0);
}

static void	start_server(int argc, int pid)
{
	if (argc != 1)
		write(1, "\033[1;33mWARNING : ./server\n\033[0m", 31);
	write(1, "Server PID : ", 14);
	ft_putnbr_fd(pid, 1);
}

static pid_t	set_client(pid_t old_pid, pid_t new_pid)
{
	int		signo;
	pid_t	client_pid;

	if (old_pid == 0)
	{
		signo = SIGUSR2;
		client_pid = new_pid;
		write(1, "\nClient PID : ", 14);
		ft_putnbr_fd (client_pid, 1);
		write(1, "\n", 1);
	}
	else
	{	
		signo = SIGUSR1;
		client_pid = old_pid;
	}
	if (kill(new_pid, signo) == -1)
		exception("INVALID PID");
	return (client_pid);
}

// static void	respond(pid_t *client_pid, int *bit_mask, unsigned char *res)
// {
// 	if (*res > 31 || *res == '\n' || *res == '\t')
// 	{
// 		write(1, "res ", 4);
// 		write(1, res, 1);
// 	}
// 	*bit_mask = 1;
// 	if (*res == 0)
// 	{
// 		if (kill(*client_pid, SIGUSR1) == -1)
// 			exception("INVALID PID");
// 		*client_pid = 0;
// 	}
// 	*res = 0;
// 	if (kill(*client_pid, SIGUSR2) == -1)
// 		exception("INVALID PID");
// }

static void	signal_server(int signo, siginfo_t *info, void *context)
{
	static pid_t			client_pid = 0;
	static int				bit_mask = 1;
	static unsigned char	res = 0;

	context = (void *)context;
	if (info->si_pid != 0 && (signo == SIGUSR1 || signo == SIGUSR2))
	{
		client_pid = set_client(client_pid, info->si_pid);
		if (client_pid == info->si_pid)
		{
			if (signo == SIGUSR2)
				res += bit_mask;
			bit_mask = bit_mask << 1;
		}
		else
			return ;
	}
	if (bit_mask > UCHAR_MAX)
		// respond(&client_pid, &bit_mask, &res);
	{
		if (res > 31 || res == '\n' || res == '\t')
		{
			write(1, "res ", 4);
			write(1, &res, 1);
		}
		bit_mask = 1;
		if (res == 0)
		{
			if (kill(client_pid, SIGUSR1) == -1)
				exception("INVALID PID");
			client_pid = 0;
		}
		res = 0;
		if (kill(client_pid, SIGUSR2) == -1)
			exception("INVALID PID");		
	}
}
