/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:22:36 by egomez-a          #+#    #+#             */
/*   Updated: 2021/10/21 17:02:33 by egomez-a         ###   ########.fr       */
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
	int		*stack_a;
	int		*stack_b;
	int		len_a;
	int 	len_b;	
}					t_pl;

int	main(int argc, char **argv);

#endif
