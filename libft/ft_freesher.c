/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:54:10 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/23 19:41:21 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freesher(char **str, int len)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
