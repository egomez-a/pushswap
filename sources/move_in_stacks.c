/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_in_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:30:23 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 13:43:53 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Busca el menor valor y lo sube a la primera posicion */

void	pushmintotop_a(t_pl *stk)
{
	int	i;

	min_number_a(stk);
	if (stk->posa.min_index < (stk->len_a / 2))
	{
		i = 0;
		while (i < stk->posa.min_index)
		{
			ra(stk);
			i++;
		}
	}
	else
	{
		i = stk->posa.min_index;
		while (i < stk->len_a)
		{
			rra(stk);
			i++;
		}
	}
}

void	pushmintotop_b(t_pl *stk)
{
	int	i;

	min_number_b(stk);
	if (stk->posb.min_index < (stk->len_b / 2))
	{
		i = 0;
		while (i < stk->posb.min_index)
		{
			rb(stk);
			i++;
		}
	}
	else
	{
		i = stk->posb.min_index;
		while (i < stk->len_b)
		{
			rrb(stk);
			i++;
		}
	}
}

void	pushmaxtotop_b(t_pl *stk)
{
	int	i;

	max_number_b(stk);
	if ((stk->posb.max_index) == 0)
		return ;
	if (stk->posb.max_index < (stk->len_b / 2))
	{
		i = 0;
		while (i < stk->posb.max_index)
		{
			rb(stk);
			i++;
		}
	}
	else
	{
		i = stk->posb.max_index;
		while (i < stk->len_b)
		{
			rrb(stk);
			i++;
		}
	}
}

/* push number from chunk to the top */

void	pushnumbertotop_a(t_pl *stk)
{
	int	i;

	if (stk->posa.index < (stk->len_a / 2))
	{
		i = 0;
		while (i < stk->posa.index)
		{
			ra(stk);
			i++;
		}
	}
	else
	{
		i = stk->posa.index;
		while (i < stk->len_a)
		{
			rra(stk);
			i++;
		}
	}
}
