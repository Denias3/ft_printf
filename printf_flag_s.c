/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:54:48 by emeha             #+#    #+#             */
/*   Updated: 2019/01/16 16:54:51 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int printf_flag_s(char *str, t_flist *elem)
{
	char    *tmp;
	int     s;
	int     i;

	i = 0;
	if (str == NULL)
	    str = ft_strdup("(null)");
	if (elem->dot == 1)
		tmp = ft_strsub(str, 0, elem->accu_r);
	else
		tmp = ft_strdup(str);
	s = ft_strlen(tmp);
	if (elem->minus == 0)
	{
		while (i < elem->accu_l - s)
		{
			if (elem->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putstr(tmp);
		return (s + i);
	}
	else
	{
		ft_putstr(tmp);
		i = ft_strlen(tmp);
		while (i < elem->accu_l)
		{
			ft_putchar(' ');
			i++;
		}
		return (i);
	}
}