/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:56:39 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/01 14:33:58 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include "libft.h"

void	exception(char *msg);
void	set_sigaction(struct sigaction *sa_ptr,
			void (*handler)(int, siginfo_t *, void *));
void	server_sigaction(int signo, siginfo_t *info, void *context);
void	client_sigaction(int signo, siginfo_t *info, void *context);

#endif
