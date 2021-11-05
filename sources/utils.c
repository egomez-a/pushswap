/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:14:38 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/05 12:26:47 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** copy a str until stop character or end of string str
*/

char	*ft_strdup_char(const char *str, char stop)
{
	int		i;
	char	*pt;

	i = 0;
	while (str[i] && str[i] != stop)
		i++;
	pt = malloc((i + 1) * sizeof(char));
	if (!(pt))
		return (0);
	i = -1;
	while (str[++i] && str[i] != stop)
		pt[i] = str[i];
	pt[i] = '\0';
	return (pt);
}

/*
** atoi passing a pointer to the number in parameter and returning 1 if there is
** an error (not a number or not a integer)
*/

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
