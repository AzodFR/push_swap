/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:10:12 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/25 13:16:09 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *string, int code)
{
	if (code)
	{
		printf("\e[96mpush\e[0m_\e[93mswap\e[0m");
		if (code)
			printf("_\e[91merror");
		printf(": %s\e[0m\n", string);
	}
	wrdestroy();
	exit(code);
}
