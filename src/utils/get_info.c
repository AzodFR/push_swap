#include "push_swap.h"

int is_max(t_list **lst, t_list *max)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp != max && tmp->content > max->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int is_min(t_list **lst, t_list *min)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp != min && tmp->content < min->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

long get_max(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		if (is_max(lst, tmp))
			return ((long)tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

long get_min(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		if (is_min(lst, tmp))
			return ((long)tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

int get_min_pos(t_list **lst)
{
	t_list *tmp;
	int i;

	i = -1;
	tmp = *lst;
	while (tmp)
	{
		++i;
		if (is_min(lst, tmp))
			return (i);
		tmp = tmp->next;
	}
	return (i);
}

long get_middle(t_list **lst)
{
    long total;
    t_list *tmp;
    int size;

    size = lst_size(lst);
    if (!size)
        return (0);
    tmp = *lst;
    total = 0;
    while (tmp)
    {
        total += (long)tmp->content;
        tmp = tmp->next;
    }
    return ((long)(total / size + 0.5));
}

t_list *get_at_pos(t_list **lst, int n)
{
	int i;
	t_list *tmp;

	i = -1;
	tmp = *lst;
	while (tmp && ++i < n)
		tmp = tmp->next;
	if (tmp)
		return (tmp);
	return (NULL);
}