/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:18:10 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/25 12:37:33 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Push_a manda el primer elemento en pila_b al top de pila_a */

void	pa(t_pl	*stk)
{
	int i;
	int j;
	int k;
	
	i = 0;
	j = 1;
	k = 0;
	if (stk->stkb)
	{
		stk->aux = ft_calloc(stk->len_a, sizeof(int));
		stk->len_b = stk->len_b - 1;
		stk->len_a = stk->len_a + 1;
		stk->aux = stk->stka;
		stk->stka[0] = stk->stkb[0];
		while (k < stk->len_a)
		{
			stk->aux[k] = stk->stka[k];
			k++;
		}
		while (i < stk->len_b)
		{
			stk->stkb[i] = stk->stkb[i + 1];
			i++;
		}
		while (j < stk->len_a)
		{
			stk->stka[j] = stk->aux[j - 1];
			j++;
		}
		free(stk->aux);
		write(2, "pa\n", 4);
	}
	return ;
}

void	push_aux(t_pl	*stk)
{
	int i;
	
	i = 1;
	stk->aux = ft_calloc(stk->len_b, sizeof(int));
	stk->aux[0] = stk->stka[stk->len_a];
	while (i < stk->len_b)
	{
		stk->aux[i] = stk->stkb[i - 1];
		i++;
	}
	stk->stkb = stk->aux;
	free(stk->aux);
}

/* Push_b manda el primer elemento en pila_a al top de pila_b */

void	pb(t_pl	*stk)
{
	int i;
	
	i = 1;
	stk->flag = 1;
	if (stk->stka)
	{
		ra(stk);
		stk->len_a = stk->len_a - 1;
		stk->len_b = stk->len_b + 1;
		push_aux(stk);
		write(2, "pb\n", 4);
	}
	return ;
}

