/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderbig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:15:29 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/27 13:46:28 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pushlowtotop (t_pl *stk)
{
	int i;
	
	bottom_number(stk);
	if (stk->position.bottom_index < (stk->len_a / 2))
	{
		i = 0;
		while(i < stk->position.bottom_index)
		{
			ra(stk);
			i++;
		}
	}
	else 
	{
		i = stk->position.bottom_index;
		while(i < stk->len_a)
		{
			rra(stk);
			i++;
		}
	}
}

void	orderbig(t_pl *stk)
{
	int i;

	check_order(stk);
	while (stk->len_a > 3)
	{
		pushlowtotop(stk);
		pb (stk);
		
	}
	orderlow(stk);
	i = 0;
	while (stk->len_b > 0)
		pa(stk);
	return;
}
