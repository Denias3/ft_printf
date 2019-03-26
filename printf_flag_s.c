/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:54:48 by emeha             #+#    #+#             */
/*   Updated: 2019/03/25 17:19:47 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	printf_flag_s_1(char **str, t_flist *elem, int *i, int *s)
{
	while ((*i) < elem->accu_l - (*s))
	{
		if (elem->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		(*i)++;
	}
	ft_putstr(*str);
}

static void	printf_flag_s_2(char **str, t_flist *elem, int *i)
{
	ft_putstr(*str);
	(*i) = ft_strlen(*str);
	while ((*i) < elem->accu_l)
	{
		ft_putchar(' ');
		(*i)++;
	}
}

static void	printf_flag_s_3(char **str, t_flist *elem, int *ch)
{
	if (*str == NULL)
	{
		*str = ft_strdup("(null)");
		(*ch) = 1;
	}
	if (elem->dot == 1)
	{
		*str = ft_strsub(*str, 0, elem->accu_r);
		(*ch) = 1;
	}
}

int			printf_flag_s(char *str, t_flist *elem)
{
	int		s;
	int		i;
	int		ch;

	i = 0;
	ch = 0;
	printf_flag_s_3(&str, elem, &ch);
	s = ft_strlen(str);
	if (elem->minus == 0)
	{
		printf_flag_s_1(&str, elem, &i, &s);
		if (ch)
			free(str);
		return (s + i);
	}
	else
	{
		printf_flag_s_2(&str, elem, &i);
		if (ch)
			free(str);
		return (i);
	}
}
