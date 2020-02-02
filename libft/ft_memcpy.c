/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:25:40 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/24 20:16:04 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *str, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*s1;

	s1 = (unsigned char *)str;
	d1 = (unsigned char *)dest;
	if (!n || str == dest)
	{
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		d1[i] = s1[i];
		i++;
	}
	return (dest);
}
