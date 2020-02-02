/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:30:32 by hlorrine          #+#    #+#             */
/*   Updated: 2020/01/29 17:48:13 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_math_pow(int nmb, int power)
{
	if (power == 0)
		return (1);
	while (--power > 0)
		nmb *= 16;
	return (nmb);
}

int		ft_math(char *str, char *base, int len)
{
	int		num;
	int		res;
	int		sym;
	int		i;

	i = 0;
	res = 0;
	while (len >= 0)
	{
		sym = 0;
		while (base[sym] != str[i])
			sym++;
		num = ft_math_pow(16, len);
		res += (sym * num);
		len--;
		i++;
	}
	return (res);
}

int		ft_atoi_base(char *str)
{
	char	*base_lower;
	char	*base_upper;
	int		i;
	int		len;

	i = -1;
	len = 0;
	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	while (str[++i] && (str[i] >= 48 && str[i] <= 57))
		i++;
	while (str[len])
		len++;
	if (str[i] >= 65 && str[i] <= 90)
		return (ft_math(str, base_upper, len - 1));
	else
		return (ft_math(str, base_lower, len - 1));
}
