/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:34:19 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/24 20:58:33 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <signal.h>
#include "../lib/libft/libft.h"

static int	get_pid(char *s)
{
	int	pid;

	pid = ft_atoi(s);
	write(1, "Client started... Sent pid : ", 30);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	return (pid);
}

static void	kill_error(void)
{
	write(1, "check pid or signo!\n", 21);
	exit(1);
}

static void	send_signal(pid_t pid, char *s)
{
	int	bit_mask;
	int	kill_check;
	unsigned char	res;

	while (*s)
	{
		res = 0;
		bit_mask = 1;
		while (bit_mask < UCHAR_MAX)
		{
			if (*s & bit_mask)
			{
				kill_check = kill(pid, SIGUSR2);
				res |= bit_mask;
			}
			else
				kill_check = kill(pid, SIGUSR1);
			if (kill_check == -1)
				kill_error();
			bit_mask = bit_mask << 1;
			usleep(1);
		}
		s++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*s;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	pid = get_pid(argv[1]);
	send_signal(pid, argv[2]);
	return (0);
}
