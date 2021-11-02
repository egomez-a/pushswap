/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderbig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:15:29 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/02 10:45:26 by egomez-a         ###   ########.fr       */
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
		while(i < stk->len_b)
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
	if ((stk->posb.max_index) == 0)
		return ;
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

/* push number from chunk to the top */

void	pushnumbertotop_a (t_pl *stk)
{
	int i;
	
	if (stk->posa.index < (stk->len_a / 2))
	{
		i = 0;
		while(i < stk->posa.index)
		{
			ra(stk);
			i++;
		}
	}
	else 
	{
		i = stk->posa.index;
		while(i < stk->len_a)
		{
			rra(stk);
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
	int j;

	check_order(stk);
	chunk_limits(stk);
	j = 1;
	while (j <= stk->ck.n_chunk)
	{
		i = 0;
		while ((stk->len_b < stk->ck.chunksize) && (j <= stk->ck.n_chunk))
		{
			if (j == stk->ck.n_chunk) 
			{
				if ((stk->len_a != stk->ck.chunksize) || (stk->ck.n_chunk == 1))
				{
					orderlastchunk(stk);
					j++;
				}
				else
					break;
			}
			else 
			{
				if ((stk->stka[i] < stk->ck.chunk[j]) && (stk->stka[i] >= stk->ck.chunk[(j - 1)]))
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
		while (stk->len_b > 0)
			order_stackb(stk);
		i = 0;
		while (i < stk->flagorder)
		/* revisar para que haga rra si merece la pena */
		{
			ra(stk);
			i++;
		}
		j++;
		stk->flagorder = 0;
	}
	return;
}
