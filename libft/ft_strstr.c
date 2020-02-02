/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:56:58 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/21 20:41:01 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *find)
{
	size_t i;
	size_t pos;

	pos = 0;
	if (find[0] == '\0')
		return ((char *)str);
	while (str[pos])
	{
		if (str[pos] == find[0])
		{
			i = 1;
			while (find[i] && str[pos + i] == find[i])
				i++;
			if (find[i] == '\0')
				return ((char *)&str[pos]);
		}
		pos++;
	}
	return (0);
}
