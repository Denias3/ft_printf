/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:46:02 by emeha             #+#    #+#             */
/*   Updated: 2019/03/20 16:01:31 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int printf_flag_o(char *str, t_flist *elem)
{
	int z;
	int s;
	int i;

	i = 0;

	z = 0;
	if (elem->hash == 1 && ft_utoi(str) != 0)
		z = 1;
	if (ft_utoi(str) == 0 && elem->accu_r == 0 && elem->dot)
		s = 0;
	else if ((int)ft_strlen(str) >= elem->accu_r)
		s = ft_strlen(str);
	else
		s = elem->accu_r - z;
	if (elem->minus == 0)
	{
		while (i < elem->accu_l - s - z && (elem->dot == 1 || (elem->accu_r == 0 && elem->zero == 0)))
		{
			ft_putchar(' ');
			i++;
		}
		if (elem->hash == 1 && ft_utoi(str) != 0)
			ft_putchar('0');
		while (i < elem->accu_l - z - s && elem->dot == 0)
		{
			ft_putchar('0');
			i++;
		}
		s = ft_strlen(str);
		while (elem->accu_r - s - z > 0)
		{
			ft_putchar('0');
			s++;
		}
		if (ft_utoi(str) != 0 || elem->hash == 1 || (elem->hash == 0 && elem->dot == 0)
			|| elem->accu_r > 0)
			ft_putstr(str);
		else
			s = 0;
		return (s + i + z);
	}
	else
	{
		if (elem->hash == 1 && ft_utoi(str) != 0)
			ft_putchar('0');
		s = ft_strlen(str);
		while (elem->accu_r - s - z > 0)
		{
			ft_putchar('0');
			s++;
		}
		if (ft_utoi(str) != 0 || elem->hash == 1 || (elem->hash == 0 && elem->dot == 0)
			|| elem->accu_r > 0)
			ft_putstr(str);
		else
			s = 0;
		while (i < elem->accu_l - z - s && (elem->dot == 1 || elem->accu_r == 0))
		{
			ft_putchar(' ');
			i++;
		}
		return (s + i + z);
	}
}
