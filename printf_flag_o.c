/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:46:02 by emeha             #+#    #+#             */
/*   Updated: 2019/03/25 16:49:07 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	printf_flag_o_1(char **str, t_flist *elem, int *num)
{
	if (elem->hash == 1 && ft_utoi(*str) != 0)
		num[2] = 1;
	if (ft_utoi(*str) == 0 && elem->accu_r == 0 && elem->dot)
		num[1] = 0;
	else if ((int)ft_strlen(*str) >= elem->accu_r)
		num[1] = ft_strlen(*str);
	else
		num[1] = elem->accu_r - num[2];
}

static void	printf_flag_o_2(char **str, t_flist *elem, int *num)
{
	while (num[0] < elem->accu_l - num[1] - num[2] && (elem->dot == 1 ||
			(elem->accu_r == 0 && elem->zero == 0)))
	{
		ft_putchar(' ');
		num[0]++;
	}
	if (elem->hash == 1 && ft_utoi(*str) != 0)
		ft_putchar('0');
	while (num[0] < elem->accu_l - num[2] - num[1] && elem->dot == 0)
	{
		ft_putchar('0');
		num[0]++;
	}
	num[1] = ft_strlen(*str);
	while (elem->accu_r - num[1] - num[2] > 0)
	{
		ft_putchar('0');
		num[1]++;
	}
	if (ft_utoi(*str) != 0 || elem->hash == 1 ||
			(elem->hash == 0 && elem->dot == 0)
		|| elem->accu_r > 0)
		ft_putstr(*str);
	else
		num[1] = 0;
}

static void	printf_flag_o_3(char **str, t_flist *elem, int *num)
{
	if (elem->hash == 1 && ft_utoi(*str) != 0)
		ft_putchar('0');
	num[1] = ft_strlen(*str);
	while (elem->accu_r - num[1] - num[2] > 0)
	{
		ft_putchar('0');
		num[1]++;
	}
	if (ft_utoi(*str) != 0 || elem->hash == 1 ||
			(elem->hash == 0 && elem->dot == 0)
		|| elem->accu_r > 0)
		ft_putstr(*str);
	else
		num[1] = 0;
	while (num[0] < elem->accu_l - num[2] - num[1] && (elem->dot == 1 ||
			elem->accu_r == 0))
	{
		ft_putchar(' ');
		num[0]++;
	}
}

int			printf_flag_o(char *str, t_flist *elem)
{
	int num[3];

	num[0] = 0;
	num[2] = 0;
	printf_flag_o_1(&str, elem, num);
	if (elem->minus == 0)
	{
		printf_flag_o_2(&str, elem, num);
		return (num[1] + num[0] + num[2]);
	}
	else
	{
		printf_flag_o_3(&str, elem, num);
		return (num[1] + num[0] + num[2]);
	}
}
