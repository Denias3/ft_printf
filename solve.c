/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:43:41 by emeha             #+#    #+#             */
/*   Updated: 2019/03/25 18:54:02 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

extern int g_s;

static void			solve_printf_2(t_flist *elem, va_list ap)
{
	char *tmp;

	tmp = ft_utoa_base(param_size_u(va_arg(ap, unsigned long long),
			elem), 16);
	tmp = ft_strlowcase(tmp);
	g_s += printf_flag_p(tmp, elem);
	free(tmp);
}

static void			solve_printf_3(t_flist *elem, va_list ap)
{
	char *tmp;

	tmp = ft_utoa_base(param_size_u(
			va_arg(ap, unsigned long long), elem), 8);
	g_s += printf_flag_o(tmp, elem);
	free(tmp);
}

static void			solve_printf_4(char **format)
{
	if (**format && **format != '%')
	{
		ft_putchar(**format);
		(*format)++;
		g_s++;
	}
}

static void			solve_printf_1(t_flist *elem, char **format, va_list ap)
{
	if (elem->spec == 'X')
		solve_dop_1(elem, ap);
	else if (elem->spec == 'x')
		solve_dop_2(elem, ap);
	else if (elem->spec == '%')
		g_s += printf_flag_c('%', elem);
	else if (elem->spec == 'f' && (ft_strcmp(elem->flag, "l") == 0 ||
			elem->flag == NULL || ft_strcmp(elem->flag, "ll") == 0))
		solve_dop_3(elem, ap);
	else if (elem->spec == 'f' && ft_strcmp(elem->flag, "L") == 0)
		solve_dop_4(elem, ap);
	else if (elem->spec == 'p')
		solve_printf_2(elem, ap);
	else if (elem->spec == 'o')
		solve_printf_3(elem, ap);
	else if (elem->spec == 'u')
		g_s += printf_flag_u(param_size_u(
				va_arg(ap, unsigned long long), elem), elem);
	else
		solve_dop_5(elem, format);
}

int					solve_printf(char *format, va_list ap)
{
	t_flist	*elem;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			elem = specifiers(&format);
			if (elem->spec == 'c')
				g_s += printf_flag_c(va_arg(ap, int), elem);
			else if (elem->spec == 's')
				g_s += printf_flag_s(va_arg(ap, char*), elem);
			else if (elem->spec == 'd' || elem->spec == 'i')
				g_s += printf_flag_d(param_size(
						va_arg(ap, long long int), elem->flag), elem);
			else if (elem->spec == 'f' || elem->spec == '%' ||
			elem->spec == 'o' || elem->spec == 'x' ||
			elem->spec == 'X' || elem->spec == 'u' ||
			elem->spec == 'p')
				solve_printf_1(elem, &format, ap);
			flist_free(elem);
		}
		solve_printf_4(&format);
	}
	return (0);
}
