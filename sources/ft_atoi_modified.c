/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_modified.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:14:38 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/05 12:59:06 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* atoi pasa un puntero al número en parámetro de entrada y retorna 0 si */
/* hay un error (no un número entero) */

int	ft_atoi_modified(const char *str, int *nbr)
{
	char	*ptr;
	int		sign;
	long	num;
	size_t	i;

	ptr = (char *)str;
	num = 0;
	sign = 1;
	if ((*str == '-') || (*str == '+'))
	{
		if (*ptr == '-' && ptr++)
			sign *= -1;
	}
	if ((*ptr == '\0') || (*str == '-') || (*str == '+'))
		return (0);
	i = 0;
	while (*ptr >= '0' && *ptr <= '9' && i++ < 10)
		num = num * 10 + *ptr++ - '0';
	if (*ptr != '\0' || num * sign > 2147483647 || num * sign < -2147483648)
		return (0);
	*nbr = num * sign;
	return (1);
}
