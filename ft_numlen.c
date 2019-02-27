/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:00:52 by emeha             #+#    #+#             */
/*   Updated: 2018/12/04 10:04:07 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_numlen(long long n)
{
	long long  s;
	long long del;

	del = 10;
	s = 0;
	if (n < 0)
		s++;
	while (del)
	{
		s++;
		if ((n / del) == 0)
			break ;
		del = del * 10;
	}
	return (s);
}
