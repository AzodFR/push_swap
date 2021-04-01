#include "push_swap.h"

int		fill_sort_stack_b(t_struct *ps)
{
	while (lst_size(ps->lst_b) != 0)
	{
		if (lst_size(ps->lst_b) / 2 >= get_pos(ps->lst_b, get_max(ps->lst_b)))
		{
			while (!is_top_max(ps->lst_b))
				rotate(ps->lst_b, ps, 1, 0);
			push(ps->lst_a, ps->lst_b, ps, 1);
		}
		if (lst_size(ps->lst_b) / 2 < get_pos(ps->lst_b, get_max(ps->lst_b)))
		{
			while (!is_top_max(ps->lst_b))
				reverse_rotate(ps->lst_b, ps, 1, 0);
			push(ps->lst_a, ps->lst_b, ps, 1);
		}
	}
	return (1);
}

void	empty_stack_a(t_struct *ps, int p)
{

	while (lst_size(ps->lst_a) != 0 && (p = find_num_plage(ps, ps->start, ps->end) < 900000))
	{
		if (p == IMPOSSIBLE && raise_plage(ps))
			continue ;
		if (p == lst_size(ps->lst_a) - 1)
			push(ps->lst_b, ps->lst_a, ps, 0);
		else if (lst_size(ps->lst_a) / 2 <= p)
		{
			while (p-- >= 0)
				rotate(ps->lst_a, ps, 1, 1);
			push(ps->lst_b, ps->lst_a, ps, 0);
		}
		else if (lst_size(ps->lst_a) / 2 > p)
		{
			if (!p)
			{
				reverse_rotate(ps->lst_a, ps, 1, 1);
				push(ps->lst_b, ps->lst_a, ps, 0);
				continue ;
			}
			while (p-- >= 0)
				reverse_rotate(ps->lst_a, ps, 1, 1);
			push(ps->lst_b, ps->lst_a, ps, 0);
		}
	}
}

long			find_num_plage(t_struct *ps, long start, long end)
{
	int		i;
	int		first_find;

	first_find = IMPOSSIBLE;
	i = -1;
	while (get_at_pos(ps->lst_a, ++i))
		if ((long)get_at_pos(ps->lst_a, i)->content >= start && (long)get_at_pos(ps->lst_a, i)->content <= end)
		{
			first_find = i;
			break ;
		}
	if (first_find == IMPOSSIBLE)
		return (IMPOSSIBLE);
	i = lst_size(ps->lst_a);
	while (--i > 0)
		if ((long)get_at_pos(ps->lst_a, i)->content >= start && (long)get_at_pos(ps->lst_a, i)->content <= end)
		{
			if (first_find == 0 && i == lst_size(ps->lst_a) - 1)
				return (i);
			else
				return (first_find);
		}
	return (first_find);
}


long		raise_plage(t_struct *ps)
{
	ps->start = ps->min[ps->push];
	if (ps->push + ps->increment > ps->size)
		ps->push = ps->size - 1;
	else
		ps->push += ps->increment;
	ps->end = ps->min[ps->push];
	return (1);
}