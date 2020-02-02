/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 23:33:35 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/23 19:56:24 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *new;
	t_list *lst_0;

	if (!lst || !f)
		return (NULL);
	lst_0 = lst;
	temp = f(lst_0);
	new = temp;
	while (lst_0->next)
	{
		temp->next = f(lst_0->next);
		lst_0 = lst_0->next;
		temp = temp->next;
	}
	return (new);
}
