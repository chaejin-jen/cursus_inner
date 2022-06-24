/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/24 13:49:00 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../lib/libft/libft.h"

static void	handler(int signo)
{
	static int				received;
	static unsigned char	req;

	if (signo == SIGUSR1 || signo == SIGUSR2)
	{
		if (received == 0)
			req = 0;
		received++;
		if (received == 8)
		{
			if (ft_isprint(req))
				write(1, &req, 1);
			else
				write(1, "(unprintable)", 14);
			received = 0;
		}
	}
	if (signo == SIGUSR2)
		req |= 1 << received;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa_req;
	// unsigned char		req;

	pid = getpid();
	write(1, "Server started...  My pid is ", 30);
	ft_putnbr_fd((int)getpid(), 1);
	write(1, "\n", 1);
	// req = 0;
	sa_req.sa_handler = handler;
	sigemptyset(&sa_req.sa_mask);
	sigaction(SIGUSR1, &sa_req, NULL);
	sigaction(SIGUSR2, &sa_req, NULL);
	while (1)
	{
		// sleep(1);
		pause();
	}
	return (0);
}