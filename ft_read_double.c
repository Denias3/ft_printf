/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:56:38 by emeha             #+#    #+#             */
/*   Updated: 2019/03/21 16:47:44 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char *ft_read_double(long double n, t_flist *elem)
{
	char				*res;
	int 				i;
	unsigned long long 	fr;
	int 				st;

	i = 0;
	if (n < 0)
	{
		n = -n;
		res = ft_strnew(1);
		res[0] = '-';
	}
	else
		res = ft_strnew(0);
	fr = n;
	res = ft_strjoin_free(res, ft_itoa(fr));
	res = ft_strjoin_free(res, ft_chardup('.'));
	n = n - fr;
	st = ((elem->accu_r == 0 && elem->dot == 0) ? 6 : elem->accu_r);
	while (i < st + 1)
	{
		n = n * 10;
		fr = n;
		res = ft_strjoin_free(res, ft_chardup(fr + 48));
		n = n - fr;
		i++;
	}
	return (res);
}