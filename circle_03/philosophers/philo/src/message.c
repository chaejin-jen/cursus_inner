/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:54:57 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/08 14:01:15 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(char *msg)
{
	int	len;

	len = 0;
	while (*(msg + len))
		len++;

	write(1, "\033[0;31mERROR : ", 16);
	write(1, msg, len);
	write(1, "\n\033[0m", 6);
	return (-1);
}
