/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:08:22 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 11:15:22 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_order(t_pl *stk)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < stk->len_max)
	{
		j = i + 1;
		while (j < stk->len_max)
		{
			if (stk->stka[i] < stk->stka[j])
				j++;
			else
				return ;
		}	
		i++;
	}
	printf("Stack in order\n");
	return ;
}

int 	check_duplicates(t_pl *stk)
{
	int i;
	int j;

	if (!(stk) || stk->len_a < 1)
	{
		write(2, "Error\n", 6);
		return (0);		
	}
	i = 0;
	while (i < stk->len_a)
	{
		j = 1 + i;
		while (j < stk->len_a)
		{
			if (stk->stka[i] == stk->stka[j])
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
