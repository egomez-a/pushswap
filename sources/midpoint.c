/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:57:46 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/27 13:15:14 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void insertion_sort(t_pl *stk) 
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

void	bottom_number(t_pl *stk)
{
	int i;

	i = 1;
	stk->position.bottom = stk->stka[0];
	while (i < stk->len_a)
	{
		if (stk->position.bottom > stk->stka[i])
		{
			stk->position.bottom = stk->stka[i];
			stk->position.bottom_index = i;
			i++;
		}
		else 
			i++;	
	}
	return ;
}

void top_number(t_pl *stk)
{
	int	i;

	i = 1;
	stk->position.top = stk->stka[0];
	while (i < stk->len_a)
	{
		if (stk->stka[i] > stk->position.top)
		{
			stk->position.top = stk->stka[i];
			stk->position.top_index = i;
		}
		i++;
	}
	return ;
}
