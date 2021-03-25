/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:04:50 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 17:02:17 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_struct(t_struct *ps)
{
	ps->lst_a = wrmalloc(sizeof(t_list *));
	*ps->lst_a = NULL;
	ps->debug = 0;
	ps->color = 0;
	ps->flag = 0;
	ps->lst_b = wrmalloc(sizeof(t_list *));
	*ps->lst_b = NULL;
}

static int	is_valid(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (i != 0 && (s[i] == '+' || s[i] == '-') && s[i - 1] != s[i])
			return (0);
		else if (is_alpha(s[i]))
			return (0);
		else if (!is_digit(s[i]) && i && s[i - 1] != s[i])
			return (0);
	}
	return (1);
}

int duplicate(t_list **lst)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *lst;
	tmp2 = tmp->next;
	while (tmp2)
	{
		if (tmp->content == tmp2->content)
			return (1);
		tmp2 = tmp2->next;
	}
	return (0);
}

void	parse(char **av, t_struct *ps, int i, int j)
{
	char	**part;

	init_struct(ps);
	while (av[++i])
	{	
		if (i < 3 && !ft_strcmp(av[i], "-v") && !ps->flag)
			ps->debug = 1;
		else if (i < 3 && !ft_strcmp(av[i], "-c") && !ps->flag)
			ps->color = 1;
		else
		{
			ps->flag = 1;
			part = ft_split(av[i], ' ');
			if (!part[0])
				ft_exit(ARGS_F, 1);
			j = -1;
			while (part[++j])
			{
				if (!is_valid(part[j]))
					ft_exit(ARGS_F, 1);
				lst_push_front(ps->lst_a, new_lst((void *)ft_atol(part[j])));
				if (duplicate(ps->lst_a))
					ft_exit(DUP, 1);
			}
		}
	}
	ps->size = lst_size(ps->lst_a);
}
