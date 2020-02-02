/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverselst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:24:50 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/23 19:29:55 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_reverselst(t_list *lst)
{
	t_list *actual;
	t_list *prev;
	t_list *next;

	prev = NULL;
	actual = lst;
	while (actual != NULL)
	{
		next = actual->next;
		actual->next = prev;
		prev = actual;
		actual = next;
	}
	lst = prev;
	return (lst);
}
