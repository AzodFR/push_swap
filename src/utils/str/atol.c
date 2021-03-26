/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:13:00 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 16:39:35 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *s)
{
	int		i;
	int		neg;
	long	res;

	i = -1;
	neg = 0;
	res = 0;
	while (s[++i] == '+' || s[i] == '-')
		if (s[i] == '-')
			neg = !neg;
	while (s[i])
		res = (res * 10) + (s[i++] - '0');
	if (!neg)
		return (res);
	return (res * -1);
}
