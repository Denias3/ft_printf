/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:48:55 by emeha             #+#    #+#             */
/*   Updated: 2019/03/25 17:01:19 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	printf_flag_p_1(char **str, t_flist *elem, int *i, int *s)
{
	while (*i < elem->accu_l - (*s) - 2)
	{
		if (elem->zero == 1 && elem->dot == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		(*i)++;
	}
	if (elem->zero == 0 || elem->dot == 1)
		ft_putstr("0x");
	if (ft_utoi(*str) == 0 && elem->dot == 1)
		(*s) = 0;
	while (elem->accu_r - *s > 0)
	{
		ft_putchar('0');
		(*s)++;
	}
	if (ft_utoi(*str) != 0 || elem->dot == 0)
		ft_putstr(*str);
}

static void	printf_flag_p_2(char **str, t_flist *elem, int *i, int *s)
{
	if (elem->zero == 0 || elem->dot == 1)
		ft_putstr("0x");
	if (ft_utoi(*str) == 0 && elem->dot == 1)
		(*s) = 0;
	while (elem->accu_r - (*s) > 0)
	{
		ft_putchar('0');
		(*s)++;
	}
	(*i) = (*s);
	if (ft_utoi(*str) != 0 || elem->dot == 0)
		ft_putstr(*str);
	while ((*i) < elem->accu_l - 2)
	{
		ft_putchar(' ');
		(*i)++;
	}
}

int			printf_flag_p(char *str, t_flist *elem)
{
	int	i;
	int	s;

	i = 0;
	if (elem->zero == 1 && elem->dot == 0)
		ft_putstr("0x");
	s = ft_strlen(str);
	if (elem->minus == 0)
	{
		printf_flag_p_1(&str, elem, &i, &s);
		return (s + i + 2);
	}
	else
	{
		printf_flag_p_2(&str, elem, &i, &s);
		return (i + 2);
	}
}
