/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:26:39 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 16:40:00 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_lst(void *data)
{
	t_list	*elem;

	elem = wrmalloc(sizeof(t_list));
	elem->content = data;
	elem->next = NULL;
	return (elem);
}

void	lst_push_front(t_list **lst, t_list *elem)
{
	if (!lst)
	{
		*lst = elem;
		return ;
	}
	elem->next = *lst;
	*lst = elem;
}

void	lst_push_back(t_list **lst, t_list *elem)
{
	if (!elem || !lst)
		return ;
	else if ((*lst) == NULL)
		(*lst) = elem;
	else
		lst_push_back(&(*lst)->next, elem);
}

int	lst_size(t_list **lst)
{
	t_list	*tmp;
	int		i;

	tmp = *lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
