/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:41:34 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/24 13:23:22 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Switch_a intercambia el primer elemento con el segundo */

void	sa(t_pl *stk)
{
	int	aux;

	if (stk->stka)
	{
		if (stk->flag == 0)
			write(1, "sa\n", 4);
		aux = stk->stka[0];
		stk->stka[0] = stk->stka[1];
		stk->stka[1] = aux;
	}
	return;
}

void	sb(t_pl *stk)
{
	int aux;
	
	if (stk->stkb)
	{
		if (stk->flag == 0)
			write(1, "sb\n", 4);
		aux = stk->stkb[0];
		stk->stkb[0] = stk->stkb[1];
		stk->stkb[1] = aux;
	}
	return;
}

void	ss(t_pl *stk)
{ 
	stk->flag = 1;
	sa(stk);
	sb(stk);
	write(1, "ss\n", 4);
	stk->flag = 0;
	return;
}

/* Push_a manda el primer elemento en pila_b al top de pila_a */

void	pa(t_pl	*stk)
{
	int i;
	int j;
	int k;
	
	i = 0;
	j = 1;
	k = 0;
	if (stk->stkb)
	{
		stk->aux = ft_calloc(stk->len_a, sizeof(int));
		stk->len_b = stk->len_b - 1;
		stk->len_a = stk->len_a + 1;
		stk->aux = stk->stka;
		stk->stka[0] = stk->stkb[0];
		while (k < stk->len_a)
		{
			stk->aux[k] = stk->stka[k];
			k++;
		}
		while (i < stk->len_b)
		{
			stk->stkb[i] = stk->stkb[i + 1];
			i++;
		}
		while (j < stk->len_a)
		{
			stk->stka[j] = stk->aux[j - 1];
			j++;
		}
		free(stk->aux);
		write(2, "pa\n", 4);
	}
	return;
}

/* Push_b manda el primer elemento en pila_a al top de pila_b */

void	pb(t_pl	*stk)
{
	int i;
	int j;
	int k;
	
	i = 0;
	j = 1;
	k = 0;
	
	if (stk->stka)
	{
		stk->aux = ft_calloc(stk->len_b, sizeof(int));
		stk->len_a = stk->len_a - 1;
		stk->len_b = stk->len_b + 1;
		stk->aux = stk->stkb;
		stk->stkb[0] = stk->stka[0];
		while (k < stk->len_b)
		{
			stk->aux[k] = stk->stkb[k];
			k++;
		}
		stk->stkb[0] = stk->stka[0];
		while (i < stk->len_a)
		{
			stk->stka[i] = stk->stka[i + 1];
			i++;
		}
		while (j < stk->len_b)
		{
			stk->stkb[j] = stk->aux[j - 1];
			j++;
		}	
		free(stk->aux);
		write(2, "pb\n", 4);
	}
	return;
}

/* Rotate desplaza hacia arriba todos los elementos de la pila */
/* y el primero pasa a ser el último */

void	ra(t_pl *stk)
{
	int	i;
	int aux;

	i = 0;
	if (stk->stka)
	{
		if (stk->flag == 0)
			write(2, "ra\n", 4);
		aux = stk->stka[0];
		while (i < stk->len_a - 1)
		{
			stk->stka[i] = stk->stka[i + 1];
			i++;
		}
		stk->stka[i] = aux;
	}
	return;
}

void	rb(t_pl *stk)
{
	int	i;
	int aux;

	i = 0;
	if (stk->stkb)
	{
		if (stk->flag == 0)
			write(2, "rb\n", 4);
		aux = stk->stkb[0];
		while (i < stk->len_b - 1)
		{
			stk->stkb[i] = stk->stkb[i + 1];
			i++;
		}
		stk->stkb[i] = aux;
	}
	return;
}

void	rr(t_pl *stk)
{ 
	stk->flag = 1;
	ra(stk);
	rb(stk);
	write(1, "rr\n", 4);
	stk->flag = 0;
	return;
}

/* Reverse Rotate desplaza hacia abajo todos los elementos de la pila */
/* y el ultimo pasa a ser el primero */

void	rra(t_pl *stk)
{
	int	i;
	int aux;

	i = stk->len_a - 1;
	if (stk->stka)
	{
		if (stk->flag == 0)
			write(2, "rra\n", 5);
		aux = stk->stka[stk->len_a - 1];
		while (i > 0)
		{
			stk->stka[i] = stk->stka[i - 1];
			i--;
		}
		stk->stka[i] = aux;
	}
	return;
}

void	rrb(t_pl *stk)
{
	int	i;
	int aux;

	i = stk->len_b - 1;
	if (stk->stkb)
	{
		if (stk->flag == 0)
			write(2, "rrb\n", 5);
		aux = stk->stkb[stk->len_b - 1];
		while (i > 0)
		{
			stk->stkb[i] = stk->stkb[i - 1];
			i--;
		}
		stk->stkb[i] = aux;
	}
	return;
}

void	rrr(t_pl *stk)
{ 
	stk->flag = 1;
	rra(stk);
	rrb(stk);
	write(1, "rrr\n", 5);
	stk->flag = 0;
	return;
}

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

int	main(int argc, char **argv)
{
	t_pl	*stk;
	
	stk = NULL;
	stk = init_structure(stk, argc, argv);
	if (stk->len_a < 4)
		orderlow(stk);
	if (stk->len_a < 7)
		ordersix(stk);
	return (0);
}