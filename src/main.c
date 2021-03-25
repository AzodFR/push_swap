/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:17:55 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 18:28:43 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_struct	*ps;
	int i;

	if (ac < 2)
		ft_exit(ARGS_N, 1);
	ps = wrmalloc(sizeof(t_struct));
	parse(av, ps, 0, 0);
	if (ps->debug)
		printf("size: %d\ndebug: %d\ncolor: %d\n", ps->size, ps->debug, ps->color);

	print_stack(ps, "sa");
	while ((*ps->lst_a))
	{
		i = 0;
		while (i != 214748360)
			i++;
		push(ps->lst_b, ps->lst_a);
		print_stack(ps, "sa");
	}
	ft_exit(SUCCESS, 0);
	return (0);
}
