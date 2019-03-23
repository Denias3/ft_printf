/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:40:16 by emeha             #+#    #+#             */
/*   Updated: 2019/03/21 15:17:17 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"


int printf_flag_f(char *str, t_flist *elem)
{
	int     s;
	int     i;
	int		z;
	int		min;

	min = 0;
	z = 0;
	if (str[0] == '-')
		min = 1;
	else if (elem->plus == 1)
		z = 1;
	else if (elem->space == 1)
		z = 1;
	s = ft_strlen(str);
	if (elem->accu_r == 0 && elem->dot == 1)
		str = ft_strsub_free(str, min, s - 2 +  elem->hash - min);
	else
		str = ft_strsub_free(str, min, s - 1 - min);
	i = 0;
	s = ft_strlen(str);
	if (elem->minus == 0)
	{
		if (min == 1 && elem->zero == 1)
			ft_putchar('-');
		else if (elem->plus == 1 && elem->zero == 1)
			ft_putchar('+');
		else if (elem->space && elem->zero == 1)
			ft_putchar(' ');
		while (i < elem->accu_l - s - z - min)
		{
			if (elem->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
		if (min == 1 && elem->zero == 0)
			ft_putchar('-');
		if (elem->plus == 1 && elem->zero == 0)
			ft_putchar('+');
		else if (elem->space && elem->zero == 0)
			ft_putchar(' ');
		ft_putstr(str);
		free(str);
		return (s + i);
	}
	else
	{
		if (min == 1)
			ft_putchar('-');
		else if (elem->plus == 1)
			ft_putchar('+');
		else if (elem->space)
			ft_putchar(' ');
		ft_putstr(str);
		i = ft_strlen(str);
		while (i < elem->accu_l - z - min)
		{
			ft_putchar(' ');
			i++;
		}
		free(str);
		return (i);
	}

}