/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:41:34 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/25 22:19:07 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int top_number(t_pl *stk)
{
	int	i;

	i = 1;
	stk->top = stk->stka[0];
	while (i < stk->len_a)
	{
		if (stk->stka[i] > stk->top)
		{
			stk->top = stk->stka[i];
			stk->top_index = i;
		}
		i++;
	}
	return (stk->top);
}

int		check_order(t_pl *stk)
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
				return (0);
		}	
		i++;
	}
	return (1);
}

void	transfer(t_pl *stk)
{
	

	pb(stk);
	return ;
}

void	orderfive(t_pl *stk)
{
	transfer(stk);
	while (stk->len_a > 3)
		pb(stk);
	orderlow(stk);
	if ((stk->len_b == 2) && (stk->stkb[0] < stk->stkb[1]))
		sb(stk);
	if ((stk->stkb[0] > stk->stka[0]) && (stk->stkb[0] < stk->stka[1]))
	{
		sa(stk);
		pa(stk);
		pa(stk);
		rra(stk);
	}
	if ((stk->stkb[0] > stk->stka[0]) && (stk->stkb[0] > stk->stka[1]) && (stk->stkb[0] > stk->stkb[2]))
	{
		pa(stk);
		pa(stk);
		ra(stk);
		ra(stk);
	}
	if ((stk->stkb[0] > stk->stka[0]) && (stk->stkb[0] > stk->stkb[1]) && (stk->stkb[0] < stk->stkb[2]))
	{
		pa(stk);
		pa(stk);
		ra(stk);
		ra(stk);
		ra(stk);
	}
	if (stk->stkb[0] < stk->stka[0])
	{
		pa(stk);
		pa(stk);
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
	if (stk)
	{
		printf("Stack A  --> ");
		while (i < stk->len_a)
		{
			printf("%d ",stk->stka[i]);
			i++;
		}
		printf("\n");
		printf("Top number is --> %d \n", top_number(stk));
		printf("Index of top number --> %d \n", stk->top_index);
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

int	main(int argc, char **argv)
{
	t_pl	*stk;
	
	stk = NULL;
	stk = init_structure(stk, argc, argv);
	printstacks(stk);
	if (check_order(stk) > 0)
	{
		printf("Stack in order\n");
		return (0);
	}
//	if ((stk) && (stk->len_a < 4))
//		orderlow(stk);
//	if ((stk) && ((stk->len_a < 6) && (stk->len_a > 3)))
//		orderfive(stk);
//	printstacks(stk);
	free(stk);
	return (0);
}