/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:28:08 by emeha             #+#    #+#             */
/*   Updated: 2019/01/04 10:25:11 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	res;

	res = 0;
	i = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\f' ||
	str[i] == '\v' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res * 10 / 10 != res)
			return ((neg == -1) ? 0 : -1);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * neg);
}
