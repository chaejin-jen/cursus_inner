/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/29 10:36:45 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		start_server(int argc, int pid);
static void		set_sigaction(struct sigaction *sa_ptr);
static pid_t	set_client(pid_t si_pid, int signo);
static void		signal_catcher(int signo, siginfo_t *info, void *context);

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
	(*sa_ptr).sa_sigaction = signal_catcher;
	sigemptyset(&(*sa_ptr).sa_mask);
	if (sigaction(SIGUSR1, sa_ptr, 0) == -1)
		exception("signal(SIGUSR1) error");
	if (sigaction(SIGUSR2, sa_ptr, 0) == -1)
		exception("signal(SIGUSR2) error");
}

/*
static void	signal_catcher(int signo, siginfo_t *info, void *context)
{
	//static pid_t			client_pid = 0;
	static int				bit_mask = 1;
	static unsigned char	res = 0;

	context = (void *)context;
	if ((info->si_pid == 0 ) && (signo == SIGUSR1 || signo == SIGUSR2))
		write(1, "\033[1;33msi_pid = 0\n\033[0m", 23);
	if (info->si_pid != 0 && (signo == SIGUSR1 || signo == SIGUSR2))
	{
		//if (client_pid == 0)
		//	client_pid = info->si_pid;
		//if (client_pid == info->si_pid)
		//{
		//	if (signo == SIGUSR2)
		//		res += bit_mask;
		//	bit_mask = bit_mask << 1;
		//}
		if (signo == SIGUSR2)
			res += bit_mask;
		bit_mask = bit_mask << 1;
	}
	if (bit_mask > UCHAR_MAX)
	{
		//if (client_pid != 0 && res == UCHAR_MAX)
		//{
		//	//write(1, &res, 1);
		//	write(1, " : 11111111\n", 12);
		//}
		//else if (client_pid != 0 && res == 0)
		//{
		//	write(1, "00000000\n", 9);
		//	client_pid = 0;
		//}
		if (res > 31 || res == '\n' || res == '\t')
			write(1, &res, 1);
		bit_mask = 1;
		res = 0;
	}
}
*/

static pid_t	set_client(pid_t si_pid, int signo)
{
	if (kill(si_pid, signo) == -1)
		exception("INVALID PID");
	return (si_pid);
}

static void	signal_catcher(int signo, siginfo_t *info, void *context)
{
	static pid_t			client_pid = 0;
	static int				bit_mask = 1;
	static unsigned char	res = 0;

	context = (void *)context;
	if (info->si_pid != 0 && (signo == SIGUSR1 || signo == SIGUSR2))
	{
		if (client_pid == 0)
			client_pid = set_client(info->si_pid, SIGUSR2);
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
		if (res > 31 || res == '\n' || res == '\t')
			write(1, &res, 1);
		ft_putnbr_fd(client_pid, 1);
		ft_putnbr_fd((int)res, 1);
		write(1, "\n", 1);
		if (res == 0)
		{
			if (kill(client_pid, SIGUSR2) == -1)
				exception("INVALID PID");
			client_pid = 0;
		}
		else
		{
			if (kill(client_pid, SIGUSR2) == -1)
				exception("INVALID PID");
		}
		bit_mask = 1;
		res = 0;
		usleep(100);
	}
}
