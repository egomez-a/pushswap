/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:57:46 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 10:30:41 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Formula para definir el tamaño de los trozos */

void	chunks_size(t_pl	*stk)
{
	insertion_sort(stk);
	stk->ck.chunksize = stk->len_max / (ft_squareroot(stk->len_max) / 2);
	if (stk->ck.chunksize < 5)
		stk->ck.chunksize = 5;
	return ;
}

/* Defino el array chunk y sus límites */

void	chunk_limits(t_pl	*stk)
{
	int	i;

	insertion_sort(stk);
	stk->ck.chunksize = 40;
	chunks_size(stk);
	stk->ck.n_chunk = stk->len_max / stk->ck.chunksize;
	stk->ck.rest_chunk = stk->len_max % stk->ck.chunksize;
	if (stk->ck.rest_chunk == 0)
		stk->ck.chunk = ft_calloc(stk->ck.n_chunk + 1, sizeof(int));
	else
	{
		stk->ck.n_chunk = stk->ck.n_chunk + 1;
		stk->ck.chunk = ft_calloc((stk->ck.n_chunk + 1), sizeof(int));
	}
	i = 1;
	stk->ck.chunk[0] = stk->posa.array[0];
	while (i < stk->ck.n_chunk)
	{
		stk->ck.chunk[i] = stk->posa.array[(i * stk->ck.chunksize)];
		i++;
	}
	stk->ck.chunk[i] = stk->posa.array[(stk->len_max - 1)];
	return ;
}

void	place_number(t_pl	*stk)
{
	int	index;

	min_number_a(stk);
	index = (stk->len_a - (stk->ck.chunkcount - 1) * stk->ck.chunksize);
	if (stk->posa.min_index < index)
	{
		while (stk->posa.min_index != index)
		{
			rra(stk);
			index--;
		}
	}
	return ;
}
