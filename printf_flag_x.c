/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:39:25 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 17:00:03 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	printf_flag_x(char *str, t_flist *elem)
{
	int	s;
	int	i;
	int	hash;

	hash = 0;
	i = 0;
	if (elem->hash == 1 && *str != '0')
		hash = 2;
	str = ft_strdup(str);
	if (*str == '0' && elem->accu_r == 0 && elem->dot == 1)
		s = 0;
	else
	{
		if ((int)ft_strlen(str) > elem->accu_r)
			s = ft_strlen(str);
		else
			s = elem->accu_r;
	}
	if (elem->minus == 0)
	{
		if (elem->hash == 1 && *str != '0' && elem->zero == 1 && elem->dot == 0)
		{
			if (elem->spec == 'x')
				ft_putstr("0x");
			else if (elem->spec == 'X')
				ft_putstr("0X");
			elem->hash = 2;
		}
		while (i < elem->accu_l - s - hash)
		{
			if (elem->zero == 1 && elem->dot == 0)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
		if (*str == '0' && elem->accu_r == 0 && elem->dot == 1)
			s = 0;
		else
			s = ft_strlen(str);
		if (elem->hash == 1 && *str != '0')
		{
			if (elem->spec == 'x')
				ft_putstr("0x");
			else if (elem->spec == 'X')
				ft_putstr("0X");
		}
		while (elem->accu_r - s > 0)
		{
			ft_putchar('0');
			s++;
		}
		if (!(*str == '0' && elem->accu_r == 0 && elem->dot == 1))
			ft_putstr(str);
		free(str);
		return (s + i + hash);
	}
	else
	{
		if (elem->hash == 1 && *str != '0')
		{
			if (elem->spec == 'x')
				ft_putstr("0x");
			else if (elem->spec == 'X')
				ft_putstr("0X");
			hash = 2;
		}
		i = ft_strlen(str);
		while (elem->accu_r - i > 0)
		{
			ft_putchar('0');
			i++;
		}
		if (!(*str == '0' && elem->accu_r == 0 && elem->dot == 1))
			ft_putstr(str);
		else
			ft_putchar(' ');
		while (i < elem->accu_l - hash)
		{
			ft_putchar(' ');
			i++;
		}
		free(str);
		return (i + hash);
	}
}
