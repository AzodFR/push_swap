#include "checker.h"

void    ft_exit2(char *s, int code, char *s2)
{
    printf("%s\n", s);
    wrdestroy();
    free(s2);
	exit(code);
}

void	push2(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (!lst_size(src))
		return ;
	tmp = new_lst((*src)->content);
	(*src) = (*src)->next;
	lst_push_front(dest, tmp);
}

void handler(char *s, t_struct *ps)
{
    if (!ft_strcmp(s, "sa"))
        swap(ps->lst_a, ps, 0, 0);
    else if (!ft_strcmp(s, "sb"))
        swap(ps->lst_b, ps, 0, 0);
    else if (!ft_strcmp(s, "ss"))
        double_swap(&ps, 0);
    else if (!ft_strcmp(s, "pa"))
        push2(ps->lst_a, ps->lst_b);
    else if (!ft_strcmp(s, "pb"))
        push2(ps->lst_b, ps->lst_a);
    else if (!ft_strcmp(s, "ra"))
        rotate(ps->lst_a, ps, 0, 0);
    else if (!ft_strcmp(s, "rb"))
        rotate(ps->lst_b, ps, 0, 0);
    else if (!ft_strcmp(s, "rr"))
        double_rotate(&ps, 0);
    else if (!ft_strcmp(s, "rra"))
        reverse_rotate(ps->lst_a, ps, 0, 0);
    else if (!ft_strcmp(s, "rrb"))
        reverse_rotate(ps->lst_b, ps, 0, 0);
    else if (!ft_strcmp(s, "rrr"))
        double_rev_rotate(&ps, 0);
    else
        ft_exit2("Error", 1, s);
}


int	parse2(char **av, t_struct *ps, int i, int j)
{
	char	**part;
    int     file;

	init_struct(ps);
    file = 0;
	while (av[++i])
	{	
		if (i < 3 && !ft_strcmp(av[i], "-f") && !ps->flag)
			file = ++i;
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
				lst_push_back(ps->lst_a, new_lst((void *)ft_atol(part[j])));
				if (duplicate(ps->lst_a))
					ft_exit(DUP, 1);
			}
		}
	}
	ps->size = lst_size(ps->lst_a);
    return (file);
}



int main(int ac, char **av)
{
    int fd;
    char *line;
    int ret;
    t_struct *ps;

    (void)ac;
    fd = 0;
    ps = wrmalloc(sizeof(t_struct));
	if (parse2(av, ps, 0, 0))
    {
        fd = open(av[2], O_RDONLY);
        if (fd < 0)
            ft_exit2("Error", 1, NULL);
    }
    ps->debug = 1;
    ret = get_next_line(fd, &line);
    while (ret > 0)
    {
        handler(line, ps);
        free(line);
        ret = get_next_line(fd, &line);
    }
    if (is_sort(ps))
		ft_exit2("OK", 0, line);
    ft_exit2("KO", 1, line);
    return (0);
}