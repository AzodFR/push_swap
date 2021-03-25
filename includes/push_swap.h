/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:18:28 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 17:01:40 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ARGS_N "\e[91mNumber of args"
# define ARGS_F "\e[91mArgument not well formated"
# define SUCCESS "\e[92mSuccess"
# include "utils.h"

typedef struct s_struct
{
	t_list		**lst_a;
	t_list		**lst_b;
	int			size;
	int			debug;
	int			color;
	int			flag;
}				t_struct;


void	parse(char **av, t_struct *ps, int i, int j);
/*
** OPERATIONS
*/
void	swap(t_list **lst);
void	double_swap(t_struct **ps);
void	push(t_list **dest, t_list **src);
void	rotate(t_list **lst);
void	double_rotate(t_struct **ps);
void	reverse_rotate(t_list **lst);
void	double_rev_rotate(t_struct **ps);
#endif