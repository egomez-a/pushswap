/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderbig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:15:29 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/26 20:27:11 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		orderbig(t_pl *stk)
{
	int i; 

	i = 0;
	bottom_number(stk);
	if (stk->position.bottom_index < (stk->len_a / 2))
	{
		while(i < stk->position.bottom_index)
		{
			pb(stk);
			i++;
		}
	orderbig(stk);
	}
	return ;
}