/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:16:47 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/25 13:12:59 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Switch_a intercambia el primer elemento con el segundo */

void	sa(t_pl *stk)
{
	int	aux;

	if (stk->stka)
	{
		if (stk->flag == 0)
		{
			write(1, "sa\n", 4);
			stk->mov++;
		}
		aux = stk->stka[0];
		stk->stka[0] = stk->stka[1];
		stk->stka[1] = aux;
	}
	return ;
}

void	sb(t_pl *stk)
{
	int	aux;

	if (stk->stkb)
	{
		if (stk->flag == 0)
		{
			write(1, "sb\n", 4);
			stk->mov++;
		}
		aux = stk->stkb[0];
		stk->stkb[0] = stk->stkb[1];
		stk->stkb[1] = aux;
	}
	return ;
}

void	ss(t_pl *stk)
{
	stk->flag = 1;
	sa(stk);
	sb(stk);
	write(1, "ss\n", 4);
	stk->mov++;
	stk->flag = 0;
	return ;
}
