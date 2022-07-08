/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:21 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/29 21:29:00 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	start_server(int argc, int pid)
{
	if (argc != 1)
		write(1, "\033[1;33mWARNING : ./server\n\033[0m", 31);
	write(1, "Server PID : ", 14);
	ft_putnbr_fd(pid, 1);
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa_req;

	argv = (char **)argv;
	server_pid = getpid();
	start_server(argc, server_pid);
	set_sigaction(&sa_req, server_sigaction);
	while (1)
		pause();
	return (0);
}
