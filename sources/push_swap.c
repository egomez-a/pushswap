/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:41:34 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 19:47:10 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pl	*init_structure(t_pl *stk, int argc, char **argv)
{
	int	i;

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
	return (stk);
}

t_pl	*init_structure_split(char **split, t_pl *stk)
{
	int	i;

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
	return (stk);
}

void	free_leaks(t_pl *stk, char **split)
{
	free(stk->ck.chunk);
	free(stk->stka);
	free(stk->stkb);
	free(stk->posa.array);
	free(stk->posb.array);
	free(stk);
	if (split)
		ft_freematrix(split);
}

int	main(int argc, char **argv)
{
	t_pl	*stk;
	char	**split;

	stk = NULL;
	split = NULL;
	if (argc > 2)
		stk = init_structure(stk, argc, argv);
	else
	{
		split = ft_split(argv[1], ' ');
		stk = init_structure_split(split, stk);
	}
	if (check_duplicates(stk))
	{
		if ((stk) && (stk->len_a < 4))
			orderlow(stk);
		if ((stk) && ((stk->len_a < 6) && (stk->len_a > 4)))
			orderfive(stk);
		else
			orderstackbychunks(stk);
	}
	printstacks(stk);
	free_leaks(stk, split);
	return (0);
}
