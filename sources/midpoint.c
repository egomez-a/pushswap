/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:57:46 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/26 17:32:29 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void mid_insertionsort(t_pl *stk) 
{ 
	int i;
	int j;
	int element;

	stk->position.array =  ft_calloc(stk->len_a, sizeof(int));
	stk->position.array = stk->stka;
	i = 1;
	while (i < stk->len_a)
	{ 
		element = stk->position.array[i]; 
		j = i - 1;
		while (j >= 0 && stk->position.array[j] > element) 
		{ 
			stk->position.array[j + 1] = stk->position.array[j]; 
            j = j - 1; 
        } 
        stk->position.array[j + 1] = element;
		i++;
    }
	stk->position.mid_index = (stk->len_a/2);
	stk->position.mid = stk->position.array[stk->position.mid_index];
	return ;
}
