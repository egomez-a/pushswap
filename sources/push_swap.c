/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:41:34 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 11:17:01 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	transfer(t_pl *stk)
{
	max_number_a(stk);
	if (((stk->posa.max_index) + 1) <= ((stk->len_a)/2) && (stk->stka[0] != stk->posa.max))
	{
		while (stk->stka[0] != stk->posa.max)
			ra(stk);
	}
	if (((stk->posa.max_index) + 1) > ((stk->len_a)/2) && (stk->stka[0] != stk->posa.max))
	{
		while (stk->stka[0] != stk->posa.max)
			rra(stk);
	}
	return ;
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
	// stk->argc = argc;
	// stk->argv = argv;
	return (stk);
}

t_pl	*init_structure_split(char **split, t_pl *stk)
{
	int i;

	i = 0;
	stk = ft_calloc(sizeof(t_pl), 1);
	while (split[i])
		i++;
	stk->len_a = i;
	i = 0;
	stk->len_max = stk->len_a;
	stk->stka = ft_calloc(stk->len_max, sizeof(int));
	stk->stkb = ft_calloc(stk->len_max, sizeof(int));
	while (i < stk->len_a)
	{
		stk->stka[i] = ft_atoi(split[i]);
		i++;
	}
	//stk->argc = argc;
	return (stk);
}

void	leaks(void)
{
	system("leaks -q push_swap");
	return ;
}

void	free_arrays(t_pl *stk)
{
	int i;

	i = 0;
	if (stk->stka)
	{
		while (i < stk->len_a)
		{	
			stk->stka[i] = 0;
			i++;
		}
	}
	i = 0;
	if (stk->stkb)
	{
		while (i < stk->len_b)
		{	
			stk->stkb[i] = 0;
			i++;
		}
	}
	i = 0;
	if (stk->posa.array)
	{
		while (i < stk->len_max)
		{	
			stk->posa.array[i] = 0;
			i++;
		}
	}
	i = 0;
	if (stk->ck.chunk)
	{
		while (i < stk->ck.n_chunk)
		{	
			stk->ck.chunk[i] = 0;
			i++;
		}
	}
	
	return ;
}

void	free_leaks(t_pl *stk)
{
	free(stk->stka);
	free(stk->stkb);
	free(stk->posa.array);
	free(stk->ck.chunk);
	free(stk);
}

int	main(int argc, char **argv)
{
	t_pl	*stk;
	char 	**split;
	
	stk = NULL;
	atexit(leaks);
	if (argc > 2)
	{
		stk = init_structure(stk, argc, argv);
	}
	else
	{
		split = ft_split(argv[1], ' ');
		stk = init_structure_split(split, stk);
	}
	if (check_duplicates(stk) == 0)
	{
		free_arrays(stk);
		return (0);
	}
	if ((stk) && (stk->len_a < 4))
		orderlow(stk);
	if ((stk) && ((stk->len_a < 6) && (stk->len_a > 4)))
		orderfive(stk);
	else 
		orderstackbychunks(stk);
	printstacks(stk);
	free_arrays(stk);
	free_leaks(stk);
	return (0);
}