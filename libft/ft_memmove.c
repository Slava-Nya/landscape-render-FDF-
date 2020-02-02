/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:09:33 by hlorrine          #+#    #+#             */
/*   Updated: 2019/10/05 16:48:07 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *source, size_t num)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)source;
	if (d == NULL && s == NULL)
		return (NULL);
	if (s < d)
		while ((int)(--num) >= 0)
			d[num] = s[num];
	else
	{
		i = 0;
		while (i < num)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
