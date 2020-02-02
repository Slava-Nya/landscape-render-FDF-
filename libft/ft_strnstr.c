/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:39:47 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/21 20:41:25 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *find, size_t n)
{
	size_t i;
	size_t pos;

	pos = 0;
	if (find[0] == '\0')
		return ((char *)str);
	while (str[pos] && pos < n)
	{
		if (str[pos] == find[0])
		{
			i = 1;
			while (find[i] && str[pos + i] == find[i] && (pos + i) < n)
				i++;
			if (find[i] == '\0')
				return ((char *)&str[pos]);
		}
		pos++;
	}
	return (0);
}
