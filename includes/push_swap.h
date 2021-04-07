/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:18:28 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/26 13:10:08 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ARGS_N "\e[91mNumber of args"
# define ARGS_F "\e[91mArgument not well formated"
# define DUP "\e[91mDuplicate numbers"
# define SUCCESS "\e[92mSuccess"
# define A_SORTED "\e[92mAlready sorted"
# define FAILED "\e[91mFailed"
# define LIMIT "\e[91mINT_LIMITS"
# define IMPOSSIBLE -36666
# include "utils.h"

typedef struct s_struct
{
	t_list		**lst_a;
	t_list		**lst_b;
	int			*sorted;
	int			size;
	int			debug;
	int			color;
	int			flag;
	long			*min;
	int			chunck;
	long		start;
	long		end;
	int			push;
}				t_struct;


void	parse(char **av, t_struct *ps, int i);
void	take_arg(char **part, t_struct *ps);
void	init_struct(t_struct *ps);
int duplicate(t_list **lst, long n);
void	print_stack(t_struct *ps, char *last, int i);
void	empty_chunk_a(t_struct *ps);
void	fill_sorted_a(t_struct *ps);

/*
** INFOS
*/
int	is_valid(char *s);
int 	is_top_max(t_list **lst);
int is_max(t_list **lst, t_list *max);
int is_min(t_list **lst, t_list *min);
long get_max(t_list **lst);
long get_min(t_list **lst);
int get_min_pos(t_list **lst);
long get_middle(t_list **lst);
t_list *get_at_pos(t_list **lst, int n);
int get_pos(t_list **lst, long n);
int		is_sort(t_struct *ps);
long *sort_long_tab(t_struct *ps, int i);
/*
** ALGOS
*/
void mini_sort(t_struct *ps);
void		micro_sort(t_struct *ps);
/*
** OPERATIONS
*/
void	swap(t_list **lst, t_struct *ps, int aff, int type);
void	double_swap(t_struct **ps, int aff);
void	push(t_list **dest, t_list **src, t_struct *ps ,int type);
void	rotate(t_list **lst, t_struct *ps, int aff, int type);
void	double_rotate(t_struct **ps, int aff);
void	reverse_rotate(t_list **lst, t_struct *ps, int aff, int type);
void	double_rev_rotate(t_struct **ps, int aff);
#endif