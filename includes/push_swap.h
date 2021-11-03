/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:22:36 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/03 20:38:08 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Para probar con cadenas instrucción es: */
/* ARG=$(ruby -e "puts (0..100).to_a.shuffle.join(' ')"); ./push_swap $ARG */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

/* Definicion de estructura de datos con las pilas */

typedef struct s_pos_a
{
	int		*array;
	int		max;
	int		max_index;
	int		min;
	int		min_index;
	int		index;
}				t_pos_a;

typedef struct s_pos_b
{
	int		*array;
	int		max;
	int		max_index;
	int		min;
	int		min_index;
	int		index;
}				t_pos_b;

typedef struct s_chunk
{
	int		chunksize;
	int		*chunk;
	int		n_chunk;
	int		rest_chunk;
	int		ckcnt;
}				t_chunk;

typedef struct s_index
{
	int		flag;
	int		flagrotate;
	int		mov;
	int		flagorder;
	int		count;
}				t_index;

typedef struct s_pl
{
	int		argc;
	int		*stka;
	int		*stkb;
	int		*aux;
	int		len_a;
	int		len_b;
	int		len_max;
	t_index	index;
	t_pos_a	posa;
	t_pos_b	posb;
	t_chunk	ck;
}				t_pl;

int		main(int argc, char **argv);
t_pl	*init_structure(t_pl *stk, int argc, char **argv);
t_pl	*init_structure_split(char **split, t_pl *stk);
int		check_duplicates(t_pl *stk);
int		check_order(t_pl *stk);
void	sa(t_pl	*stk);
void	sb(t_pl *stk);
void	ss(t_pl *stk);
void	pa(t_pl	*stk);
void	pb(t_pl	*stk);
void	ra(t_pl	*stk);
void	rb(t_pl	*stk);
void	rr(t_pl	*stk);
void	rra(t_pl *stk);
void	rrb(t_pl *stk);
void	rrr(t_pl *stk);
void	push_aux_a(t_pl	*stk);
void	push_aux_b(t_pl	*stk);
void	orderlow(t_pl *stk);
void	orderfive(t_pl *stk);
void	min_number_a(t_pl *stk);
void	min_number_b(t_pl *stk);
void	max_number_a(t_pl *stk);
void	max_number_b(t_pl *stk);
void	transfer(t_pl *stk);
void	insertion_sort(t_pl *stk);
void	orderstack(t_pl *stk);
void	order_stackb(t_pl *stk);
void	orderstacka(t_pl *stk);
void	chunks_size(t_pl *stk);
void	chunk_limits(t_pl *stk);
void	place_number(t_pl *stk);
void	chunkselection(t_pl	*stk);
void	orderstackbychunks(t_pl *stk);
void	pushmintotop_a(t_pl *stk);
void	pushmintotop_b(t_pl *stk);
void	pushmaxtotop_b(t_pl *stk);
int		ft_squareroot(int n);
void	pushnumbertotop_a(t_pl *stk);
void	free_leaks(t_pl *stk, char **split);

#endif
