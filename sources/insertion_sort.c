/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:32:14 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/02 17:34:52 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Algoritmo de ordenación del stack */

void	insertion_sort(t_pl *stk)
{
	int	i;
	int	j;
	int	element;

	stk->posa.array = ft_calloc(stk->len_a, sizeof(int));
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
	return ;
}
