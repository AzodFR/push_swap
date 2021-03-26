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

int mini_sort(t_struct *ps)
{
    int i;

	push(ps->lst_b, ps->lst_a);
	print_stack(ps, "pb");
	push(ps->lst_b, ps->lst_a);
	print_stack(ps, "pb");
	i = 2;
	i += micro_sort(ps);\
	/*while (lst_size(ps->lst_b) > 0)
	{
		push(ps->lst_a, ps->lst_b);
		print_stack(ps, "pa");
		i++;
	}
	rotate(ps->lst_a);
	print_stack(ps, "ra");
	i++;*/
	/*
		if (!is_top_max(ps->lst_b))
		{
			rotate(ps->lst_b);
			print_stack(ps, "rb"); 
			i++;
		}
		push(ps->lst_a, ps->lst_b);
		print_stack(ps, "pa");
		i++;
		if (is_top_max(ps->lst_a))
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
		push(ps->lst_a, ps->lst_b);
		print_stack(ps, "pa");
			if ((*ps->lst_a)->content > (*ps->lst_a)->next->content)
		{
			swap(ps->lst_a);
			print_stack(ps, "sa"); 
			i++;
		}
		i++;
	}*/
    return (i);
}