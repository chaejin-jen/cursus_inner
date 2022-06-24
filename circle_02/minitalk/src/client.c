/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:19 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/24 13:46:20 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <signal.h>
#include "../lib/libft/libft.h"
// #include "libft.h"

static void kill_error(void)
{
	write(1, "check pid or signo!\n", 21);
	exit(1);
}

static void	send_signal(pid_t pid, unsigned char c)
{
	int	bit_num;
	int	kill_check;

	bit_num = 1;
	while (bit_num < UCHAR_MAX)
	{
		usleep(1);
		if (c && bit_num)
			kill_check = kill(pid, SIGUSR2);
		else
			kill_check = kill(pid, SIGUSR1);
		if (kill_check == -1)
			kill_error();
		bit_num *= 2;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*s;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	pid = ft_atoi(*(argv + 1));
	write(1, "Client started... Sent pid : ", 30);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	s = argv[2];
	while (*s)
	{
		send_signal(pid, (unsigned char)*s);
		s++;
	}
	return (0);
}
