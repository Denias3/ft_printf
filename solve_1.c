/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:28:18 by emeha             #+#    #+#             */
/*   Updated: 2019/03/25 18:37:44 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

extern int g_s;

void			solve_dop_1(t_flist *elem, va_list ap)
{
	char *tmp;

	tmp = ft_utoa_base(param_size_u(
			va_arg(ap, unsigned long long), elem), 16);
	g_s += printf_flag_x(tmp, elem);
	free(tmp);
}

void			solve_dop_2(t_flist *elem, va_list ap)
{
	char *tmp;

	tmp = ft_utoa_base(param_size_u(
			va_arg(ap, unsigned long long), elem), 16);
	g_s += printf_flag_x(ft_strlowcase(tmp), elem);
	free(tmp);
}

void			solve_dop_3(t_flist *elem, va_list ap)
{
	char *tmp;

	tmp = ft_read_double(va_arg(ap, double), elem);
	tmp = rounding(tmp);
	g_s += printf_flag_f(tmp, elem);
}

void			solve_dop_4(t_flist *elem, va_list ap)
{
	char *tmp;

	tmp = ft_read_l_double(va_arg(ap, long double), elem);
	tmp = rounding(tmp);
	g_s += printf_flag_f(tmp, elem);
}

void			solve_dop_5(t_flist *elem, char **format)
{
	char *tmp;

	tmp = ft_chardup(**format);
	g_s += printf_flag_s(tmp, elem);
	free(tmp);
	if (*format)
		format++;
}
