/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_array_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:35:52 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/02 17:37:53 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Buscar el número más bajo del stack a */

void	min_number_a(t_pl *stk)
{
	int	i;

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
	int	i;

	i = 0;
	stk->posb.min = stk->stkb[0];
	stk->posb.min_index = 0;
	while (i < stk->len_b)
	{
		if (stk->posb.min > stk->stkb[i])
		{
			stk->posb.min = stk->stkb[i];
			stk->posb.min_index = i;
			i++;
		}
		else
			i++;
	}
	return ;
}
/* Buscar el número más alto del stack a*/

void	max_number_a(t_pl *stk)
{
	int	i;

	i = 1;
	stk->posa.max = stk->stka[0];
	stk->posa.max_index = 0;
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

void	max_number_b(t_pl *stk)
{
	int	i;

	i = 1;
	stk->posb.max = stk->stkb[0];
	stk->posb.max_index = 0;
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
