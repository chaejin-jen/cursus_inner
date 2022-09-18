/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:54:57 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/09 15:07:45 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(char *msg)
{
	int	len;

	len = 0;
	while (*(msg + len))
		len++;
	write(2, "\033[0;31mERROR : ", 16);
	write(2, msg, len);
	write(2, "\n\033[0m", 6);
	return (-1);
}
