/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squareroot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:35:12 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/17 12:25:17 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Función para estimar raiz cuadrada. Algoritmo babilónico */

#include "../includes/push_swap.h"

int	ft_squareroot(int n)
{
	float	temp;
	float	sqrt;

	sqrt = n / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (n / temp + temp) / 2;
	}
	return (sqrt);
}
