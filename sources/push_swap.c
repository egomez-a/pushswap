/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:41:34 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/27 13:27:30 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	transfer(t_pl *stk)
{
	top_number(stk);
	if (((stk->position.top_index) + 1) <= ((stk->len_a)/2) && (stk->stka[0] != stk->position.top))
	{
		while (stk->stka[0] != stk->position.top)
			ra(stk);
	}
	if (((stk->position.top_index) + 1) > ((stk->len_a)/2) && (stk->stka[0] != stk->position.top))
	{
		while (stk->stka[0] != stk->position.top)
			rra(stk);
	}
	return ;
}

void	orderfive(t_pl *stk)
{
	transfer(stk);
	while (stk->len_a > 3)
		pb(stk);
	orderlow(stk);
	if ((stk->len_b == 2) && (stk->stkb[0] > stk->stkb[1]))
		sb(stk);
	if ((stk->stkb[0] < stk->stka[0]) && (stk->stkb[0] < stk->stka[1]) &&(stk->stkb[0] < stk->stka[2]))
	{
		pa(stk);
		pa(stk);
		ra(stk);
	}
	else if ((stk->stkb[0] > stk->stka[0]) && (stk->stkb[0] < stk->stka[1]) &&(stk->stkb[0] < stk->stka[2]))
	{
		pa(stk);
		sa(stk);
		pa(stk);
		ra(stk);
	}
	else if ((stk->stkb[0] > stk->stka[0]) && (stk->stkb[0] > stk->stka[1]) &&(stk->stkb[0] < stk->stka[2]))
	{
		rra(stk);
		pa(stk);
		ra(stk);
		ra(stk);
		pa(stk);
		ra(stk);
	}
	else
	{
		pa(stk);
		ra(stk);
		pa(stk);
		ra(stk);
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

t_pl	*init_structure(t_pl *stk, int argc, char **argv)
{
	int i;

	i = 0;
	stk = ft_calloc(sizeof(t_pl), 1);
	stk->len_a = argc - 1;
	stk->len_max = stk->len_a;
	stk->stka = ft_calloc(stk->len_max, sizeof(int));
	stk->stkb = ft_calloc(stk->len_max, sizeof(int));
	while (i < stk->len_a)
	{
		stk->stka[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	stk->argc = argc;
	stk->argv = argv;
	return (stk);
}

int	main(int argc, char **argv)
{
	t_pl	*stk;
	
	stk = NULL;
	stk = init_structure(stk, argc, argv);
	check_order(stk);
	printstacks(stk);
	if (check_duplicates(stk) == 0)
		return (0);
//	if ((stk) && (stk->len_a < 4))
//		orderlow(stk);
//	if ((stk) && ((stk->len_a < 6) && (stk->len_a > 3)))
//		orderfive(stk);
//	if ((stk) && (stk->len_a >= 6))
	orderbig(stk);
	printstacks(stk);
	free(stk);
	return (0);
}