/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/05/02 04:41:35 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../lib/libft/libft.h"

static void	catch_sigusr(int signo)
{
	unsigned char	u_c;

	if (ft_isprint(signo))
	{
		u_c = (unsigned char)signo;
		write(1, &u_c, 1);
	}
	if (signo == SIGUSR1)
		write(1, "SIGUSR1 Receive\n", 17);
	else
		write(1, "WDFFFFF\n", 9);
	ft_putnbr_fd(signo, 1);
	write(1, "\n", 1);
	// signal(SIGINT,SIG_DFL);
}

static void	handler(int signum)
{
	unsigned char	u_c;

	if (ft_isprint(signum))
	{
		u_c = (unsigned char)signum;
		write(1, &u_c, 1);
	}
	/* Take appropriate actions for signal delivery */
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	write(1, "Server started...  My pid is ", 30);
	ft_putnbr_fd((int)getpid(), 1);
	write(1, "\n", 1);
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	// if (signal(SIGUSR1, (void *) catch_sigusr) == SIG_ERR)
	// {
	// 	/* Handle error */;
	// 	write(1, "catch_sigusr error\n", 20);
	// }
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