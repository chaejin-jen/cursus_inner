/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/29 15:16:26 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		start_server(int argc, int pid);
static void		set_sigaction(struct sigaction *sa_ptr);
static pid_t	set_client(pid_t si_pid, int signo);
static void		signal_server(int signo, siginfo_t *info, void *context);

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa_req;

	argv = (char **)argv;
	server_pid = getpid();
	start_server(argc, server_pid);
	set_sigaction(&sa_req);
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
	write(1, "\n", 1);
}

static void	set_sigaction(struct sigaction *sa_ptr)
{
	(*sa_ptr).sa_flags = SA_SIGINFO;
	(*sa_ptr).sa_sigaction = signal_server;
	sigemptyset(&(*sa_ptr).sa_mask);
	if (sigaction(SIGUSR1, sa_ptr, 0) == -1)
		exception("signal(SIGUSR1) error");
	if (sigaction(SIGUSR2, sa_ptr, 0) == -1)
		exception("signal(SIGUSR2) error");
}

static pid_t	set_client(pid_t si_pid, int signo)
{
	if (kill(si_pid, signo) == -1)
		exception("INVALID PID");
	usleep(10);
	return (si_pid);
}

static void	signal_server(int signo, siginfo_t *info, void *context)
{
	static pid_t			client_pid = 0;
	static int				bit_mask = 1;
	static unsigned char	res = 0;

	context = (void *)context;
	if (info->si_pid != 0 && (signo == SIGUSR1 || signo == SIGUSR2))
	{
		if (client_pid == 0)
		{
			client_pid = set_client(info->si_pid, SIGUSR2);
			usleep(10);
			return ;
		}	
		if (client_pid == info->si_pid)
		{
			if (signo == SIGUSR2)
				res += bit_mask;
			//bit_mask <<= 1;
			bit_mask = bit_mask << 1;
		}
	}
	if (bit_mask > UCHAR_MAX)
	{
		write(1, "\n", 1);
		ft_putnbr_fd(client_pid, 1);
		write(1, "\n", 1);
		if (res > 31 || res == '\n' || res == '\t')
			write(1, &res, 1);
		if (res == 0)
		{
			if (kill(client_pid, SIGUSR1) == -1)
				exception("INVALID PID");
			write(1, "SIGUSR1\n", 9);
			client_pid = 0;
		}
		else
		{
			if (kill(client_pid, SIGUSR2) == -1)
				exception("INVALID PID");
			write(1, "SIGUSR2\n", 9);
		}
		bit_mask = 1;
		res = 0;
		usleep(10);
	}
}
