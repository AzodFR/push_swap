/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:17:55 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 16:59:13 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_struct	*ps;
	t_list		*tmp;

	if (ac < 2)
		ft_exit(ARGS_N, 1);
	ps = wrmalloc(sizeof(t_struct));
	parse(av, ps, 0, 0);
	printf("size: %d\ndebug: %d\ncolor: %d\n", ps->size, ps->debug, ps->color);
	tmp = *ps->lst_a;
	while (tmp)
	{
		printf("%ld\n", (long)tmp->content);
		tmp = tmp->next;
	}
	ft_exit(SUCCESS, 0);
	return (0);
}
