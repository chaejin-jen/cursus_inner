/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/24 21:07:15 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include "../lib/libft/libft.h"

static int	start_server(int argc, int pid)
{
	if (argc != 1)
	{
		write(1, "ERROR : NO ARGMENTS\n", 21);
		return (-1);
	}	
	write(1, "Server started...  My pid is ", 30);
	ft_putnbr_fd((int)pid, 1);
	write(1, "\n", 1);
	return (0);
}

static void	signal_catcher(int signo, siginfo_t *info, void *context)
{
	static int				bit_mask = 1;
	static unsigned char	req = 0;

	if (signo == SIGUSR1 || signo == SIGUSR2)
	{
		if (signo == SIGUSR2)
			req += bit_mask;
		bit_mask = bit_mask << 1;
	}
	if (bit_mask > UCHAR_MAX)
	{
		if (ft_isprint(req))
			write(1, &req, 1);
		else
			write(1, "(unprintable)", 14);
		bit_mask = 1;
		req = 0;
	}
}

static int	set_sinaction(struct sigaction *sa_ptr)
{
	(*sa_ptr).sa_flags = SA_SIGINFO;
	(*sa_ptr).sa_sigaction = signal_catcher;
	sigemptyset(&(*sa_ptr).sa_mask);
	if (sigaction(SIGUSR1, sa_ptr, 0) == -1)
	{
		write (1, "signal(SIGUSR1) error\n", 23);
		return (-1);
	}
	if (sigaction(SIGUSR2, sa_ptr, 0) == -1)
	{
		write (1, "signal(SIGUSR2) error\n", 23);
		return (-1);
	}
	return (0);
}


int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa_req;

	pid = getpid();
	if (start_server(argc, pid) == -1)
		return (-1);
	if (set_sinaction(&sa_req) == -1)
		return (-1);
	while (1)
	{
		pause();
	}
	return (0);
}
