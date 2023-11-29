/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:00:50 by aperis            #+#    #+#             */
/*   Updated: 2021/12/09 13:59:38 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*clear;

	tmp = *lst;
	while (tmp)
	{
		clear = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = clear;
	}
	*lst = NULL;
}
