/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:19:25 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 19:43:30 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Rotate desplaza hacia arriba todos los elementos de la pila */
/* y el primero pasa a ser el último */

void	ra(t_pl *stk)
{
	int	i;
	int	aux;

	i = 0;
	if (stk->stka)
	{
		if ((stk->index.flag == 0) && (stk->index.flagrotate == 0))
		{
			write(2, "ra\n", 4);
			stk->index.mov++;
		}
		aux = stk->stka[0];
		while (i < stk->len_a - 1)
		{
			stk->stka[i] = stk->stka[i + 1];
			i++;
		}
		stk->stka[i] = aux;
	}
	stk->index.flagrotate = 0;
	return ;
}

void	rb(t_pl *stk)
{
	int	i;
	int	aux;

	i = 0;
	if (stk->stkb)
	{
		if ((stk->index.flag == 0) && (stk->index.flagrotate == 0))
		{
			write(2, "rb\n", 4);
			stk->index.mov++;
		}
		aux = stk->stkb[0];
		while (i < stk->len_b - 1)
		{
			stk->stkb[i] = stk->stkb[i + 1];
			i++;
		}
		stk->stkb[i] = aux;
	}
	stk->index.flagrotate = 0;
	return ;
}

void	rr(t_pl *stk)
{
	stk->index.flag = 1;
	ra(stk);
	rb(stk);
	write(1, "rr\n", 4);
	stk->index.mov++;
	stk->index.flag = 0;
	return ;
}
