/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 00:15:13 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 17:04:23 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_utoi(const char *str)
{
	int					i;
	unsigned long long	res;

	res = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\f' ||
	str[i] == '\v' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res * 10 / 10 != res)
			return (-1);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}
