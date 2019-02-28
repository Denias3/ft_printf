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

int printf_flag_d(int n, t_flist *elem)
{
	int z;
	int s;
	int i;

	i = 0;
//	if (ft_strcmp(elem->flag, "hh") == 0)
//	{
//		n = (char)n;
//	}
//	else if (ft_strcmp(elem->flag, "h") == 0)
//	{
//		n = (short int)n;
//	}
//	else if (ft_strcmp(elem->flag, "ll") == 0)
//	{
//		n = (long long)n;
//	}
//	else if (ft_strcmp(elem->flag, "l") == 0)
//	{
//		n = (long)n;
//	}
	if (ft_numlen(n) > elem->accu_r)
		s = ft_numlen(n);
	else
		s = elem->accu_r;
	z = 0;
	if ((elem->plus || elem->space) && n > -1)
		z = 1;
	if (elem->minus == 0)
	{
		while (i < elem->accu_l - z - s && (elem->dot == 1 || elem->accu_r == 0) && elem->zero == 0)
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
		while (elem->accu_r - s > 0)
		{
			ft_putchar('0');
			s++;
		}
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