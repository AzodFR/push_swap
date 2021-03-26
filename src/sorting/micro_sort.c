/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:35:43 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 18:52:09 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_max(t_list **lst, t_list *max)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp != max && tmp->content > max->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void micro_sort(t_struct *ps)
{
	if (is_top_max(ps->lst_a))
		reverse_rotate(ps->lst_a, ps, 1, 0);
	if (is_max(ps->lst_a, (*ps->lst_a)->next))
		reverse_rotate(ps->lst_a, ps, 1, 0);
	if ((*ps->lst_a)->content > (*ps->lst_a)->next->content)
		swap(ps->lst_a, ps, 1, 0);
}