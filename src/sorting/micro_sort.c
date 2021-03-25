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

int micro_sort(t_struct *ps)
{
	int i;

	i = 0;

	if (is_top_max(ps->lst_a))
	{
		reverse_rotate(ps->lst_a);
		print_stack(ps, "rra");
		i++;
	}
	if (is_max(ps->lst_a, (*ps->lst_a)->next))
	{
		reverse_rotate(ps->lst_a);
		print_stack(ps, "rra");
		i++;
	}
	if ((*ps->lst_a)->content > (*ps->lst_a)->next->content)
	{
		swap(ps->lst_a);
		print_stack(ps, "sa");
		i++;
	}
	return (i);
}