/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderfive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:03:03 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 20:09:22 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sequence5_1(t_pl *stk)
{
	pa(stk);
	pa(stk);
	ra(stk);
}

void	sequence5_2(t_pl *stk)
{
	pa(stk);
	sa(stk);
	pa(stk);
	ra(stk);
}

void	sequence5_3(t_pl *stk)
{
	rra(stk);
	pa(stk);
	ra(stk);
	ra(stk);
	pa(stk);
	ra(stk);
}

void	sequence5_4(t_pl *stk)
{
	pa(stk);
	ra(stk);
	pa(stk);
	ra(stk);
}

void	orderfive(t_pl *stk)
{
	transfer(stk);
	while (stk->len_a > 3)
		pb(stk);
	orderlow(stk);
	if ((stk->len_b == 2) && (stk->stkb[0] > stk->stkb[1]))
		sb(stk);
	if ((stk->stkb[0] < stk->stka[0]) && (stk->stkb[0] < stk->stka[1])
		&& (stk->stkb[0] < stk->stka[2]))
		sequence5_1(stk);
	else if ((stk->stkb[0] > stk->stka[0]) && (stk->stkb[0] < stk->stka[1])
		&& (stk->stkb[0] < stk->stka[2]))
		sequence5_2(stk);
	else if ((stk->stkb[0] > stk->stka[0]) && (stk->stkb[0] > stk->stka[1])
		&& (stk->stkb[0] < stk->stka[2]))
		sequence5_3(stk);
	else
		sequence5_4(stk);
}
