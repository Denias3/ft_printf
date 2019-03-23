/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:58:40 by emeha             #+#    #+#             */
/*   Updated: 2019/03/19 22:33:24 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int printf_flag_c(int c, t_flist *elem)
{
	int     s;
	int     size;
	short   ch;

	ch = 1;
	size = 0;
	s = elem->accu_l;
	if (s == 0)
	{
		ft_putchar(c);
		size++;
	}
	while (s > 0)
	{
		if (elem->minus == 1)
		{
			if (ch)
			{
				ft_putchar(c);
				ch = 0;
			}
			else
				ft_putchar(' ');
		}
		else
		{
			if (s != 1)
			{
				if (elem->zero == 0)
					ft_putchar(' ');
				else
					ft_putchar('0');
			}
			else
				ft_putchar(c);
		}
		s--;
		size++;
	}
	return (size);
}

