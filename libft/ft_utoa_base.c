/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:52:16 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 18:31:32 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned long long	ft_strlenn(unsigned long long n,
		unsigned long long *del)
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

static unsigned long long	ft_utoa_alg(unsigned long long *n,
		unsigned long long *del, unsigned long long num)
{
	num = *n / (*del /= 10);
	*n -= num * *del;
	return (num);
}

char						*ft_utoa(unsigned long long n)
{
	unsigned long long	del;
	int					i;
	int					s;
	unsigned long long	num;
	char				*nb;

	i = 0;
	del = 10;
	num = 0;
	s = ft_strlenn(n, &del);
	if ((nb = ft_strnew(s += i)) == NULL)
		return (NULL);
	while (i < s)
		nb[i++] = (ft_utoa_alg(&n, &del, num) + 48);
	return (nb);
}

char						*ft_utoa_base(unsigned long long v,
		unsigned long long base)
{
	char *str;

	str = ft_strnew(0);
	while (v >= base)
	{
		if ((v % base) < 10)
			str = ft_strjoin_free(str, ft_utoa(v % base));
		else if ((v % base) > 9)
			str = ft_strjoin_free(str, ft_chardup(55 + (v % base)));
		v = v / base;
	}
	if ((v % base) < 10)
		str = ft_strjoin_free(str, ft_utoa(v % base));
	else if ((v % base) > 9)
		str = ft_strjoin_free(str, ft_chardup(55 + (v % base)));
	ft_strref(str);
	return (str);
}
