/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:41:34 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/25 12:40:18 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ordersix(t_pl *stk)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (stk->len_a > 3)
		pb(stk);
	orderlow(stk);
	while(stk->len_b < 1)
	{
		pa(stk);
		j++;
	}
	while (j == 0)
	{
		ra(stk);
		j--;
	}
	while (stk->len_a > 3)
		pb(stk);
	orderlow(stk);
	while(stk->len_b < 1)
	{
		pa(stk);
		j++;
	}
	return;
}

void	orderlow(t_pl *stk)
{
	if ((stk->len_a == 1) || ((stk->len_a == 2) && (stk->stka[0] < stk->stka[1])))
		return ;
	else if ((stk->len_a == 2) && (stk->stka[0] > stk->stka[1]))
	{
		sa(stk);
		return ;
	}
	else if (stk->stka[0] > stk->stka[1])
	{
		if (stk->stka[1] > stk->stka[2] && stk->stka[0] > stk->stka[2])
		{
			sa(stk);
			rra(stk);
			return ;
		}
		else if (stk->stka[1] < stk->stka[2] && stk->stka[0] > stk->stka[2])
		{
			ra(stk);
			return ;
		}
		else if (stk->stka[1] < stk->stka[2] && stk->stka[0] < stk->stka[2])
		{	
			sa(stk);
			return ;
		}
	}
	else
	{
		if (stk->stka[1] > stk->stka[2] && stk->stka[0] < stk->stka[2])
		{
			sa(stk);
			ra(stk);
			return ;
		}
		else if (stk->stka[1] > stk->stka[2] && stk->stka[0] > stk->stka[2])
		{
			rra(stk);
			return ;
		}
		else if (stk->stka[1] < stk->stka[2] && stk->stka[0] < stk->stka[2])
		{	
			return ;
		}
	}
}



int 	check_duplicates(t_pl *stk)
{
	int i;
	int j;

	if (!(stk) || stk->argc < 2)
	{
		write(2, "Error\n", 6);
		free(stk);
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
				free(stk);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_pl	*init_structure(t_pl *stk, int argc, char **argv)
{
	int i;

	i = 0;
	stk = ft_calloc(sizeof(t_pl), 1);
	stk->len_a = argc - 1;
	stk->stka = ft_calloc(stk->len_a, sizeof(int));
	stk->stkb = ft_calloc(stk->len_a, sizeof(int));
	stk->len_max = stk->len_a;
	while (i < stk->len_a)
	{
		stk->stka[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	stk->argc = argc;
	stk->argv = argv;
	check_duplicates(stk);
	return (stk);
}

void	printstacks(t_pl *stk)
{
	int i;
	
	i = 0;
	printf("Stack A    Stack B\n");
	while (i < stk->len_max)
	{
		printf("   %d          %d\n",stk->stka[i],stk->stkb[i]);
		i++;
	}
	return ;
}


int	main(int argc, char **argv)
{
	t_pl	*stk;
	
	stk = NULL;
	stk = init_structure(stk, argc, argv);
	printstacks(stk);
//	if (stk->len_a < 4)
//		orderlow(stk);
//	if ((stk->len_a < 7) && (stk->len_a > 3))
//		ordersix(stk);
	pb(stk);
	printstacks(stk);
	pb(stk);
	printstacks(stk);
	pb(stk);
	printstacks(stk);
	pb(stk);
	printstacks(stk);
	free(stk);
	return (0);
}