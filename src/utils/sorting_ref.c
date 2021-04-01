#include "push_swap.h"

long *sort_long_tab(t_struct *ps)
{
    long *min;
    t_list *temp;
    int   i;
    long     tmp;

    min = wrmalloc(lst_size(ps->lst_a) * sizeof(long));
    temp = *(ps->lst_a);
    i = -1;
    while (temp)
    {
        min[++i] = (long)temp->content;
        temp = temp->next;
    }
    i = 0;
    while (i < ps->size - 1)
    {
        if (min[i] > min[i + 1])
        {
            tmp = min[i];
            min[i] = min[i + 1];
            min[i + 1] = tmp;
            i = 0;
        }
        else
            i++;
    }
    return (min);
}

int			define_plages(t_struct *ps)
{
	int		plages;
	int		length;

	plages = 0;
	length = ps->size;
	if (length <= 10)
		plages = 5;
	else if (length >= 10 && length <= 50)
		plages = 10;
	else if (length >= 50 && length <= 100)
		plages = 20;
	else if (length <= 50)
		plages = 20;
	else if (length >= 100 && length <= 300)
		plages = 35;
	else if (length >= 300)
		plages = 50;
	return (plages);
}