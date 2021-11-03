/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:30:46 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 19:36:43 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Reverse Rotate desplaza hacia abajo todos los elementos de la pila */
/* y el ultimo pasa a ser el primero */

void	rra(t_pl *stk)
{
	int	i;
	int	aux;

	i = stk->len_a - 1;
	if (stk->stka)
	{
		if (stk->index.flag == 0)
		{
			write(2, "rra\n", 5);
			stk->index.mov++;
		}
		aux = stk->stka[stk->len_a - 1];
		while (i > 0)
		{
			stk->stka[i] = stk->stka[i - 1];
			i--;
		}
		stk->stka[i] = aux;
	}
	return ;
}

void	rrb(t_pl *stk)
{
	int	i;
	int	aux;

	i = stk->len_b - 1;
	if (stk->stkb)
	{
		if (stk->index.flag == 0)
		{
			write(2, "rrb\n", 5);
			stk->index.mov++;
		}
		aux = stk->stkb[stk->len_b - 1];
		while (i > 0)
		{
			stk->stkb[i] = stk->stkb[i - 1];
			i--;
		}
		stk->stkb[i] = aux;
	}
	return ;
}

void	rrr(t_pl *stk)
{
	stk->index.flag = 1;
	rra(stk);
	rrb(stk);
	write(1, "rrr\n", 5);
	stk->index.mov++;
	stk->index.flag = 0;
	return ;
}
