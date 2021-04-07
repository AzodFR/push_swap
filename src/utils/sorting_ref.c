/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ref.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:37:47 by thjacque          #+#    #+#             */
/*   Updated: 2021/04/07 15:37:47 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*sort_long_tab(t_struct *ps, int i)
{
	long	*min;
	t_list	*temp;
	long	tmp;

	min = wrmalloc(lst_size(ps->lst_a) * sizeof(long));
	temp = *(ps->lst_a);
	while (temp)
	{
		min[++i] = (long)temp->content;
		temp = temp->next;
	}
	i = 0;
	while (i < ps->size - 1)
	{
		if (min[i] > min[i + 1])
		{
			tmp = min[i];
			min[i] = min[i + 1];
			min[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (min);
}
