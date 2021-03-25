/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:04:20 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 16:41:08 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*tmp;

	if (lst_size(lst) < 2)
		return ;
	tmp = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
	lst_push_back(lst, tmp);
}

void	reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lst_size(lst) < 2)
		return ;
	tmp = lst_get_last(lst);
	tmp2 = *lst;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	lst_push_front(lst, tmp);
}

void	double_rotate(t_struct **ps)
{
	rotate((*ps)->lst_a);
	rotate((*ps)->lst_b);
}

void	double_rev_rotate(t_struct **ps)
{
	reverse_rotate((*ps)->lst_a);
	reverse_rotate((*ps)->lst_b);
}