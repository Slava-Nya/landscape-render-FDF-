/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:13:06 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/22 21:00:24 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		len;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	len = (int)ft_strlen(s) - 1;
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (len >= i && len >= 0 &&
			(s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	if (!(new = (char *)malloc(sizeof(char) * (len - i + 2))))
		return (NULL);
	while (i <= len)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
