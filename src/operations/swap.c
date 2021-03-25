/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:56:00 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 16:40:40 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*tmp;

	if (lst_size(lst) < 2)
		return ;
	tmp = *lst;
	tmp = tmp->next;
	(*lst)->next = tmp->next;
	tmp->next = (*lst);
	*lst = tmp;
}

void	double_swap(t_struct **ps)
{
	swap((*ps)->lst_a);
	swap((*ps)->lst_b);
}
