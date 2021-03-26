/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:13:20 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 18:31:41 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	print_one(t_list **elem)
{
	int	size;

	size = 0;
	if (*elem)
		size = printf("%ld", (long)(*elem)->content);
	printf("%*s", 21 - size, " ");
	if (*elem)
		(*elem) = (*elem)->next;
}

void	print_stack(t_struct *ps, char *last)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;

	if (ps->debug)
	{
		i = -1;
		tmp = *(ps->lst_a);
		tmp2 = *(ps->lst_b);
		printf("\x1b[2J _____________________ _____________________\n");
		printf("|\e[92m%-21s\e[0m|\e[93m%21s\e[0m|\n", "STACK", "TMP");
		printf("|_____________________|_____________________|\n");
		while (++i < ps->size)
		{
			printf("|");
			print_one(&tmp);
			printf("|");
			print_one(&tmp2);
			printf("|\n");
		}
		printf("|_____________________ _____________________|\n");
	}
	if (ps->color)
		printf("Last Operation: \e[95m%s\e[0m\n", last);
	else
		printf("%s\n", last);
	if (ps->debug)
		usleep(1000000);
}
