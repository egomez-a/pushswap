/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:22:36 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/25 22:17:31 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

/* Definicion de estructura de datos con las pilas */

typedef struct		s_pl
{
	int		argc;
	char	**argv;
	int		*stka;
	int		*stkb;
	int		*aux;
	int		len_a;
	int		len_b;
	int		len_max;
	int		flag;
	int		mov;
	int		top;
	int		top_index;
}					t_pl;

int		main(int argc, char **argv);
t_pl	*init_structure(t_pl *stk, int argc, char **argv);
int		check_duplicates(t_pl *stk);
int		check_order(t_pl *stk);
void	sa(t_pl		*stk);
void	sb(t_pl 	*stk);
void	ss(t_pl 	*stk);
void	pa(t_pl		*stk);
void	pb(t_pl		*stk);
void	ra(t_pl		*stk);
void	rb(t_pl		*stk);
void	rr(t_pl		*stk);
void	rra(t_pl	*stk);
void	rrb(t_pl	*stk);
void	rrr(t_pl	*stk);
void	push_aux_a(t_pl	*stk);
void	push_aux_b(t_pl	*stk);

void	orderlow(t_pl	*stk);
void	ordersix(t_pl	*stk);

#endif
