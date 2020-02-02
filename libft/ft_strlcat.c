/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:10:46 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/21 20:31:43 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char const *str, size_t n)
{
	size_t i;
	size_t slen;
	size_t dlen;

	i = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen((char *)str);
	if (dlen >= n)
		return (n + slen);
	while (dest[i] && i < (n - 1))
		i++;
	while (*str && i < (n - 1))
	{
		dest[i] = (char)*str;
		i++;
		str++;
	}
	dest[i] = '\0';
	return (dlen + slen);
}
