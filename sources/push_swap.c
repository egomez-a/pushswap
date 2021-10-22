/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:41:34 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/22 12:49:41 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int 	check_duplicates(t_pl *stack)
{
	int i;
	int j;

	i = 0;
	while (i < stack->len_a)
	{
		j = 1 + i;
		while (j < stack->len_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
			{
				printf("Error!! - Duplicates terms");
				free(stack);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_pl	*init_structure(t_pl *stack, int argc, char **argv)
{
	int i;

	i = 0;
	stack = ft_calloc(sizeof(t_pl), 1);
	stack->len_a = argc - 1;
	stack->stack_a = ft_calloc(stack->len_a, sizeof(int));
	while (i < stack->len_a)
	{
		stack->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	stack->argc = argc;
	stack->argv = argv;
	check_duplicates(stack);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_pl *stack;
	stack = NULL;
	stack = init_structure(stack, argc, argv);
	if (!(stack) || argc < 3) 
	{
		write(2, "Error\n", 6);
		return (0);		
	}
	return (0);
}