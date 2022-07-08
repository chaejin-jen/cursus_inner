/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/29 06:34:35 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../lib/libft/libft.h"

static void	sa_init(struct sigaction sa, int signo, void *handler)
{
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, signo);
}

static void	handler(int signo)
{
	static int		received;
	unsigned char	u_c;

	if (signo == SIGUSR1)
		++received;
	else if (signo == SIGUSR2)
	{
		u_c = (unsigned char)received;
		if (ft_isprint(u_c))
			write(1, &u_c, 1);
		else
			write(1, "(unprintable)", 14);
		received = 0;
	}
}

static void	signal_catcher(int signo, siginfo_t *info, void *context)
{
	static t_sa_data	client = {0, 1, 0};
	ucontext_t			*uct;

	if (info->si_pid != 0 && (signo == SIGUSR1 || signo == SIGUSR2))
	{
		if (client.pid == 0)
			client.pid = info->si_pid;
		if (client.pid == info->si_pid)
		{
			uct = (ucontext_t *)context;
			if (signo == SIGUSR2)
				client.c += client.bit_mask;
			client.bit_mask = client.bit_mask << 1;
		}
	}
	if (client.bit_mask > UCHAR_MAX)
	{
		if (client.pid == 0 && client.c == UCHAR_MAX)
		{
			write(1, &client.c, 1);
			write(1, " : 11111111\n", 12);
		}	//send_client();
		if (client.pid == 0 && client.c == 0)
			write(1, "00000000\n", 9);
		if (client.c > 31 || client.c == '\n' || client.c == '\t')
			write(1, &client.c, 1);
		client.bit_mask = 1;
		client.c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa_received;
	struct sigaction	sa_complete;

	pid = getpid();
	write(1, "Server started...  My pid is ", 30);
	ft_putnbr_fd((int)getpid(), 1);
	write(1, "\n", 1);
	sa_init(sa1, SIGUSR2, sigusr1_handler);
	sa_init(sa2, SIGUSR1, sigusr2_handler);
	sigaction(SIGUSR1, &sa1, )
	if (signal(SIGUSR1, (void *) catch_sigusr) == SIG_ERR)
	{
		/* Handle error */;
		write(1, "catch_sigusr error\n", 20);
	}
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		write(1, "hadler WDFFFFF\n", 16);
	}
	// pause();
	// if (signal(SIGUSR1, (void *) catch_sigusr) == SIG_ERR)
	// {
	// 	/* Handle error */;
	// 	write(1, "catch_sigusr error\n", 20);
	// }
	// if (kill(pid, SIGUSR1) == -1)
	// {
	// 	/* Handle error */;
	// }
	// sleep(1);
	while (1)
		sleep(1);
		// pause();
	return (0);
}
