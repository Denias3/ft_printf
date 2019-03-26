/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:40:16 by emeha             #+#    #+#             */
/*   Updated: 2019/03/25 16:41:46 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	printf_flag_f_1(char **str, t_flist *elem, int *num)
{
	if ((*str)[0] == '-')
		num[3] = 1;
	else if (elem->plus == 1)
		num[2] = 1;
	else if (elem->space == 1)
		num[2] = 1;
	num[1] = ft_strlen((*str));
	if (elem->accu_r == 0 && elem->dot == 1)
		(*str) = ft_strsub_free((*str), num[3], num[1]
			- 2 + elem->hash - num[3]);
	else
		(*str) = ft_strsub_free((*str), num[3], num[1]
			- 1 - num[3]);
	num[0] = 0;
	num[1] = ft_strlen((*str));
}

static void	printf_flag_f_2(t_flist *elem, int *num)
{
	if (num[3] == 1 && elem->zero == 1)
		ft_putchar('-');
	else if (elem->plus == 1 && elem->zero == 1)
		ft_putchar('+');
	else if (elem->space && elem->zero == 1)
		ft_putchar(' ');
	while (num[0] < elem->accu_l - num[1] - num[2] - num[3])
	{
		if (elem->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		num[0]++;
	}
	if (num[3] == 1 && elem->zero == 0)
		ft_putchar('-');
	else if (elem->plus == 1 && elem->zero == 0)
		ft_putchar('+');
	else if (elem->space && elem->zero == 0)
		ft_putchar(' ');
}

static void	printf_flag_f_3(t_flist *elem, int *num)
{
	if (num[3] == 1)
		ft_putchar('-');
	else if (elem->plus == 1)
		ft_putchar('+');
	else if (elem->space)
		ft_putchar(' ');
}

int			printf_flag_f(char *str, t_flist *elem)
{
	int	num[4];

	num[3] = 0;
	num[2] = 0;
	printf_flag_f_1(&str, elem, num);
	if (elem->minus == 0)
	{
		printf_flag_f_2(elem, num);
		ft_putstr(str);
		free(str);
		return (num[1] + num[0] + num[3] + num[2]);
	}
	else
	{
		printf_flag_f_3(elem, num);
		ft_putstr(str);
		num[0] = ft_strlen(str);
		while (num[0] < elem->accu_l - num[2] - num[3])
		{
			ft_putchar(' ');
			num[0]++;
		}
		free(str);
		return (num[0] + num[3] + num[2]);
	}
}
