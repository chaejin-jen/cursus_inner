/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sigaction_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:10:28 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/01 14:33:32 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	set_sigaction(struct sigaction *sa_ptr,
						void (*handler)(int, siginfo_t *, void *))
{
	(*sa_ptr).sa_flags = SA_SIGINFO;
	(*sa_ptr).sa_sigaction = handler;
	sigemptyset(&(*sa_ptr).sa_mask);
	if (sigaction(SIGUSR1, sa_ptr, 0) == -1)
		exception("signal(SIGUSR1) error");
	if (sigaction(SIGUSR2, sa_ptr, 0) == -1)
		exception("signal(SIGUSR2) error");
}
