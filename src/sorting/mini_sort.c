/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:35:43 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 18:52:09 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_top_max(t_list **lst)
{
    t_list *tmp;
    t_list *tmp2;

    tmp = *lst;
    tmp2 = tmp->next;
    while (tmp2)
    {
        if (tmp->content < tmp2->content)
            return (0);
        tmp2 = tmp2->next;
    }
    return (1);
}

void minis_sort2(t_struct *ps)
{
	if ((*ps->lst_a)->content > (*ps->lst_a)->next->content )
	{
		if ((*ps->lst_a)->content < (*ps->lst_a)->next->next->content)
			swap(ps->lst_a, ps, 1, 0);
		else
		{
			reverse_rotate(ps->lst_a, ps, 1, 0);
			swap(ps->lst_a, ps, 1, 0);
			rotate(ps->lst_a, ps, 1, 0);
			rotate(ps->lst_a, ps, 1, 0);
		}
	}
}

void minis_sort3(t_struct *ps)
{
	if ((*ps->lst_a)->content > (*ps->lst_a)->next->content )
	{
		if ((*ps->lst_a)->content < (*ps->lst_a)->next->next->content)
			swap(ps->lst_a, ps, 1, 0);
		else if ((*ps->lst_a)->content < (*ps->lst_a)->next->next->next->content)
		{
			reverse_rotate(ps->lst_a, ps, 1, 0);
			swap(ps->lst_a, ps, 1, 0);
			rotate(ps->lst_a, ps, 1, 0);
			rotate(ps->lst_a, ps, 1, 0);
		}
		else
		{

		}
	}
}

void mini_sort(t_struct *ps)
{

	push(ps->lst_b, ps->lst_a, ps, 1);
	push(ps->lst_b, ps->lst_a, ps, 1);
	micro_sort(ps);
	if (!is_top_max(ps->lst_b))
		rotate(ps->lst_b, ps, 1, 1);
	push(ps->lst_a, ps->lst_b, ps, 0);
	if (is_top_max(ps->lst_a))
		rotate(ps->lst_a, ps, 1, 0);
	minis_sort2(ps);
	if ((*ps->lst_b)->content > (*ps->lst_a)->next->content)
	{
		push(ps->lst_b, ps->lst_a, ps, 1);
		swap(ps->lst_b, ps, 1, 1);
		push(ps->lst_a, ps->lst_b, ps, 0);
		swap(ps->lst_a, ps, 1, 0);
	}
	push(ps->lst_a, ps->lst_b, ps, 0);
	micro_sort(ps);
	//minis_sort2(ps);
}