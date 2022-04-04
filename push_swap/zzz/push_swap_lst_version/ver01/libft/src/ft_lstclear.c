/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:34:47 by chaejkim          #+#    #+#             */
/*   Updated: 2022/01/09 16:08:31 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*cur;

	tmp = *lst;
	while (tmp)
	{
		cur = tmp;
		tmp = tmp->next;
		ft_lstdelone(cur, del);
	}
	*lst = NULL;
}
