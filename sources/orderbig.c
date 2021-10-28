/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderbig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:15:29 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/28 12:44:04 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Busca el menor valor y lo sube a la primera posicion */

void	pushmintotop_a (t_pl *stk)
{
	int i;
	
	min_number_a(stk);
	if (stk->posa.min_index < (stk->len_a / 2))
	{
		i = 0;
		while(i < stk->posa.min_index)
		{
			ra(stk);
			i++;
		}
	}
	else 
	{
		i = stk->posa.min_index;
		while(i < stk->len_a)
		{
			rra(stk);
			i++;
		}
	}
}

void	pushmintotop_b (t_pl *stk)
{
	int i;
	
	min_number_b(stk);
	if (stk->posb.min_index < (stk->len_b / 2))
	{
		i = 0;
		while(i < stk->posb.min_index)
		{
			rb(stk);
			i++;
		}
	}
	else 
	{
		i = stk->posb.min_index;
		while(i < stk->len_a)
		{
			rrb(stk);
			i++;
		}
	}
}

void	pushmaxtotop_b(t_pl *stk)
{
		int i;
	
	max_number_b(stk);
	if (stk->posb.max_index < (stk->len_b / 2))
	{
		i = 0;
		while(i < stk->posb.max_index)
		{
			rb(stk);
			i++;
		}
	}
	else 
	{
		i = stk->posb.max_index;
		while(i < stk->len_b)
		{
			rrb(stk);
			i++;
		}
	}
}

/* Ordenación sin optimizar */

void	orderstack(t_pl *stk)
{
	int i;

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
	return;
}

/*busqueda de menor elemento en stack_b */

void order_stackb(t_pl *stk)
{
	pushmaxtotop_b(stk);
	printstacks(stk);
	return ;
}
 

/* Ordenación por trozos */

void	orderstackbychunks(t_pl *stk)
{
	int i;
	int j;

	check_order(stk);
	chunk_limits(stk);
	i = 0;
	j = 1;
	while (j < stk->ck.n_chunk)
	{
		while (stk->len_a > 3)
		{
			if (stk->stka[i] < stk->ck.chunk[j])
			{
				pushmintotop_a(stk);
				pb (stk);
				i++;
			}
			i++;
		}
		order_stackb(stk);
	
	}
	orderlow(stk);
	i = 0;
	while (stk->len_b > 0)
		pa(stk);
	return;
}
