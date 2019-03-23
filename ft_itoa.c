/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:54:00 by emeha             #+#    #+#             */
/*   Updated: 2019/03/20 04:59:03 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strlenn(long long n, long long *del)
{
	int s;

	s = 0;
	while (del)
	{
		s++;
		if ((n / *del) == 0)
			break ;
		*del = *del * 10;
	}
	return (s);
}

static int	ft_itoa_alg(long long *n, long long *del, long long num)
{
	num = *n / (*del /= 10);
	*n -= num * *del;
	return (num);
}

char		*ft_itoa(long long n)
{
	long long	del;
	int		i;
	int		s;
	long long	num;
	char	*nb;

	i = 0;
	del = 10;
	num = 0;
	// if (n == -2147483648)
		// return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	s = ft_strlenn(n, &del);
	if ((nb = ft_strnew(s += i)) == NULL)
		return (NULL);
	if (i == 1)
		nb[0] = '-';
	while (i < s)
		nb[i++] = (ft_itoa_alg(&n, &del, num) + 48);
	return (nb);
}
