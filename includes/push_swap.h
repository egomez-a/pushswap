/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:22:36 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/22 18:39:57 by egomez-a         ###   ########.fr       */
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
	int 	len_b;
	int		flag;
}					t_pl;

int		main(int argc, char **argv);
t_pl	*init_structure(t_pl *stack, int argc, char **argv);
int 	check_duplicates(t_pl *stack);
void	sa(t_pl		*stack);
void	sb(t_pl 	*stack);
void	ss(t_pl 	*stack);
void	pa(t_pl		*stack);
void	pb(t_pl		*stack);
void	ra(t_pl		*stack);
void	rb(t_pl		*stack);
void	rr(t_pl		*stack);
void	rra(t_pl	*stack);
void	rrb(t_pl	*stack);
void	rrr(t_pl	*stack);

#endif
