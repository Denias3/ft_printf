/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:58:40 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 21:03:43 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	printf_flag_c_1(t_flist *elem, int c, short *ch, int s)
{
	if (elem->minus == 1)
	{
		if (*ch)
		{
			ft_putchar(c);
			*ch = 0;
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
}

int			printf_flag_c(int c, t_flist *elem)
{
	int		s;
	int		size;
	short	ch;

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
		printf_flag_c_1(elem, c, &ch, s);
		s--;
		size++;
	}
	return (size);
}
