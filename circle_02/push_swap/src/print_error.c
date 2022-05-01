/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:47:58 by chaejkim          #+#    #+#             */
/*   Updated: 2022/04/28 14:15:47 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_list *lst)
{
	if (lst != NULL)
		ft_lstclear(&lst, ft_del);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
