/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:17:55 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/26 10:35:30 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_struct	*ps;

	if (ac < 2)
		ft_exit("Error", 1);
	ps = wrmalloc(sizeof(t_struct));
	parse(av, ps, 0);
	if (is_sort(ps))
		ft_exit("Error", 0);
	else if (ps->size <= 5)
		mini_sort(ps);
	else
	{
		ps->min = sort_long_tab(ps);
		ps->increment = define_plages(ps);
		ps->push = ps->increment;
		ps->start = ps->min[0];
		ps->end = ps->min[ps->increment];
		empty_stack_a(ps, 0);
		if (!(fill_sort_stack_b(ps)))
			ft_exit("Error sort", 1);
	}
	/*ps->debug = 1;
	print_stack(ps, "LAST", -1);*/
	if (!is_sort(ps))
		ft_exit("Error", 1);
	wrdestroy();
	return (0);
}
