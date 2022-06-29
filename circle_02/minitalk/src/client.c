/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:19 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/29 10:38:24 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	set_sigaction(struct sigaction *sa_ptr);
static void	check_connection(pid_t server_pid, int signo);
static void	send_string(pid_t server_pid, char *s);
static void	signal_client(int signo, siginfo_t *info, void *context);

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	int					arg_i;
	struct sigaction	sa_req;

	if (argc < 3)
		exception("INVALID ARGUMENTS");
	server_pid = ft_atoi(argv[1]);
	set_sigaction(&sa_req);
	check_connection(server_pid, SIGUSR2);
	arg_i = 1;
	while (++arg_i < argc)
		send_string(server_pid, argv[arg_i]);
	check_connection(server_pid, SIGUSR1);
	return (0);
}

static void	set_sigaction(struct sigaction *sa_ptr)
{
	(*sa_ptr).sa_flags = SA_SIGINFO;
	(*sa_ptr).sa_sigaction = signal_client;
	sigemptyset(&(*sa_ptr).sa_mask);
	if (sigaction(SIGUSR1, sa_ptr, 0) == -1)
		exception("signal(SIGUSR1) error");
	if (sigaction(SIGUSR2, sa_ptr, 0) == -1)
		exception("signal(SIGUSR2) error");
}

static void	check_connection(pid_t server_pid, int signo)
{
	int	i;

	if (signo == SIGUSR2)
	{
		write(1, "Client PID : ", 14);
		ft_putnbr_fd((int)getpid(), 1);
		write(1, "\nServer PID : ", 15);
		ft_putnbr_fd(server_pid, 1);
	}
	write(1, "\n", 1);
	i = 0;
	while (i++ < 8)
	{
		if (kill(server_pid, signo) == -1)
			exception("INVALID PID");
	}
	pause();
	write(1, "cococococo\n", 12);
}

static void	send_string(pid_t server_pid, char *s)
{
	int	bit_mask;
	int	signo;

	ft_putstr_fd(s, 1);
	while (*s)
	{
		bit_mask = 1;
		while (bit_mask < UCHAR_MAX)
		{
			signo = SIGUSR1;
			if (*s & bit_mask)
				signo = SIGUSR2;
			if (kill(server_pid, signo) == -1)
				exception("INVALID PID");
			//bit_mask <<= 1;
			bit_mask = bit_mask << 1;
			usleep(500);
		}
		pause();
		usleep(100);
		s++;
	}
}

static void	signal_client(int signo, siginfo_t *info, void *context)
{
	static pid_t	server_pid = 0;

	(void)context;
	if (signo == SIGUSR2 && info->si_pid != 0)
	{
		if (server_pid == 0)
		{
			server_pid = info->si_pid;
			write(1, "Connect to Server [SUCCESS]\n", 29);
		}
		else
			write(1, "*\n", 2);
	}
	if (server_pid != 0 && server_pid == info->si_pid && signo == SIGUSR1)
	{
		write(1, "Send String to Server [SUCCESS]\n", 33);
		exit(0);
	}
}
