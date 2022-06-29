/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:19 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/29 21:47:12 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	set_server_pid(char *s)
{
	int		pid_len;
	int		exception_flag;

	exception_flag = 0;
	while (*s == '0')
		s++;
	pid_len = (int)ft_strlen(s);
	if (pid_len > 5 || pid_len < 3)
		exception_flag = 1;
	while (exception_flag == 0 && --pid_len > -1)
	{
		if (ft_isdigit(*(s + pid_len)) != 1)
			exception_flag = 1;
	}
	if (exception_flag == 1)
		exception("INVALID ARGUMENTS (100 < PID < 99999)");
	return ((pid_t)ft_atoi(s));
}

static void	connect_server(pid_t server_pid)
{
	write(1, "Client PID : ", 14);
	ft_putnbr_fd((int)getpid(), 1);
	write(1, "\nServer PID : ", 15);
	ft_putnbr_fd(server_pid, 1);
	write(1, "\n", 1);
	if (kill(server_pid, SIGUSR2) == -1)
		exception("INVALID PID");
	usleep(100);
}

static void	disconnect_server(pid_t server_pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		if (kill(server_pid, SIGUSR1) == -1)
			exception("INVALID PID");
		usleep(100);
	}
	write(1, "Disconnect\n", 11);
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	int					arg_i;
	struct sigaction	sa_req;

	if (argc < 3)
		exception("INVALID ARGUMENTS (./client <SERVER_PID> <string>)");
	server_pid = set_server_pid(argv[1]);
	set_sigaction(&sa_req, client_sigaction);
	connect_server(server_pid);
	write(1, "connection_started\n", 20);
	arg_i = 1;
	while (++arg_i < argc)
		send_string(server_pid, argv[arg_i]);
	disconnect_server(server_pid);
	return (0);
}
