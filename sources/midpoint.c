/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:57:46 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/28 12:37:27 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Algoritmo de ordenación del stack */

void insertion_sort(t_pl *stk) 
{ 
	int i;
	int j;
	int element;

	stk->posa.array =  ft_calloc(stk->len_a, sizeof(int));
	i = 0;
	while (i < stk->len_a)
	{
		stk->posa.array[i] = stk->stka[i];
		i++;
	}
	i = 1;
	while (i < stk->len_a)
	{ 
		element = stk->posa.array[i]; 
		j = i - 1;
		while (j >= 0 && stk->posa.array[j] > element) 
		{ 
			stk->posa.array[j + 1] = stk->posa.array[j]; 
            j = j - 1; 
        } 
        stk->posa.array[j + 1] = element;
		i++;
    }
//	stk->posa.mid_index = (stk->len_a/2);
//	stk->posa.mid = stk->posa.array[stk->posa.mid_index];
	return ;
}

/* Buscar el número más bajo */

void	min_number_a(t_pl *stk)
{
	int i;

	i = 0;
	stk->posa.min = stk->stka[0];
	stk->posa.min_index = 0;
	while (i < stk->len_a)
	{
		if (stk->posa.min > stk->stka[i])
		{
			stk->posa.min = stk->stka[i];
			stk->posa.min_index = i;
			i++;
		}
		else 
			i++;	
	}
	return ;
}


/* Buscar el número más bajo del stack b */

void	min_number_b(t_pl *stk)
{
	int i;

	i = 0;
	stk->posb.min = stk->stkb[0];
	stk->posb.min_index = 0;
	while (i < stk->len_a)
	{
		if (stk->posb.min > stk->stka[i])
		{
			stk->posb.min = stk->stka[i];
			stk->posb.min_index = i;
			i++;
		}
		else 
			i++;	
	}
	return ;
}
/* Buscar el número más alto del stack a*/

void max_number_a(t_pl *stk)
{
	int	i;

	i = 1;
	stk->posa.max = stk->stka[0];
	while (i < stk->len_a)
	{
		if (stk->stka[i] > stk->posa.max)
		{
			stk->posa.max = stk->stka[i];
			stk->posa.max_index = i;
		}
		i++;
	}
	return ;
}

/* Buscar el número más alto del stack b*/

void max_number_b(t_pl *stk)
{
	int	i;

	i = 1;
	stk->posb.max = stk->stkb[0];
	while (i < stk->len_b)
	{
		if (stk->stkb[i] > stk->posb.max)
		{
			stk->posb.max = stk->stkb[i];
			stk->posb.max_index = i;
		}
		i++;
	}
	return ;
}

/* Formula para definir el tamaño de los trozos */

void	chunks_size(t_pl	*stk)
{
	insertion_sort(stk);
	stk->ck.chunksize = stk->len_max / (sqrt(stk->len_max) / 2);
	return ;
}

/* Defino el array chunk y sus límites */

void	chunk_limits(t_pl	*stk)
{
	int i;
	int index;
	
	insertion_sort(stk);
	stk->ck.chunksize = 5;
	stk->ck.n_chunk = stk->len_max / stk->ck.chunksize;
	stk->ck.chunk =  ft_calloc(stk->ck.n_chunk, sizeof(int));
	i = 0;
	while (i < stk->ck.n_chunk)
	{
		index = i * stk->len_max / stk->ck.n_chunk;
		stk->ck.chunk[i] = stk->posa.array[index];
		i++;
	}
	return ;
}