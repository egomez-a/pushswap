/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:57:00 by egomez-a          #+#    #+#             */
/*   Updated: 2021/06/23 12:31:30 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Reserva memoria (con malloc(3)) y devuelve un nuevo
** elemento. La variable ’content’ se inicializa
** mediante el valor del parámetro ’content’. La
** variable ’next’ se inicializa con NULL.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	if (!(new_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_list->content = (void*)content;
	new_list->next = NULL;
	return (new_list);
}
