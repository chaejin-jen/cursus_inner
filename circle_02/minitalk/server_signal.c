/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/05/02 05:03:11 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../lib/libft/libft.h"

static void	catch_sigusr(int signo)
{
	unsigned char	u_c;

	if (signo == SIGUSR1)
		write(1, "SIGUSR1 Receive\n", 17);
	if (signo == SIGUSR2)
		write(1, "SIGUSR2 Receive\n", 17);
	ft_putnbr_fd(signo, 1);
	write(1, "\n", 1);
	// signal(SIGINT,SIG_DFL);
}

int	main(void)
{
	pid_t				pid;

	pid = getpid();
	write(1, "Server started...  My pid is ", 30);
	ft_putnbr_fd((int)getpid(), 1);
	write(1, "\n", 1);
	if (signal(SIGUSR1, (void *) catch_sigusr) == SIG_ERR)
	{
		/* Handle error */;
		write(1, "catch_sigusr error\n", 20);
	}
	if (signal(SIGUSR2, (void *) catch_sigusr) == SIG_ERR)
	{
		/* Handle error */;
		write(1, "catch_sigusr error\n", 20);
	}
	while (1)
		sleep(1);
		// pause();
	return (0);
}