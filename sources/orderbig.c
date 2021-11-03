/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderbig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:15:29 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 15:49:48 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	orderlastchunk(t_pl *stk)
{
	int	i;

	i = 0;
	while (i < stk->len_a)
	{
		if ((stk->stka[i] <= stk->ck.chunk[stk->ck.n_chunk]) && (stk->stka[i]
				>= stk->ck.chunk[(stk->ck.n_chunk - 1)]))
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
}

void	orderchunk(t_pl	*stk)
{
	int	i;

	i = 0;
	while ((stk->len_b < stk->ck.chunksize) && (stk->ck.ckcnt
			<= stk->ck.n_chunk))
	{
		if (stk->ck.ckcnt == stk->ck.n_chunk)
		{
			if ((stk->len_a != stk->ck.chunksize) || (stk->ck.n_chunk == 1))
			{
				orderlastchunk(stk);
				stk->ck.ckcnt++;
			}
			else
				break ;
		}
		else
		{
			if ((stk->stka[i] < stk->ck.chunk[stk->ck.ckcnt])
				&& (stk->stka[i] >= stk->ck.chunk[(stk->ck.ckcnt - 1)]))
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
}

void	chunkselection(t_pl	*stk)
{
	int	i;

	i = 0;
	while ((stk->len_b < stk->ck.chunksize) && (stk->ck.ckcnt
			<= stk->ck.n_chunk))
	{
		if (stk->ck.ckcnt == stk->ck.n_chunk)
		{
			if ((stk->len_a != stk->ck.chunksize) || (stk->ck.n_chunk == 1))
			{
				orderlastchunk(stk);
				stk->ck.ckcnt++;
			}
			else
				break ;
		}
		else
		{
			if ((stk->stka[i] < stk->ck.chunk[stk->ck.ckcnt])
				&& (stk->stka[i] >= stk->ck.chunk[(stk->ck.ckcnt - 1)]))
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
}

/* Ordenación por trozos */

void	orderstackbychunks(t_pl *stk)
{
	int	i;

	check_order(stk);
	chunk_limits(stk);
	stk->ck.ckcnt = 1;
	while (stk->ck.ckcnt <= stk->ck.n_chunk)
	{
		chunkselection(stk);
		if (stk->ck.ckcnt > 1)
			place_number(stk);
		while (stk->len_b > 0)
			order_stackb(stk);
		i = 0;
		while (i < stk->flagorder)
		{
			ra(stk);
			i++;
		}
		stk->ck.ckcnt++;
		stk->flagorder = 0;
	}
}
