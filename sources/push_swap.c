/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:41:34 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/22 18:04:08 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Switch_a intercambia el primer elemento con el segundo */

void	sa(t_pl *stack)
{
	int aux;
	
	if (stack->stack_a)
	{
		if (stack->flag == 0)
			write(1, "sa\n", 4);
		aux = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = aux;
	}
	return;
}

void	sb(t_pl *stack)
{
	int aux;
	
	if (stack->stack_b)
	{
		if (stack->flag == 0)
			write(1, "sb\n", 4);
		aux = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = aux;
	}
	return;
}

void	ss(t_pl *stack)
{ 
	stack->flag = 1;
	sa(stack);
	sb(stack);
	write(1, "ss\n", 4);
	stack->flag = 0;
	return;
}

/* Push_a manda el primer elemento en pila_b al top de pila_a */

void	pa(t_pl	*stack)
{
	int i;
	int j;
	
	i = 0;
	j = 1;
	if (stack->stack_b)
	{
		stack->aux = ft_calloc(stack->len_a, sizeof(int));
		stack->len_b = stack->len_b - 1;
		stack->len_a = stack->len_a + 1;
		stack->aux = stack->stack_a;
		stack->stack_a[0] = stack->stack_b[0];
		while (i < stack->len_b)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		while (j < stack->len_a)
		{
			stack->stack_a[j] = stack->aux[j - 1];
			j++;
		}
		free(stack->aux);
		write(2, "pa\n", 4);
	}
	return;
}

/* Push_b manda el primer elemento en pila_a al top de pila_b */

void	pb(t_pl	*stack)
{
	int i;
	int j;
	
	i = 0;
	j = 1;
	if (stack->stack_a)
	{
		stack->aux = ft_calloc(stack->len_b, sizeof(int));
		stack->len_a = stack->len_a - 1;
		stack->len_b = stack->len_b + 1;
		stack->aux = stack->stack_b;
		stack->stack_b[0] = stack->stack_a[0];
		while (i < stack->len_a)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
			i++;
		}
		while (j < stack->len_b)
		{
			stack->stack_b[j] = stack->aux[j - 1];
			j++;
		}	
		free(stack->aux);
		write(2, "pb\n", 4);
	}
	return;
}

/* Rotate desplaza hacia arriba todos los elementos de la pila */
/* y el primero pasa a ser el último */

void	ra(t_pl *stack)
{
	int	i;
	int aux;

	i = 0;
	if (stack->stack_a)
	{
		if (stack->flag == 0)
			write(2, "ra\n", 4);
		aux = stack->stack_a[0];
		while (i < stack->len_a - 1)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
			i++;
		}
		stack->stack_a[i] = aux;
	}
	return;
}

void	rb(t_pl *stack)
{
	int	i;
	int aux;

	i = 0;
	if (stack->stack_b)
	{
		if (stack->flag == 0)
			write(2, "rb\n", 4);
		aux = stack->stack_b[0];
		while (i < stack->len_b - 1)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		stack->stack_b[i] = aux;
	}
	return;
}

void	rr(t_pl *stack)
{ 
	stack->flag = 1;
	ra(stack);
	rb(stack);
	write(1, "rr\n", 4);
	stack->flag = 0;
	return;
}

/* Reverse Rotate desplaza hacia abajo todos los elementos de la pila */
/* y el ultimo pasa a ser el primero */

void	rra(t_pl *stack)
{
	int	i;
	int aux;

	i = stack->len_a - 1;
	if (stack->stack_a)
	{
		if (stack->flag == 0)
			write(2, "rra\n", 5);
		aux = stack->stack_a[stack->len_a - 1];
		while (i > 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
		stack->stack_a[i] = aux;
	}
	return;
}

void	rrb(t_pl *stack)
{
	int	i;
	int aux;

	i = stack->len_b - 1;
	if (stack->stack_b)
	{
		if (stack->flag == 0)
			write(2, "rrb\n", 5);
		aux = stack->stack_b[stack->len_b - 1];
		while (i > 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
		stack->stack_b[i] = aux;
	}
	return;
}

void	rrr(t_pl *stack)
{ 
	stack->flag = 1;
	rra(stack);
	rrb(stack);
	write(1, "rrr\n", 5);
	stack->flag = 0;
	return;
}

int 	check_duplicates(t_pl *stack)
{
	int i;
	int j;

	if (!(stack) || stack->argc < 3) 
	{
		write(2, "Error\n", 6);
		free(stack);
		return (0);		
	}
	i = 0;
	while (i < stack->len_a)
	{
		j = 1 + i;
		while (j < stack->len_a)
		{
			if ((stack->stack_a[i] == stack->stack_a[j]) || (sizeof(stack->stack_a[i]) <= 2))
			{
				write(2, "Error\n", 6);
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
	stack->stack_b = ft_calloc(stack->len_a, sizeof(int));

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
	t_pl	*stack;
	
	stack = NULL;
	stack = init_structure(stack, argc, argv);
	rra(stack);
	return (0);
}