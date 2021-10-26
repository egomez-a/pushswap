/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:57:46 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/26 13:13:55 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int mid_insertionsort(t_pl *stk) 
{ 
	int i;
	int j;
	int element;
	int	midpoint;

	stk->array =  ft_calloc(stk->len_a, sizeof(int));
	stk->array = stk->stka;
	i = 1;
	while (i < stk->len_a)
	{ 
		element = stk->array[i]; 
		j = i - 1;
		while (j >= 0 && stk->array[j] > element) 
		{ 
			stk->array[j + 1] = stk->array[j]; 
            j = j - 1; 
        } 
        stk->array[j + 1] = element;
		i++;
    }
	midpoint = stk->array[(stk->len_a/2)];
	return(midpoint);
}