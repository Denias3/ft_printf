/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:04:52 by emeha             #+#    #+#             */
/*   Updated: 2019/03/25 17:27:05 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static unsigned long long	ft_numlen_u(unsigned long long n)
{
	long long	s;
	long long	del;

	del = 10;
	s = 1;
	while (n > 9)
	{
		s++;
		n = n / del;
	}
	return (s);
}

static void					printf_flag_u_1(unsigned long long n,
			t_flist *elem, int *num)
{
	while (num[0] < elem->accu_l - num[2] - num[1] && (elem->dot == 1 ||
			(elem->accu_r == 0 && elem->zero == 0)))
	{
		ft_putchar(' ');
		num[0]++;
	}
	while (num[0] < elem->accu_l - num[2] - num[1] && elem->dot == 0)
	{
		ft_putchar('0');
		num[0]++;
	}
	num[1] = ft_numlen_u(n);
	while (elem->accu_r - num[1] > 0)
	{
		ft_putchar('0');
		num[1]++;
	}
	if (n == 0 && elem->dot == 1 && elem->accu_r == 0)
		num[1] = 0;
	else
		ft_putnbr_u(n);
}

static void					printf_flag_u_2(unsigned long long n,
			t_flist *elem, int *num)
{
	num[1] = ft_numlen_u(n);
	while (elem->accu_r - num[1] > 0)
	{
		ft_putchar('0');
		num[1]++;
	}
	ft_putnbr_u(n);
	while (num[0] < elem->accu_l - num[2] - num[1] && (elem->dot == 1 ||
			elem->accu_r == 0))
	{
		ft_putchar(' ');
		num[0]++;
	}
}

int							printf_flag_u(unsigned long long n, t_flist *elem)
{
	int num[3];

	num[0] = 0;
	if (n == 0 && elem->accu_r == 0)
		num[1] = 1;
	else if ((int)ft_numlen_u(n) > elem->accu_r)
		num[1] = ft_numlen_u(n);
	else
		num[1] = elem->accu_r;
	num[2] = 0;
	if (elem->minus == 0)
	{
		printf_flag_u_1(n, elem, num);
		return (num[1] + num[0] + num[2]);
	}
	else
	{
		printf_flag_u_2(n, elem, num);
		return (num[1] + num[0] + num[2]);
	}
}
