/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderbig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:15:29 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 13:34:27 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	pa(stk);
	stk->flagorder++;
	if (stk->len_b == 0)
		return ;
	pushmintotop_b(stk);
	pa(stk);
	ra(stk);
	return ;
}

void	orderstacka(t_pl *stk)
{
	int i;

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
	return ;
}

void	orderlastchunk(t_pl *stk)
{
	int i;

	i = 0;
	while (i < stk->len_a)
	{
		if ((stk->stka[i] <= stk->ck.chunk[stk->ck.n_chunk]) && (stk->stka[i] >= stk->ck.chunk[(stk->ck.n_chunk - 1)]))
		{
			stk->posa.index = i;
			pushnumbertotop_a(stk);
			pb (stk);
			i = 0;
		}			
		else 
			i++;
	}
	orderstacka(stk);
	return ;
}

/* Ordenación por trozos */

void	orderstackbychunks(t_pl *stk)
{
	int i;

	check_order(stk);
	chunk_limits(stk);
	stk->ck.chunkcount = 1;
	while (stk->ck.chunkcount <= stk->ck.n_chunk)
	{
		i = 0;
		while ((stk->len_b < stk->ck.chunksize) && (stk->ck.chunkcount <= stk->ck.n_chunk))
		{
			if (stk->ck.chunkcount == stk->ck.n_chunk) 
			{
				if ((stk->len_a != stk->ck.chunksize) || (stk->ck.n_chunk == 1))
				{
					orderlastchunk(stk);
					stk->ck.chunkcount++;
				}
				else
					break;
			}
			else 
			{
				if ((stk->stka[i] < stk->ck.chunk[stk->ck.chunkcount]) && (stk->stka[i] >= stk->ck.chunk[(stk->ck.chunkcount - 1)]))
				{
					stk->posa.index = i;
					pushnumbertotop_a(stk);
					pb (stk);
					i = 0;
				}			
				else 
					i++;
			}
		}
		if (stk->ck.chunkcount > 1)
			place_number(stk);
		while (stk->len_b > 0)
			order_stackb(stk);
		i = 0;
		while (i < stk->flagorder)
		{
			ra(stk);
			i++;
		}
		stk->ck.chunkcount++;
		stk->flagorder = 0;
	}
	return;
}
