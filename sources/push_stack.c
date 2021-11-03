/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:18:10 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 11:36:44 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_aux_a(t_pl	*stk)
{
	int	i;

	i = 1;
	stk->aux = ft_calloc(stk->len_a, sizeof(int));
	stk->aux[0] = stk->stkb[stk->len_b];
	while (i < stk->len_a)
	{
		stk->aux[i] = stk->stka[i - 1];
		i++;
	}
	free(stk->stka);
	stk->stka = stk->aux;
}

void	push_aux_b(t_pl	*stk)
{
	int	i;

	i = 1;
	stk->aux = ft_calloc(stk->len_b, sizeof(int));
	stk->aux[0] = stk->stka[stk->len_a];
	while (i < stk->len_b)
	{
		stk->aux[i] = stk->stkb[i - 1];
		i++;
	}
	free(stk->stkb);
	stk->stkb = stk->aux;
}

/* Push_a manda el primer elemento en pila_b al top de pila_a */

void	pa(t_pl	*stk)
{
	int	i;

	i = 1;
//	stk->flag = 1;
	if ((stk->stkb) && (stk->len_b > 0))
	{
		stk->flagrotate = 1;
		rb(stk);
		stk->len_b = stk->len_b - 1;
		stk->len_a = stk->len_a + 1;
		push_aux_a(stk);
		write(2, "pa\n", 4);
		stk->mov++;
	}
	return ;
}

/* Push_b manda el primer elemento en pila_a al top de pila_b */

void	pb(t_pl	*stk)
{
	int	i;

	i = 1;
//	stk->flag = 1;
	if ((stk->stka) && (stk->len_a > 0))
	{
		stk->flagrotate = 1;
		ra(stk);
		stk->len_a = stk->len_a - 1;
		stk->len_b = stk->len_b + 1;
		push_aux_b(stk);
		write(2, "pb\n", 4);
		stk->mov++;
	}
	return ;
}
