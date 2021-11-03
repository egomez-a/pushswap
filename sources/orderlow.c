/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderlow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:27:01 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 13:50:48 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	transfer(t_pl *stk)
{
	max_number_a(stk);
	if (((stk->posa.max_index) + 1) <= ((stk->len_a)/2) && (stk->stka[0] != stk->posa.max))
	{
		while (stk->stka[0] != stk->posa.max)
			ra(stk);
	}
	if (((stk->posa.max_index) + 1) > ((stk->len_a)/2) && (stk->stka[0] != stk->posa.max))
	{
		while (stk->stka[0] != stk->posa.max)
			rra(stk);
	}
	return ;
}

void	orderfive(t_pl *stk)
{
	transfer(stk);
	while (stk->len_a > 3)
		pb(stk);
	orderlow(stk);
	if ((stk->len_b == 2) && (stk->stkb[0] > stk->stkb[1]))
		sb(stk);
	if ((stk->stkb[0] < stk->stka[0]) && (stk->stkb[0] < stk->stka[1]) &&(stk->stkb[0] < stk->stka[2]))
	{
		pa(stk);
		pa(stk);
		ra(stk);
	}
	else if ((stk->stkb[0] > stk->stka[0]) && (stk->stkb[0] < stk->stka[1]) &&(stk->stkb[0] < stk->stka[2]))
	{
		pa(stk);
		sa(stk);
		pa(stk);
		ra(stk);
	}
	else if ((stk->stkb[0] > stk->stka[0]) && (stk->stkb[0] > stk->stka[1]) &&(stk->stkb[0] < stk->stka[2]))
	{
		rra(stk);
		pa(stk);
		ra(stk);
		ra(stk);
		pa(stk);
		ra(stk);
	}
	else
	{
		pa(stk);
		ra(stk);
		pa(stk);
		ra(stk);
	}
	return;
}

void	orderlow(t_pl *stk)
{
	if ((stk->len_a == 1) || ((stk->len_a == 2) && (stk->stka[0] < stk->stka[1])))
		return ;
	else if ((stk->len_a == 2) && (stk->stka[0] > stk->stka[1]))
	{
		sa(stk);
		return ;
	}
	else if (stk->stka[0] > stk->stka[1])
	{
		if (stk->stka[1] > stk->stka[2] && stk->stka[0] > stk->stka[2])
		{
			sa(stk);
			rra(stk);
			return ;
		}
		else if (stk->stka[1] < stk->stka[2] && stk->stka[0] > stk->stka[2])
		{
			ra(stk);
			return ;
		}
		else if (stk->stka[1] < stk->stka[2] && stk->stka[0] < stk->stka[2])
		{	
			sa(stk);
			return ;
		}
	}
	else
	{
		if (stk->stka[1] > stk->stka[2] && stk->stka[0] < stk->stka[2])
		{
			sa(stk);
			ra(stk);
			return ;
		}
		else if (stk->stka[1] > stk->stka[2] && stk->stka[0] > stk->stka[2])
		{
			rra(stk);
			return ;
		}
		else if (stk->stka[1] < stk->stka[2] && stk->stka[0] < stk->stka[2])
		{	
			return ;
		}
	}
}

