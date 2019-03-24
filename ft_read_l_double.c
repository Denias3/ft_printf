/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_l_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:42:14 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 18:42:15 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_read_l_double(long double n, t_flist *elem)
{
	char	*res;
	int		i;
	int		st;

	i = 0;
	if (n < 0)
	{
		n = -n;
		res = ft_strnew(1);
		res[0] = '-';
	}
	else
		res = ft_strnew(0);
	res = ft_strjoin_free(res, ft_itoa((long long)n));
	res = ft_strjoin_free(res, ft_chardup('.'));
	n = n - (long long)n;
	st = ((elem->accu_r == 0 && elem->dot == 0) ? 6 : elem->accu_r);
	while (i < st + 1)
	{
		n = n * 10;
		res = ft_strjoin_free(res, ft_chardup((long long)n + 48));
		n = n - (long long)n;
		i++;
	}
	return (res);
}
