/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/05/02 06:28:32 by chaejkim         ###   ########.fr       */
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