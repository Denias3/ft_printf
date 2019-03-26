/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:39:25 by emeha             #+#    #+#             */
/*   Updated: 2019/03/25 17:39:00 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	printf_flag_x_1(char **str, t_flist *elem, int *num)
{
	if (elem->hash == 1 && *(*str) != '0')
		num[2] = 2;
	if (*(*str) == '0' && elem->accu_r == 0 && elem->dot == 1)
		num[1] = 0;
	else
	{
		if ((int)ft_strlen(*str) > elem->accu_r)
			num[1] = ft_strlen(*str);
		else
			num[1] = elem->accu_r;
	}
}

static void	printf_flag_x_2(char **str, t_flist *elem, int *num)
{
	if (elem->hash == 1 && *(*str) != '0' && elem->zero == 1 && elem->dot == 0)
	{
		if (elem->spec == 'x')
			ft_putstr("0x");
		else if (elem->spec == 'X')
			ft_putstr("0X");
		elem->hash = 2;
	}
	while (num[0] < elem->accu_l - num[1] - num[2])
	{
		if (elem->zero == 1 && elem->dot == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		num[0]++;
	}
	if (*(*str) == '0' && elem->accu_r == 0 && elem->dot == 1)
		num[1] = 0;
	else
		num[1] = ft_strlen(*str);
}

static void	printf_flag_x_3(char **str, t_flist *elem, int *num)
{
	if (elem->hash == 1 && *(*str) != '0')
	{
		if (elem->spec == 'x')
			ft_putstr("0x");
		else if (elem->spec == 'X')
			ft_putstr("0X");
	}
	while (elem->accu_r - num[1] > 0)
	{
		ft_putchar('0');
		num[1]++;
	}
	if (!(*(*str) == '0' && elem->accu_r == 0 && elem->dot == 1))
		ft_putstr(*str);
}

static void	printf_flag_x_4(char **str, t_flist *elem, int *num)
{
	if (elem->hash == 1 && *(*str) != '0')
	{
		if (elem->spec == 'x')
			ft_putstr("0x");
		else if (elem->spec == 'X')
			ft_putstr("0X");
		num[2] = 2;
	}
	num[0] = ft_strlen(*str);
	while (elem->accu_r - num[0] > 0)
	{
		ft_putchar('0');
		num[0]++;
	}
	if (!(*(*str) == '0' && elem->accu_r == 0 && elem->dot == 1))
		ft_putstr(*str);
	else
		ft_putchar(' ');
}

int			printf_flag_x(char *str, t_flist *elem)
{
	int num[3];

	num[2] = 0;
	num[0] = 0;
	printf_flag_x_1(&str, elem, num);
	if (elem->minus == 0)
	{
		printf_flag_x_2(&str, elem, num);
		printf_flag_x_3(&str, elem, num);
		return (num[1] + num[0] + num[2]);
	}
	else
	{
		printf_flag_x_4(&str, elem, num);
		while (num[0] < elem->accu_l - num[2])
		{
			ft_putchar(' ');
			num[0]++;
		}
		return (num[0] + num[2]);
	}
}
