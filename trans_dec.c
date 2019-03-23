/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:54:30 by emeha             #+#    #+#             */
/*   Updated: 2019/03/18 17:54:01 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	trans_dec(char *str_bit)
{
	int s;
	int i;
	long long res;

	res = 0;
	i = 0;
	s = ft_strlen(str_bit);
	while (s--)
	{
		if (str_bit[s] == '1')
		{
			res = res + (ft_pow(2, i));
		}
		i++;
	}
	return (res);
}