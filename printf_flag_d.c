/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:13:42 by emeha             #+#    #+#             */
/*   Updated: 2019/01/15 18:13:44 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int printf_flag_d(long long n, t_flist *elem)
{
	int z;
	int s;
	int i;
	int min;

	i = 0;
	min = 0;
    if (n == 0 && elem->accu_r == 0)
        s = 0;
	else if (ft_numlen(n) > elem->accu_r)
		s = ft_numlen(n);
	else
		s = elem->accu_r;
	z = 0;
	if ((elem->plus || elem->space) && n > -1)
		z = 1;
	if (n < 0 && elem->accu_r > 0)
	    min = 1;
	if (elem->minus == 0)
	{
		while (i < elem->accu_l - z - s - min && (elem->dot == 1 || (elem->accu_r == 0 && elem->zero == 0)))
		{
			ft_putchar(' ');
			i++;
		}
		if (n < 0)
            ft_putchar('-');
		else if (elem->plus == 1 && n > -1)
			ft_putchar('+');
		else if (elem->plus == 0 && elem->space == 1 && n > -1)
			ft_putchar(' ');
		while (i < elem->accu_l - z - s && elem->dot == 0)
		{
			ft_putchar('0');
			i++;
		}
		s = ft_numlen(n);
		while (elem->accu_r - s + min > 0)
		{
			ft_putchar('0');
			s++;
		}
		if (n == 0 && elem->dot == 1 && elem->accu_r == 0)
		    s = 0;
		else
		    ft_putnbr(n);
		return (s + i + z);
	}
	else
	{
        if (n < 0)
            ft_putchar('-');
		else if (elem->plus == 1 && n > -1)
			ft_putchar('+');
		else if (elem->plus == 0 && elem->space == 1 && n > -1)
			ft_putchar(' ');
		s = ft_numlen(n);
		while (elem->accu_r - s > 0)
		{
			ft_putchar('0');
			s++;
		}
		ft_putnbr(n);
		while (i < elem->accu_l - z - s && (elem->dot == 1 || elem->accu_r == 0))
		{
			ft_putchar(' ');
			i++;
		}
		return (s + i + z);
	}
}