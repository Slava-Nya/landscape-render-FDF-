/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:29:20 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/24 20:24:52 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_malloch(int n)
{
	char	*str;
	int		i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	return (str);
}

static void		ft_putnum(char *str, int n, int *i)
{
	if (n >= 10)
	{
		ft_putnum(str, n / 10, i);
		str[*i] = n % 10 + '0';
		*i += 1;
	}
	else if (n < 10)
	{
		str[*i] = n + '0';
		*i += 1;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_malloch(n);
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	ft_putnum(str, n, &i);
	str[i] = '\0';
	return (str);
}
