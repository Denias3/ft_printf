/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:56:38 by emeha             #+#    #+#             */
/*   Updated: 2019/01/12 15:56:41 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
char *ft_read_double(double n)
{
	char	*res;
	int 	i;
	i = 0;
	res = ft_strnew(0);
	while (i < 55)
	{
		if (i == 0)
		{
			res = ft_strjoin(res, ft_itoa((int) n));
			res = ft_strjoin(res, ft_chardup('.'));
			n = n - (int)n;
		}
		else
		{
			n = n * 10;
			res = ft_strjoin(res, ft_chardup(((int)n) + 48));
			n = n - (int)n;
		}
		i++;
	}
	return (res);
}