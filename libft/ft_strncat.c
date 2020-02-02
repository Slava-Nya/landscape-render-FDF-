/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:06:18 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/20 19:02:18 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char const *str, size_t n)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dest);
	i = 0;
	while (str[i] && i < n)
	{
		dest[len + i] = str[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
