/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:03:03 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/26 13:19:26 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printstacks(t_pl *stk)
{
	int i;
	
	i = 0;
	if (stk)
	{
		printf("Stack A  --> ");
		while (i < stk->len_a)
		{
			printf("%d ",stk->stka[i]);
			i++;
		}
		printf("\n");
		top_number(stk);
		printf("Top number is --> %d \n", stk->top);
		printf("Index of top number --> %d \n", stk->top_index);
		printf("Mid point is %d\n", mid_insertionsort(stk));
		printf("Stack A ordered --> \n");
		i = 0;
		while (i < stk->len_a)
		{
			printf("%d ",stk->array[i]);
			i++;
		}
		i = 0;
		printf("Stack B --> ");
		while (i < stk->len_b)
		{
			printf("%d ",stk->stkb[i]);
			i++;
		}
		printf("\n");
		if (stk->mov > 0)
			printf("Movements: %d\n", stk->mov);
	}
	return ;
}