/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:56:08 by emeha             #+#    #+#             */
/*   Updated: 2019/03/25 18:08:41 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void			specifiers_1(char **format, short *ch, t_flist *elem)
{
	if (*ch == 0)
	{
		elem->accu_l = ft_atoi(*format);
		*format = *format + ft_numlen(elem->accu_l) - 1;
	}
	else
	{
		elem->accu_r = ft_atoi(*format);
		*format = *format + ft_numlen(elem->accu_r) - 1;
		*ch = 0;
	}
}

static void			specifiers_2(char **format, t_flist *elem)
{
	if (**format == '#')
		elem->hash = 1;
	if (**format == ' ')
		elem->space = 1;
	if (**format == '+')
		elem->plus = 1;
	if (**format == '-')
		elem->minus = 1;
}

static void			specifiers_3(char **format, t_flist *elem)
{
	if (**format == *(*(format) + 1))
	{
		elem->flag = ft_strsub(*format, 0, 2);
		(*format)++;
	}
	else
		elem->flag = ft_strsub(*format, 0, 1);
}

static void			specifiers_4(char **format, t_flist *elem)
{
	if (**format == 's' || **format == 'c' || **format == 'p' ||
	**format == 'd' || **format == 'i' || **format == 'x' ||
	**format == 'X' || **format == 'u' || **format == 'o' ||
	**format == 'f' || **format == '%')
	{
		elem->spec = **format;
		(*format)++;
	}
}

t_flist				*specifiers(char **format)
{
	short		ch;
	t_flist		*elem;

	ch = 0;
	elem = flist_new_pf();
	while (**format != '\0')
	{
		if (**format == '#' || **format == ' ' ||
			**format == '+' || **format == '-')
			specifiers_2(format, elem);
		else if ((**format) == '0')
			elem->zero = 1;
		else if (**format >= '1' && **format <= '9')
			specifiers_1(format, &ch, elem);
		else if (**format == '.')
			specifiers_5(format, &ch, elem);
		else if (**format == 'h' || **format == 'l' || **format == 'L')
			specifiers_3(format, elem);
		else
			break ;
		(*format)++;
	}
	specifiers_4(format, elem);
	return (elem);
}
