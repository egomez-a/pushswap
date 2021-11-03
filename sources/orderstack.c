/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:43:07 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 19:33:18 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Ordenación sin optimizar */

void	orderstack(t_pl *stk)
{
	int	i;

	check_order(stk);
	insertion_sort(stk);
	while (stk->len_a > 3)
	{
		pushmintotop_a(stk);
		pb (stk);
	}
	orderlow(stk);
	i = 0;
	while (stk->len_b > 0)
		pa(stk);
}

/*busqueda de menor elemento en stack_b */

void	order_stackb(t_pl *stk)
{
	pushmaxtotop_b(stk);
	pa(stk);
	stk->index.flagorder++;
	if (stk->len_b == 0)
		return ;
	pushmintotop_b(stk);
	pa(stk);
	ra(stk);
}

void	orderstacka(t_pl *stk)
{
	int	i;

	i = 0;
	while (i < stk->len_a)
	{
		if ((stk->stka[i] > stk->stka[stk->len_a - 1]))
		{
			ra(stk);
			i = 0;
		}
		else
			i++;
	}
}
