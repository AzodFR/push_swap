/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:17:55 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 18:55:07 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_struct	*ps;

	if (ac < 2)
		ft_exit(ARGS_N, 1);
	ps = wrmalloc(sizeof(t_struct));
	parse(av, ps, 0, 0);
	if (ps->debug)
		printf("size: %d\ndebug: %d\ncolor: %d\n", ps->size, ps->debug, ps->color);
	micro_sort(ps);
	print_stack(ps, "sa");
	if (is_sort(ps))
		ft_exit(SUCCESS, 0);
	ft_exit(FAILED, 1);
	return (0);
}
