/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:03:03 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/16 20:43:50 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printstacks(t_pl *stk)
{
	int	i;

	i = 0;
	if (stk)
	{
		printf("Stack A  --> ");
		while (i < stk->len_a)
		{
			printf("%d ", stk->stka[i]);
			i++;
		}
		printf("\nStack B --> ");
		while (i < stk->len_b)
		{
			printf("%d ", stk->stkb[i]);
			i++;
		}
		if (stk->index.mov > 0)
		{
			printf("\nMovements: %d\n", stk->index.mov);
			printf("Chunk size is: %d\n", stk->ck.chunksize);
		}
	}
	return ;
}
