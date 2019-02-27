/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 12:08:40 by emeha             #+#    #+#             */
/*   Updated: 2019/01/13 12:08:42 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_read_float(float n)
{
	char	*res;
	int 	i;

	i = 0;
	res = ft_strnew(0);
	while (i < 40)
	{
		if (i == 0)
		{
			res = ft_strjoin(res, ft_itoa((int) n));
			res = ft_strjoin(res, ft_chardup('.'));
			n = n - (int)n;
		}
		else
		{
			n *= 10;
			res = ft_strjoin(res, ft_chardup(((int)n) + 48));
			n = n - (int)n;
		}
		i++;
	}
	return (res);
}