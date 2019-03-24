/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:13:42 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 21:20:31 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

// static void	printf_flag_d_1()
// {
	
// }

int			printf_flag_d(long long n, t_flist *elem)
{
	int num[4];

	num[0] = 0;
	num[3] = 0;
	if (n == 0 && elem->accu_r == 0 && elem->dot)
		num[2] = 0;
	else if (ft_numlen(n) > elem->accu_r)
		num[2] = ft_numlen(n);
	else
		num[2] = elem->accu_r;
	num[1] = 0;
	if ((elem->plus || elem->space) && n > -1)
		num[1] = 1;
	if (n < 0 && elem->accu_r > 0 && ft_numlen(n) <= elem->accu_r)
		num[3] = 1;
	if (elem->minus == 0)
	{
		while (num[0] < elem->accu_l - num[1] - num[2] - num[3] && (elem->dot == 1 ||
					(elem->accu_r == 0 && elem->zero == 0)))
		{
			ft_putchar(' ');
			num[0]++;
		}
		if (n < 0)
			ft_putchar('-');
		else if (elem->plus == 1 && n > -1)
			ft_putchar('+');
		else if (elem->plus == 0 && elem->space == 1 && n > -1)
			ft_putchar(' ');
		while (num[0] < elem->accu_l - num[1] - num[2] && elem->dot == 0)
		{
			ft_putchar('0');
			num[0]++;
		}
		num[2] = ft_numlen(n);
		while (elem->accu_r - num[2] + num[3] > 0)
		{
			ft_putchar('0');
			num[2]++;
		}
		if (n == 0 && elem->dot == 1 && elem->accu_r == 0)
			num[2] = 0;
		else
			ft_putnbr(n);
		return (num[2] + num[0] + num[1]);
	}
	else
	{
		if (n < 0)
			ft_putchar('-');
		else if (elem->plus == 1 && n > -1)
			ft_putchar('+');
		else if (elem->plus == 0 && elem->space == 1 && n > -1)
			ft_putchar(' ');
		num[2] = ft_numlen(n);
		while (elem->accu_r - num[2] + num[3] > 0)
		{
			ft_putchar('0');
			num[2]++;
		}
		ft_putnbr(n);
		while (num[0] < elem->accu_l - num[1] - num[2] && (elem->dot == 1 ||
				elem->accu_r == 0))
		{
			ft_putchar(' ');
			num[0]++;
		}
		return (num[2] + num[0] + num[1]);
	}
}
