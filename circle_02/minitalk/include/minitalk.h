/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:56:39 by chaejkim          #+#    #+#             */
/*   Updated: 2022/06/30 18:27:34 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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
