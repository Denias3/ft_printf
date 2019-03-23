/* ************************************************************************** */
/*
	free(s2);                                                                     */
/*                                                        :::      ::::::::   */
/*   ft_print_flag_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:25:13 by emeha             #+#    #+#             */
/*   Updated: 2019/01/21 17:25:16 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int printf_flag_p(char *str, t_flist *elem)
{
	int     i;
	int     s;
	int     z;

	i = 0;
	z = 0;
	if (elem->zero == 1 && elem->dot == 0)
		ft_putstr("0x");
	s = ft_strlen(str);
	if (elem->minus == 0)
	{
		while (i < elem->accu_l - s - 2)
		{
			if (elem->zero == 1 && elem->dot == 0)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
		if (elem->zero == 0 || elem->dot == 1)
			ft_putstr("0x");
		if (ft_utoi(str) == 0 && elem->dot == 1)
			s = 0;
		while (elem->accu_r - s > 0)
		{
			ft_putchar('0');
			s++;
		}
		if (ft_utoi(str) != 0 || elem->dot == 0)
			ft_putstr(str);
		return (s + i + 2);
	}
	else
	{
		if (elem->zero == 0 || elem->dot == 1)
			ft_putstr("0x");
		if (ft_utoi(str) == 0 && elem->dot == 1)
			s = 0;
		while (elem->accu_r - s > 0)
		{
			ft_putchar('0');
			s++;
		}
		i = s;
		if (ft_utoi(str) != 0 || elem->dot == 0)
			ft_putstr(str);
		while (i < elem->accu_l - 2)
		{
			ft_putchar(' ');
			i++;
		}
		return (i + z + 2);
	}
}
