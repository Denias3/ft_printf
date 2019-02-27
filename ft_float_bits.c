/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:15:55 by emeha             #+#    #+#             */
/*   Updated: 2019/01/09 19:15:57 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_float_bits(float m)
{
	int i;
	long *z;
	char *str;

	i = 0;
	str = ft_strnew(32);
	z = (long*)&m;
	while (i < 32)
	{
		str = ft_strjoin(str, ft_itoa((*z) >> (31 - i) & 1));
		i++;
	}
	return (str);
}
