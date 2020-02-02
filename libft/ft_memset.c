/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:11:43 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/24 20:18:50 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	size_t		i;
	char		*str;

	str = (char *)memptr;
	i = 0;
	while (i < num)
	{
		str[i] = (char)val;
		i++;
	}
	return (memptr);
}
