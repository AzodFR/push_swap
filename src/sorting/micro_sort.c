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

void micro_sort(t_struct *ps)
{
	t_list *tmp;
	
	tmp = *(ps->lst_a);
	if (tmp->content > tmp->next->content && tmp->content < tmp->next->next->content)
		swap(ps->lst_a);
	else if (tmp->content > tmp->next->content && tmp->content > tmp->next->next->content)
		rotate(ps->lst_a);
	else if (tmp->content < tmp->next->content && tmp->content > tmp->next->next->content)
		reverse_rotate(ps->lst_a);
}