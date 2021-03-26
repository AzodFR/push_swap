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
		ft_exit(ARGS_N, 1);
	ps = wrmalloc(sizeof(t_struct));
	parse(av, ps, 0, 0);
	if (is_sort(ps))
		ft_exit(A_SORTED, 0);
	else if (ps->size <= 3)
		micro_sort(ps);
	else if (ps->size == 5)
		mini_sort(ps);
	else
		ft_exit(FAILED, 1);
	if (is_sort(ps))
		ft_exit(SUCCESS, 0);
	ft_exit(FAILED, 1);
	return (0);
}
