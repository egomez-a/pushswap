/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:03:03 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/05 13:27:46 by egomez-a         ###   ########.fr       */
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
//		bottom_number(stk);
//		top_number(stk);
//		printf("Top number is --> %d \n", stk->position.top);
//		printf("Index of top number --> %d \n", stk->position.top_index);
//		printf("Bottom number is %d\n", stk->position.bottom);
//		printf("Bottom index is %d\n", stk->position.bottom_index);
//		printf("Stack A ordered --> \n");
//		i = 0; 
//		while (i < stk->len_a)
//		{
//			printf("%d ",stk->position.array[i]);
//			i++;
//		}
//		printf("\n");
//		i = 0;
		printf("Stack B --> ");
		while (i < stk->len_b)
		{
			printf("%d ",stk->stkb[i]);
			i++;
		}
		printf("\n");
		if (stk->index.mov > 0)
		{
			printf("Movements: %d\n", stk->index.mov);
			printf("Chunk size is: %d\n", stk->ck.chunksize);
		}
	}
	return ;
}