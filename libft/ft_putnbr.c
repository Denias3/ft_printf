/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:59:12 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 17:04:52 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long n)
{
	if (n < -9223372036854775807)
	{
		ft_putstr(ft_strdup("9223372036854775808"));
	}
	else if (n < 0)
	{
		n = -n;
		ft_putnbr(n);
	}
	else if (n < 10)
	{
		ft_putchar(n + 48);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
